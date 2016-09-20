#include "tritset.h"
#include <limits>
#include <iostream>

using namespace std;
namespace tritspace {

std::size_t extend_to_capacity(std::size_t num) {
    return  ((num)/(4 * sizeof(uint)))*4*sizeof(uint) 
            + (((2 * num) % (8 * sizeof(uint)))
                    ? sizeof(uint)*4 : 0);
}


/////////////
// TritSet //
/////////////


TritSet::TritSet(std::size_t reserve) {
    if ((_capacity = extend_to_capacity(reserve))){
        data = new uint[(_capacity * 2) / (8 * sizeof(uint))];
        for (std::size_t i = 0; i < (_capacity * 2) / (8 * sizeof(uint)); ++i) {
            data[i] = static_cast<uint>(0x5555555555555555);
        }
    }
}

TritSet::TritSet(const TritSet& other) {
    _capacity = 0;
    *this = other;
}

std::size_t TritSet::capacity() const {
    return _capacity;
}

std::size_t* TritSet::cardinality() const{
    std::size_t *count = new std::size_t[3];
    count[Unknown] = cardinality(Unknown);
    count[True] = cardinality(True);
    count[False] = cardinality(False);
    return count;
}

std::size_t TritSet::cardinality(Trit state) const{
    std::size_t count = 0;
    for (std::size_t i = 0; i < _capacity; ++i)
    {
        if ((*this)[i] == state) {
            ++count;
        }
    }
    return count;
}

TritSet& TritSet::flip() {
    for (std::size_t i = 0; i < _capacity; ++i) {
        (*this)[i].flip();
    }
    return *this;
}

std::size_t TritSet::length() const{
    for(std::size_t i = _capacity - 1; i != static_cast<std::size_t>(-1); --i)
    {
        if ((*this)[i] != Unknown) {
            return i + 1;
        }
    }
    return 0;
}

TritSet& TritSet::operator=(const TritSet& other) {
    if (_capacity < other._capacity) {
        resize(other._capacity);
    }
    std::size_t size = _capacity / (4 * sizeof(uint));
    for (std::size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

TritSet::reference TritSet::operator[](std::size_t id) {
    return reference(*this, id);
}

const Trit TritSet::operator[](std::size_t id) const {
    if (id < _capacity) {
        return Trit((data[(id * 2) / (8 * sizeof(uint))] >> (id * 2) % (8 * sizeof(uint))) & 0x3);
    }
    else {
        return Unknown;
    }
}

TritSet TritSet::operator&(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set&=other;
}

TritSet TritSet::operator|(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set|=other;
}

TritSet TritSet::operator^(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set^=other;
}

TritSet TritSet::operator~() const{
    TritSet new_set(*this);
    return new_set.flip();
}

TritSet& TritSet::operator&=(const TritSet& other) {
    std::size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (std::size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] & other[i];
    }
    return *this;
}

TritSet& TritSet::operator|=(const TritSet& other) {
    std::size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (std::size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] | other[i];
    }
    return *this;
}

TritSet& TritSet::operator^=(const TritSet& other){
    std::size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (std::size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] ^ other[i];
    }
    return *this;
}

TritSet& TritSet::resize(std::size_t new_capacity) {
    new_capacity = extend_to_capacity(new_capacity);
    if (new_capacity && (new_capacity != _capacity)) {
        uint *buf = data;
        data = new uint[new_capacity];
        std::size_t min_size = ((_capacity < new_capacity) ?
                            _capacity : new_capacity)
                           * 2 / (8 * sizeof(uint)); // (in sizeof(uint))
        for (std::size_t i = 0; i < min_size; ++i) {
            data[i] = buf[i];
        }
        for (std::size_t i = _capacity / (4 * sizeof(uint));
                i < new_capacity / (4 * sizeof(uint)); ++i) {
            data[i] = static_cast<uint>(0x5555555555555555);
        }
        if(_capacity) {
            delete[] buf;
        }
        _capacity = new_capacity;
    }
    else if (!new_capacity){
        if (_capacity)
        {
            delete[] data;
        }
        _capacity = 0;
    }
    return *this;
}

TritSet& TritSet::shrink() {    
    return resize(length());
}

void TritSet::trim(std::size_t lastIndex) {
    size_t limit = extend_to_capacity(lastIndex);
    for(std::size_t i = lastIndex; i < limit; ++i) {
        (*this)[i] = Unknown;
    }
    limit /= 4 * sizeof(uint);
    for(std::size_t i = limit;
                i < _capacity / (4 * sizeof(uint)); ++i) {
        data[i] = static_cast<uint>(0x5555555555555555);
    }
}

TritSet::~TritSet() {
    delete[] data;
    data = 0;
}


////////////////////////
// TritSet::reference //
////////////////////////


TritSet::reference::reference() {};

TritSet::reference::reference(TritSet &set, std::size_t pos)
 : rset(&set), rpos(pos) { }

TritSet::reference::reference(const reference& other)
 : rset(other.rset), rpos(other.rpos) { }

TritSet::reference& TritSet::reference::operator= (const Tritenum other) {
    std::size_t shift    = (rpos    ) / (4 * sizeof(uint));
    std::size_t shiftbit = (rpos * 2) % (8 * sizeof(uint));
    if ((rpos >= rset->_capacity) && ((other == _True) || (other == _False))) {
        rset->resize(rpos + 1);
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)other%3 << shiftbit);
    }
    else if (rpos < rset->_capacity) {
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)other%3 << shiftbit);
    }
    return *this;
}

Tritenum TritSet::reference::state() const {
    if (rpos < rset->capacity()) {
        return Tritenum((rset->data[(rpos) / (4 * sizeof(uint))]
        >> (rpos * 2) % (8 * sizeof(uint))) & 0x3);
    }
    else {
        return _Unknown;
    }
}

TritSet::reference::~reference() {};

}

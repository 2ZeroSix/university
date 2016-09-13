#include "tritset.h"
#include <limits>
#include <iostream>

using namespace std;
namespace tritspace {

////////////////////////
// TritSet::reference //
////////////////////////

TritSet::reference::reference() {};

TritSet::reference::reference(TritSet &set, size_t pos)
 : rset(&set), rpos(pos) { }

TritSet::reference::reference(const reference& other)
 : rset(other.rset), rpos(other.rpos) { }

TritSet::reference::operator Trit() const {
    if (rpos < rset->_capacity){
        return Trit::Tritenum((rset->data[(rpos * 2) / (8 * sizeof(uint))]
            >> (rpos * 2) % (8 * sizeof(uint))) & 0x3);
    }
    else {
        return Unknown;
    }
}

TritSet::reference::operator Trit() {
    if (rpos < rset->_capacity){
        return Trit::Tritenum((rset->data[(rpos * 2) / (8 * sizeof(uint))]
            >> (rpos * 2) % (8 * sizeof(uint))) & 0x3);
    }
    else {
        return Unknown;
    }
}

TritSet::reference& TritSet::reference::operator= (const Trit other) {
    size_t shift    = (rpos * 2) / (8 * sizeof(uint));
    size_t shiftbit = (rpos * 2) % (8 * sizeof(uint));
    if ((rpos >= rset->_capacity) && ((other == True) || (other == False))) {
        rset->resize(rpos + 1);
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)other << shiftbit);
    }
    else if (rpos < rset->_capacity) {
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)other << shiftbit);
    }
    return *this;
}

TritSet::reference& TritSet::reference::operator= (const reference& other) {
    return *this = Trit(other);
}


TritSet::reference& TritSet::reference::flip() {
    return *this = ~Trit(*this);
}

TritSet::reference::~reference() {};


/////////////
// TritSet //
/////////////

TritSet::TritSet(const TritSet& other) {
    _capacity = 0;
    *this = other;
}

size_t TritSet::capacity() const {
    return _capacity;
}

const Trit TritSet::operator[](size_t id) const {
    if (id < _capacity) {
        return Trit((data[(id * 2) / (8 * sizeof(uint))] >> (id * 2) % (8 * sizeof(uint))) & 0x3);
    }
    else {
        return Unknown;
    }
}

TritSet::reference TritSet::operator[](size_t id) {
    return reference(*this, id);
}

TritSet& TritSet::operator=(const TritSet& other) {
    if (_capacity < other._capacity) {
        resize(other._capacity);
    }
    size_t size = _capacity / (8 * sizeof(uint)) + (_capacity % (8 * sizeof(uint)) ? 1 : 0);
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
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
    size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] & other[i];
    }
    return *this;
}

TritSet& TritSet::operator|=(const TritSet& other) {
    size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] | other[i];
    }
    return *this;
}

TritSet& TritSet::operator^=(const TritSet& other){
    size_t max_capacity = (_capacity > other._capacity) ?
                           _capacity : other._capacity;
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] = (*this)[i] ^ other[i];
    }
    return *this;
}

TritSet& TritSet::flip() {
    for (size_t i = 0; i < _capacity; ++i) {
        (*this)[i].flip();
    }
    return *this;
}

TritSet& TritSet::resize(size_t new_capacity) {
    new_capacity = extend_to_capacity(new_capacity);
    if (new_capacity && (new_capacity != _capacity)) {
        uint *buf = data;
        data = new uint[new_capacity];
        size_t min_size = ((_capacity < new_capacity) ?
                            _capacity : new_capacity)
                           * 2 / (8 * sizeof(uint)); // (in sizeof(uint))
        for (size_t i = 0; i < min_size; ++i) {
            data[i] = buf[i];
        }
        for (size_t i = _capacity / (4 * sizeof(uint)); i < new_capacity / (4 * sizeof(uint)); ++i) {
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

TritSet::~TritSet() {
    if(_capacity)
        delete[] data;
}
}

#include "tritset.h"

using namespace std;
namespace tritspace {

size_t extendToCapacity(size_t num) {
    return  ((num)/(4 * sizeof(uint)))*4*sizeof(uint) 
            + (((2 * num) % (8 * sizeof(uint)))
                    ? sizeof(uint)*4 : 0);
}

ostream & operator<<(ostream &os, const TritSet &set) {
    for (size_t i = 0; i < set.length(); ++i) {
        os << set[i].state();
    }
    return os;
}


/////////////
// TritSet //
/////////////


TritSet::TritenumReal TritSet::toReal(Tritenum state) {
    return (state == _False) ?
           _FalseReal : ((state == _Unknown) ?
                         _UnknownReal : _TrueReal);
}

Tritenum TritSet::fromReal(TritSet::TritenumReal state) {
    return (state == _FalseReal) ?
           _False : ((state == _UnknownReal) ?
                     _Unknown : _True);
}

TritSet::TritSet(size_t reserve)
:_capacity(0), data(nullptr) {
    resize(reserve);
}

TritSet::TritSet(const Trit arrt[], size_t count)
:_capacity(0), data(nullptr) {
    resize(count);
    for (size_t i = 0; i < count; ++i) {
        (*this)[i] = arrt[i];
    }
}

TritSet::TritSet(const initializer_list<Trit> list)
:_capacity(0), data(nullptr) {
    resize(list.size());
    std::initializer_list<Trit>::iterator cur = list.begin();
    for (size_t i = 0; i < list.size(); ++i) {
        (*this)[i] = *(cur++);
    }
}

TritSet::TritSet(const TritSet& other)
:_capacity(0), data(nullptr) {
    resize(other.capacity());
    size_t size = capacity() / (4 * sizeof(uint));
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

size_t TritSet::capacity() const {
    return _capacity;
}

vector<size_t> TritSet::cardinality() const{
    vector<size_t> count(3);
    size_t cur_len = length();
    for (size_t i = 0; i < cur_len; ++i)
    {
        ++count[(*this)[i].state()];
    }
    return count;
}

size_t TritSet::cardinality(Tritenum state) const{
    size_t count = 0;
    size_t cur_len = length();
    for (size_t i = 0; i < cur_len; ++i) {
        if ((*this)[i].state() == state) {
            ++count;
        }
    }
    return count;
}

TritSet& TritSet::flip() {
    for (size_t i = 0; i < capacity(); ++i) {
        (*this)[i].flip();
    }
    return *this;
}

size_t TritSet::length() const{
    for(size_t i = capacity() - 1; i != static_cast<size_t>(0)-1; --i) {
        if ((*this)[i].state() != _Unknown) {
            return i + 1;
        }
    }
    return 0;
}

bool TritSet::operator== (const TritSet& other) const{
    size_t maxCapacity = (capacity() > other.capacity())
                     ? capacity() : other.capacity();
    for(size_t i = 0; i < maxCapacity; ++i) {
        if((*this)[i] != other[i]) {
            return false;
        }
    }
    return true;
}

bool TritSet::operator!= (const TritSet& other) const {
    return !(*this == other);
}

TritSet::reference TritSet::operator[](size_t id) {
    return reference(*this, id);
}

const Trit TritSet::operator[](size_t id) const {
    if (id < capacity()) {
        Tritenum a = fromReal(TritenumReal((data[(id * 2) / (8 * sizeof(uint))]
                >> (id * 2) % (8 * sizeof(uint))) & 0x3));
        return Trit(a);
    }
    else {
        return Unknown;
    }
}

TritSet TritSet::operator&(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set &= other;
}

TritSet TritSet::operator|(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set |= other;
}

TritSet TritSet::operator^(const TritSet& other) const{
    TritSet new_set(*this);
    return new_set ^= other;
}

TritSet TritSet::operator~() const{
    TritSet new_set(*this);
    return new_set.flip();
}

TritSet& TritSet::operator&=(const TritSet& other) {
    size_t max_capacity = (capacity() > other.capacity()) ?
                           capacity() : other.capacity();
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] &= other[i];
    }
    return *this;
}

TritSet& TritSet::operator|=(const TritSet& other) {
    size_t max_capacity = (capacity() > other.capacity()) ?
                           capacity() : other.capacity();
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] |= other[i];
    }
    return *this;
}

TritSet& TritSet::operator^=(const TritSet& other){
    size_t max_capacity = (capacity() > other.capacity()) ?
                           capacity() : other.capacity();
    for (size_t i = 0; i < max_capacity; ++i) {
        (*this)[i] ^= other[i];
    }
    return *this;
}

TritSet& TritSet::resize(size_t new_capacity) {
    new_capacity = extendToCapacity(new_capacity);
    if (new_capacity && (new_capacity != capacity())) {
        uint *buf = data;
        data = new uint[new_capacity]();
        size_t min_size = ((capacity() < new_capacity) ?
                            capacity() : new_capacity)
                           * 2 / (8 * sizeof(uint)); // (in sizeof(uint))
        for (size_t i = 0; i < min_size; ++i) {
            data[i] = buf[i];
        }
        if(buf != nullptr) {
            delete[] buf;
        }
        _capacity = new_capacity;
    }
    else if (!new_capacity){
        if (data != nullptr)
        {
            uint *buf = data;
            data = nullptr;
            delete[] buf;
        }
        _capacity = 0;
    }
    return *this;
}

TritSet& TritSet::shrink() {
    return resize(length());
}

void TritSet::trim(size_t lastIndex) {
    size_t limit = extendToCapacity(lastIndex);
    for(size_t i = lastIndex; i < limit; ++i) {
        (*this)[i] = _Unknown;
    }
    limit /= 4 * sizeof(uint);
    for(size_t i = limit;
                i < capacity() / (4 * sizeof(uint)); ++i) {
        data[i] = 0;
    }
}

TritSet::~TritSet() {
    _capacity = 0;
    uint* buf = data;
    data = nullptr;
    delete[] buf;
}

////////////////////////
// TritSet::reference //
////////////////////////


TritSet::reference::reference() {};

TritSet::reference::reference(TritSet &set, size_t pos)
 : rset(&set), rpos(pos) { }

TritSet::reference::reference(const reference& other)
 : rset(other.rset), rpos(other.rpos) { }

TritSet::reference& TritSet::reference::operator= (Tritenum other) {
    size_t shift    = (rpos    ) / (4 * sizeof(uint));
    size_t shiftbit = (rpos * 2) % (8 * sizeof(uint));
    TritenumReal state = toReal(other);
    if ((rpos >= rset->capacity()) && ((state == _TrueReal) || (state == _FalseReal))) {
        rset->resize(rpos + 1);
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)state%3 << shiftbit);
    }
    else if (rpos < rset->capacity()) {
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)state%3 << shiftbit);
    }
    return *this;
}

Tritenum TritSet::reference::state() const {
    if (rpos < rset->capacity()) {
        return fromReal(TritenumReal((rset->data[(rpos) / (4 * sizeof(uint))]
                >> (rpos * 2) % (8 * sizeof(uint))) & 0x3));
    }
    return _Unknown;
}

TritSet::reference::~reference() {
    rset = nullptr;
    rpos = 0;
}

}

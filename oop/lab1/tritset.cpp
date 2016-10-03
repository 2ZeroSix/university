#include "tritset.h"

using namespace std;
namespace tritspace {

std::size_t extendToCapacity(std::size_t num) {
    return  ((num)/(4 * sizeof(uint)))*4*sizeof(uint) 
            + (((2 * num) % (8 * sizeof(uint)))
                    ? sizeof(uint)*4 : 0);
}

ostream & operator<<(ostream &os, const TritSet &set) {
    for (size_t i = 0; i < set.length(); ++i) {
        os << static_cast<unsigned int>(set[i].state());
    }
    return os;
}


/////////////
// TritSet //
/////////////


TritSet::TritenumReal TritSet::toReal(Tritenum state) {
    switch(state) {
        case Tritenum::True:
            return TritenumReal::True;
        case Tritenum::Unknown:
            return TritenumReal::Unknown;
        case Tritenum::False:
            return TritenumReal::False;
        default:
            throw WrongTrit(state);
    }
}

Tritenum TritSet::fromReal(TritSet::TritenumReal state) {
    switch(state) {
        case TritenumReal::True:
            return Tritenum::True;
        case TritenumReal::Unknown:
            return Tritenum::Unknown;
        case TritenumReal::False:
            return Tritenum::False;
        default:
            throw WrongTrit(static_cast<Tritenum>(state));
    }
}

TritSet::TritSet(size_t reserve)
:_capacity(0), data(nullptr) {
    resize(reserve);
}

TritSet::TritSet(const Trit arrt[], size_t count)
:_capacity(0), data(nullptr) {
    resize(count);
    iterator curset = begin();
    for (size_t i = 0; i < count; ++i, ++arrt, ++curset) {
        *curset = *arrt;
    }
}

TritSet::TritSet(const initializer_list<Trit> list)
:_capacity(0), data(nullptr) {
    resize(list.size());
    iterator curset = begin();
    for (initializer_list<Trit>::iterator curlist = list.begin();
            curlist != list.end(); ++curlist, ++curset) {
        *curset = *curlist;
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

TritSet::TritSet(TritSet&& other)
:_capacity(other._capacity), data(std::move(other.data)){
    other._capacity = 0;
    other.data      = nullptr;
}

size_t TritSet::capacity() const {
    return _capacity;
}

vector<size_t> TritSet::cardinality() const{
    vector<size_t> count(3);
    for (const_iterator curset = begin();
            curset != end();
            ++curset) {
        ++count[static_cast<unsigned char>(curset->state())];
    }
    return count;
}

size_t TritSet::cardinality(Tritenum state) const{
    size_t count = 0;
    for (const_iterator curset = begin();
            curset != end();
            ++curset) {
        if (curset->state() == state) {
            ++count;
        }
    }
    return count;
}

TritSet& TritSet::flip() {
    for (iterator it = begin(); it != end(); ++it) {
        it->flip();
    }
    return *this;
}

size_t TritSet::length() const{
    size_t res = capacity();
    for (const_iterator curset = end() - 1;
            curset >= begin();
            --curset) {
        if (curset->state() != Tritenum::Unknown) {
            return res;
        }
        --res;
    }
    return res;
}

bool TritSet::operator== (const TritSet& other) const{
    const_iterator itth = begin();
    const_iterator itoth = other.begin();
    for(; itth < end() || itoth < other.end(); ++itth, ++itoth) {
        if(*itth != *itoth) {
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
    iterator itth = begin();
    const_iterator itoth = other.begin();
    for(; itth < end() || itoth < other.end(); ++itth, ++itoth) {
        *itth &= *itoth;
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
        (*this)[i] = Tritenum::Unknown;
    }
    limit /= 4 * sizeof(uint);
    for(size_t i = limit;
                i < capacity() / (4 * sizeof(uint)); ++i) {
        data[i] = 0;
    }
}

TritSet::~TritSet() {
    // avoid optimizations which can cause double free
    volatile size_t& bufcap = _capacity;
    uint* volatile & bufdata = data;
    delete[] bufdata;
    bufdata = nullptr;
    bufcap = 0;
}

////////////////////////
// TritSet::reference //
////////////////////////


TritSet::reference::reference()
 : rset(nullptr), rpos(0){};

TritSet::reference::reference(TritSet &set, size_t pos)
 : rset(&set), rpos(pos) { }

TritSet::reference::reference(const reference& other)
 : rset(other.rset), rpos(other.rpos) { }

TritSet::reference& TritSet::reference::operator= (Tritenum other) {
    if (!rset) {
        return *this;
    }
    // shift of byte*sizeof(uint)
    size_t shift    = (rpos    ) / (4 * sizeof(uint));
    // shift of bits
    size_t shiftbit = (rpos * 2) % (8 * sizeof(uint));
    TritenumReal state = toReal(other);
    // if trit is significant and its position is bigger than capacity of set
    if ((rpos >= rset->capacity()) && ((state == TritenumReal::True) || (state == TritenumReal::False))) {
        rset->resize(rpos + 1);
        // apply mask with zeros on position
        // and then apply binary or on it and new state
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)state%3 << shiftbit);
    }
    else if (rpos < rset->capacity()) {
        // apply mask with zeros on position
        // and then apply binary or on it and new state
        rset->data[shift] = (rset->data[shift] & ~((uint)0x3 << shiftbit)) |
                            ((uint)state%3 << shiftbit);
    }
    return *this;
}

Tritenum TritSet::reference::state() const {
    if (!rset) {
        return Unknown;
    }
    if (rpos < rset->capacity()) {
        // inside the brackets shifting of bite*sizeof(uint),
        // outside the brackets shifting of bits
        // and then apply mask 0b11
        return fromReal(TritenumReal((rset->data[(rpos) / (4 * sizeof(uint))]
                >> (rpos * 2) % (8 * sizeof(uint))) & 0x3));
    }
    return Tritenum::Unknown;
}

TritSet::reference::~reference() {
    // avoid optimizations which can delete assigning
    TritSet*volatile&bufset = rset;
    volatile size_t &bufpos = rpos;
    bufset = nullptr;
    bufpos = 0;
}

}

#ifndef _TRIT_BASE_H_
#define _TRIT_BASE_H_

enum Tritenum : unsigned char {_False, _Unknown, _True};
template<typename T, typename U=T>
class TritBase {
public:
    TritBase() { }
    // TritBase(Tritenum state) {*this = state;}
    U operator&(Tritenum other) const{
        return (state() < other) ? state() : other;
    }
    U operator|(Tritenum other) const{
        return (state() > other) ? state() : other;
    }
    U operator^(Tritenum other) const{
        return Tritenum(state() + other % 3);
    }
    U operator~() const{
        switch (state()) {
            case _False:
                return _True;
            case _Unknown:
                return _Unknown;
            case _True:
                return _False;
        }
    }
    T operator&=(Tritenum other){
        return *this = (*this & other).state();
    }
    T operator|=(Tritenum other){
        return *this = (*this | other).state();
    }
    T operator^=(Tritenum other){
        return *this = (*this ^ other).state();
    }
    T flip()                    {
        return *this = (~(*this)).state();
    }
    const char* to_string() const{
        switch (state()) {
            case _False:
                return "False";
            case _Unknown:
                return "Unknown";
            case _True:
                return "True";
        }    
    }
    operator              Tritenum  () const {return state();}
    virtual     Tritenum  state     () const                = 0;
    // virtual     T& operator= (const U& other)               = 0;
    virtual     T& operator= (Tritenum state)               = 0;
    virtual ~TritBase() { }
};

#endif

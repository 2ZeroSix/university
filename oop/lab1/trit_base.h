#ifndef _TRIT_BASE_H_
#define _TRIT_BASE_H_

enum Tritenum : unsigned char {_Unknown, _False, _True};
template<typename T, typename U=T>
class TritBase {
protected:
            TritBase  () { }
    virtual ~TritBase () { }
public:
    template<typename A, typename B>
    U operator&(const TritBase<A, B>& other) const{
        return U((state() < other.state())
                       ? state() : other.state());
    }
    template<typename A, typename B>
    U operator|(const TritBase<A, B>& other) const{
        return U((state() > other.state())
                       ? state() : other.state());
    }
    template<typename A, typename B>
    U operator^(const TritBase<A, B>& other) const{
        return U((state() + other.state())%3);
    }
    U operator~() const{
        switch (state()) {
            case _False:
                return U(_True);
            case _Unknown:
                return U(_Unknown);
            case _True:
                return U(_False);
        }
    }
    template<typename A, typename B>
    T operator&=(const TritBase<A, B>& other){
        return *this = (*this & other).state();
    }
    template<typename A, typename B>
    T operator|=(const TritBase<A, B>& other){
        return *this = (*this | other).state();
    }
    template<typename A, typename B>
    T operator^=(const TritBase<A, B>& other){
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
    explicit operator   Tritenum  () const {return state();}
    virtual Tritenum    state     () const               = 0;
    virtual T&          operator= (const Tritenum state) = 0;
};

#endif

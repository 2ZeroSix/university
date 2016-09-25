#ifndef _TRIT_BASE_H_
#define _TRIT_BASE_H_
#include <exception>

enum Tritenum : signed char {_False=-1, _Unknown, _True, _False2};

class WrongTrit: public std::exception {
public:
    WrongTrit(Tritenum state):_state(state){ }
    virtual const char* what() const throw() {
        return "Undefined trit state: ";
    }
private:
    Tritenum _state;
};

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
        return U((state() + other.state() + 2) % 3 - 1);
    }
    U operator~() const{
        switch (state()) {
            case _False:
                return U(_True);
            case _Unknown:
                return U(_Unknown);
            case _True:
                return U(_False);
            default:
                throw WrongTrit(state());
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
            default:
                throw WrongTrit(state());
        }    
    }
    explicit operator   Tritenum  () const {return state();}
    virtual Tritenum    state     () const               = 0;
    virtual T&          operator= (const Tritenum state) = 0;
    template<typename A, typename B>
    T&                  operator= (const TritBase<A, B>& other) {
        return *this = other.state();
    }
    template<typename A, typename B>
    bool                operator==(const TritBase<A, B>& other) const{
        return state() == other.state();
    }
    template<typename A, typename B>
    bool                operator!=(const TritBase<A, B>& other) const{
        return state() != other.state();
    }
};

#endif

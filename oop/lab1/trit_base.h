///////////////////////////////////////////////
// don't include directly in files           //
// which doesn't contain declaration of Trit //
// and #define _TRIT_H_                      //
///////////////////////////////////////////////
#ifndef _TRIT_H_
#error "trit_base.h can only be included from files\nwhich contain declaration of Trit\nand #define _TRIT_H_"
#endif

#ifndef _TRIT_BASE_H_
#define _TRIT_BASE_H_
#include <exception>
#include <string>
#include <ostream>


namespace tritspace {
// standard implementation of trits
class Trit;
// standard states, that must be returned by TritBase<T, U> object.state()
enum Tritenum : unsigned char {_False, _Unknown, _True};
// throws if state() return not equal to standard states
class WrongTrit: public std::exception {
public:
    WrongTrit(Tritenum state):_state(state){ }
    virtual const char* what() const noexcept{
        return ("Undefined trit state: " + std::to_string(_state)).c_str();
    }
private:
    Tritenum _state;
};

/**
 * Base class for trits realizations
 *
 * @template T  name of realization
 * 
 * @template U  name of associated realization
 */
template<typename T, typename U=Trit>
class TritBase {
protected:
    /**
     * default constructor of TritBase<T, U>
     */
    TritBase  () { }
    /**
     * destructor of TritBase<T, U>
     */
    virtual ~TritBase () { }
public:
    /**
     * three-value logic AND
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  new trit with realization class U
     */
    template<typename A, typename B>
    U operator&(const TritBase<A, B>& other) const{
        return U((state() < other.state())
                       ? state() : other.state());
    }
    /**
     * three-value logic OR
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  new trit with realization class U
     */
    template<typename A, typename B>
    U operator|(const TritBase<A, B>& other) const{
        return U((state() > other.state())
                       ? state() : other.state());
    }
    /**
     * three-value logic XOR
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  new trit with realization class U
     */
    template<typename A, typename B>
    U operator^(const TritBase<A, B>& other) const{
        return U((state() + other.state()) % 3);
    }
    /**
     * three-value logic NOT
     *
     * @return  new trit with realization class U
     */
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
    /**
     * assign three-value logic AND
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  same trit with realization class T
     */
    template<typename A, typename B>
    T operator&=(const TritBase<A, B>& other){
        return *this = (*this & other).state();
    }
    /**
     * assign three-value logic OR
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  same trit with realization class T
     */
    template<typename A, typename B>
    T operator|=(const TritBase<A, B>& other){
        return *this = (*this | other).state();
    }
    /**
     * assign three-value logic XOR
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * @return  same trit with realization class T
     */
    template<typename A, typename B>
    T operator^=(const TritBase<A, B>& other){
        return *this = (*this ^ other).state();
    }
    /**
     * assign three-value logic NOT
     *
     * @return  same trit with realization class U
     */
    T flip()                    {
        return *this = (~(*this)).state();
    }
    /**
     * create string with 
     *
     * @return             create string which explain itself content
     */
    const std::string to_string() const{
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
    /**
     * Overload of Tritenum operator
     */
    explicit operator   Tritenum  () const {return state();}
    /**
     * @return  current state of trit
     */
    virtual Tritenum    state     () const               = 0;
    /**
     * Assign operator from Tritenum
     *
     * @param   state   what to assign
     *
     * @return          same trit with realization U,
     *                       which state was changed
     */
    virtual T&          operator= (const Tritenum state) = 0;
    /**
     * Assign operator from TritBase<A, B>
     *
     * @param   other   trit realization based on TritBase<A, B>
     * 
     * @return          same trit with realization U,
     *                       which state was changed
     */
    template<typename A, typename B>
    T&                  operator= (const TritBase<A, B>& other) {
        return *this = other.state();
    }
    template<typename A, typename B>
    /**
     * Equation operator
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * return           if equal: true
     *                      else: false
     */
    bool                operator==(const TritBase<A, B>& other) const{
        return state() == other.state();
    }
    /**
     * Not equation operator
     *
     * @param   other   trit realization based on TritBase<A, B>
     *
     * return           if equal: false
     *                      else: true
     */
    template<typename A, typename B>
    bool                operator!=(const TritBase<A, B>& other) const{
        return state() != other.state();
    }
};

/**
 * overload of stream out operator
 *
 * @param   os  output stream
 *
 * @param   set trit with realization based on TritBase<A, B> 
 *              to print in stream
 *
 * @return      reference to used std::ostream
 */
template<typename A, typename B>
std::ostream& operator<<(std::ostream &os, const TritBase<A, B> &trit) {
    os << trit.to_string();
    return os;
}
}
#endif

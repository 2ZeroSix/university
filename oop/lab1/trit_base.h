///////////////////////////////////////////////
// don't include directly in files           //
// which doesn't contain declaration of Trit //
// and #define _TRIT_H_                      //
///////////////////////////////////////////////
#ifndef _TRIT_H_
#error "trit_base.h can only be included on the top of trit.h"
#endif

#ifndef _TRIT_BASE_H_
#define _TRIT_BASE_H_
#include <exception>
#include <string>
#include <ostream>

using namespace std;

namespace tritspace {
// standard implementation of trits
class Trit;
// standard states, that must be returned by TritBase<T, U> object.state()
enum class Tritenum : unsigned char {False, Unknown, True};

// throws if state() return not equal to standard states
class WrongTrit: public std::exception {
public:
    WrongTrit(const Tritenum& state){
        str[21] =   ' ';
        str[22] =   (static_cast<unsigned char>(state)/100) ?
                    (static_cast<unsigned char>(state)/100)      + '0' : ' ';
        str[23] =   (static_cast<unsigned char>(state)%100)/10 ?
                    (static_cast<unsigned char>(state)%100)/10 + '0' : ' ';
        str[24] =   (static_cast<unsigned char>(state)%10)       + '0';
        str[25] =   '\0';
    }
    virtual const char* what() const noexcept{
        return str;
    }
private:
    char str[26] = "Undefined trit state:";
};

/**
 * WARNING: 
 *     Overload resolution PROBLEM:
 *     in inherited classes you MUST paste this string after
 *     override of operator=(Tritenum) :
 *     !!!"using TritBase<inherited class name>::operator=;"!!!
 *     otherwise, operator=(Tritenum) will hides 
 *     all other overloads of operator=
 *     
 * 
 * Base class for trits realizations
 *
 * @template T  name of realization
 * 
 * @template U  name of main realization
 *
 * note:
 *     all trit realizations can be casted to main realization
 */
template<typename T, typename U=Trit>
class TritBase {
public:
    /**
     * three-value logic AND
     *
     * @param   other   trit with main realization
     *
     * @return  new trit with main realization
     */
    U operator&(const U& other) const{
        return (state() < other.state())
               ? state() : other.state();
    }
    /**
     * three-value logic OR
     *
     * @param   other   trit with main realization
     *
     * @return  new trit with main realization
     */
    U operator|(const U& other) const{
        return (state() > other.state())
                ? state() : other.state();
    }
    /**
     * three-value logic XOR
     *
     * @param   other   trit with main realization
     *
     * @return  new trit with main realization
     */
    U operator^(const U& other) const{
        return state() + other.state();
    }
    /**
     * three-value logic NOT
     *
     * @return  new trit with main realization
     */
    U operator~() const{
        switch (state()) {
            case Tritenum::False:
                return Tritenum::True;
            case Tritenum::Unknown:
                return Tritenum::Unknown;
            case Tritenum::True:
                return Tritenum::False;
            default:
                throw WrongTrit(state());
        }
    }
    /**
     * assign three-value logic AND
     *
     * @param   other   trit with main realization 
     *
     * @return  same trit with realization class T
     */
    T operator&=(const U& other){
        return *this = (*this & other).state();
    }
    /**
     * assign three-value logic OR
     *
     * @param   other   trit with main realization
     *
     * @return  same trit with realization class T
     */
    T operator|=(const U& other){
        return *this = (*this | other).state();
    }
    /**
     * assign three-value logic XOR
     *
     * @param   other   trit with main realization
     *
     * @return  same trit with realization class T
     */
    T operator^=(const U& other){
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
     * create string with name of trit
     *
     * @return             create string name of trit
     */
    const std::string to_string() const{
        switch (state()) {
            case Tritenum::False:
                return "False";
            case Tritenum::Unknown:
                return "Unknown";
            case Tritenum::True:
                return "True";
            default:
                throw WrongTrit(state());
        }
    }
    /**
     * cast to Tritenum operator
     */
    operator   Tritenum  () const {
        return state();
    }
    /**
     * cast to integer type
     */
    template<typename Integer, typename = typename std::enable_if<std::is_integral<Integer>::value,Integer>::type>
    explicit operator Integer() const {
        return static_cast<Integer>(state());
    }
    /**
     * cast to main realization
     */
    operator U() const {
        return state();
    }
    /**
     * current state of trit
     */
    virtual Tritenum    state     () const               = 0;
    /**
     * Assign operator from Tritenum
     *
     * @param   state   Tritenum to assign
     *
     * @return          same trit with realization U,
     *                       which state was changed
     *
     * note:
     *     mustn't checks if it's one of significant Tritenum values
     */
    virtual T&          operator= (const Tritenum state) = 0;
    /**
     * Assign operator from integer type
     *
     * @param   state   number to assign
     *
     * @return          same trit with realization U,
     *                       which state was assigned
     *                       to state mod 3
     */
    T&          operator= (const size_t& state) {
        return *this = static_cast<Tritenum>(state % 3);
    }
    /**
     * Assign operator from main realization
     *
     * @param   other   trit with main realization
     * 
     * @return          same trit with realization U,
     *                       which state was changed
     */
    T&                  operator= (const U& other) {
        return *this = other.state();
    }
    /**
     * Equation operator
     *
     * @param   other   trit with main realization
     *
     * return           if equal: true
     *                      else: false
     */
    bool                operator==(const U& other) const{
        return state() == other.state();
    }
    /**
     * Not equation operator
     *
     * @param   other   trit with main realization
     *
     * return           if equal: false
     *                      else: true
     */
    bool                operator!=(const U& other) const{
        return state() != other.state();
    }
};

}
#endif

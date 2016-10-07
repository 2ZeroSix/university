///////////////////////////////////////////////
// don't include directly in files           //
// which doesn't contain declaration of Trit //
// and #define _TRIT_H_                      //
///////////////////////////////////////////////
#ifndef _TRIT_H_
#error "trit_base.h can only be included on the top of trit.h,\n don't include it directly in any other way"
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
enum class Tritenum : unsigned char {False, Unknown, True};

// throws if state() return not equal to standard states
// 
// if you want to use explanation of exception after destruction
// you must copy returned from method what() string
class WrongTrit: public std::exception {
public:
    WrongTrit(const Tritenum& state) noexcept{
        unsigned char n = (static_cast<unsigned char>(state)/100);
        str[21] = ' ';
        str[22] = n ? n + '0' : ' ';
        n = (static_cast<unsigned char>(state)%100)/10;
        str[23] = n ? n + '0' : ' ';
        n = (static_cast<unsigned char>(state)%10);
        str[24] = n + '0';
        str[25] = '\0';
    }
    virtual const char* what() const noexcept{
        return str;
    }
private:
    char str[26] = "Undefined trit state:";
};

/**
 * Base class for trits realizations
 *
 * @template T  name of realization
 * 
 * @template U  name of main realization (default: Trit)
 *               Do not change it if you don't want to lose compatibility!
 *               Anyway it must have Tritenum constructor and copy constructor.
 *
 * note:
 *     all trit realizations can be casted to main realization
 * 
 * instruction:
 *     all you need is:
 *         create constructors and destructor
 *         overload pure virtual functions:
 *             Tritenum get ()
 *             T&       set (Tritenum)
 *         add string:
 *             "using TritBase<inherited class name>::operator=;"
 *
 * WARNING: 
 *     Overload resolution PROBLEM:
 *     in inherited classes you MUST add this string:
 *     !!!"using TritBase<inherited class name>::operator=;"!!!
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
     *
     * note:
     *     must be template because of "explicit" specificator
     */
    template<typename Integer, typename = typename std::enable_if<std::is_integral<Integer>::value,bool>::type>
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
    Tritenum    state     () const {
        return get();
    }
    /**
     * Assign operator from Tritenum
     *
     * @param   state   Tritenum to assign
     *
     * @return          same trit with realization U,
     *                       which state was changed
     */
    T&          operator= (Tritenum state){
        return set(state);
    }
    /**
     * Assign operator from integer type
     *
     * @param   state   number to assign
     *
     * @return          same trit with realization U,
     *                       which state was assigned
     *                       to state mod 3
     */
    T&          operator= (size_t state) {
        return set(static_cast<Tritenum>(state%3));
    }
    /**
     * Assign operator from trit with realization T
     *
     * @param   other   trit with realization T
     * 
     * @return          same trit with realization T,
     *                       which state was changed
     */
    T&          operator= (const TritBase<T>& other) {
        return set(other.state());
    }
protected:
    /**
     * get trit state
     *
     * @return  state of the trit
     */
    virtual Tritenum get() const = 0;
    /**
     * set trit state
     *
     * @param   Tritenum  state to set
     *
     * @return            same trit which state was changed
     *
     * note:
     *     mustn't check if it's one of significant Tritenum values
     */
    virtual T& set(Tritenum)     = 0;
};

}
#endif

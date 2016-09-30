#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
#include "trit_base.h"
#include <vector>
#include <ostream>
#include <initializer_list>
#include <iterator>

namespace tritspace{
typedef unsigned int uint;
/**
 * increases number to the nearest multiple of sizeof(uint)*4
 *
 * @param   num  positive integer
 *
 * @return       increased number
 */
std::size_t extendToCapacity(std::size_t num);

/**
 * dynamic container for trit logic elements
 */
class TritSet {
private:
    class reference;
    friend reference;
    // convenient internal representation of Tritenum
    enum TritenumReal : unsigned char {_UnknownReal=0, _TrueReal, _FalseReal};
    static TritenumReal toReal(Tritenum state);
    static Tritenum fromReal(TritenumReal state);
public:
    /**
     * default constructor of TritSet
     */
    explicit TritSet():_capacity(0), data(nullptr) { }

    /**
     * reserve constructor of TritSet
     */
    explicit TritSet(std::size_t reserve);

    /**
     * Trit array constructor of TritSet
     */
    explicit TritSet(const Trit arrt[], std::size_t count);

    /**
     * initializer list constructor of TritSet
     */
    TritSet(const std::initializer_list<Trit> list);

    /**
     * copy constructor of TritSet
     */
    TritSet(const TritSet& other);

    /**
     * @return  current capacity
     */
    std::size_t     capacity    ()                      const;

    /**
     * counts number of trits in set until the last significant trit
     *
     * @return vector in which
     *         [[True|Unknown|False].state()]
     *         ==
     *         number of [True|Unknown|False] trits in set
     */
    std::vector<std::size_t>  cardinality ()            const;

    /**
     * counts number of trits in set until the last significant trit
     *
     * @param   state  which trit.state() to count
     *
     * @return         number of trits, which state is equal to state, in set
     */
    std::size_t     cardinality(Tritenum state)         const;

    /**
     * counts number of trits in set until the last significant trit
     *
     * @param   other  which trit to count
     *
     * @return         number of trits, which equal to state, in set
     */
    template<typename A, typename B>
    std::size_t     cardinality (const TritBase<A, B>& other)const{
        return cardinality(other.state());
    }

    /**
     * assign ternary NOT
     *
     * @return  same set
     */
    TritSet&        flip        ();

    /**
     * number of significant trits
     *
     * @return          same set which equal to (ternary NOT *this)
     */
    std::size_t     length      ()                      const;

    /**
     * Equation operator
     *
     * @param   other   set to compare with
     * 
     * @return          if equals:   true
     *                  else:        false
     */
    bool            operator==  (const TritSet& other)  const;

    /**
     * Not equation operator
     *
     * @param   other   set to compare with
     * 
     * @return if equals:   false
     *         else:        true
     */
    bool            operator!=  (const TritSet& other)  const;

    /**
     * index operator
     *
     * @param   id  index
     *
     * @return      element, which provides access to the trit,
     *                       which located at id place
     */
    reference       operator[]  (std::size_t id);

    /**
     * constant index operator
     *
     * @param   id  index
     *
     * @return      copy of element, which located at id place
     */
    const Trit      operator[]  (std::size_t id)        const;

    /**
     * ternary AND
     *
     * @param   other   set
     * 
     * @return          new set which equal to (*this ternary AND other)
     */
    TritSet         operator&   (const TritSet& other)  const;

    /**
     * ternary OR
     *
     * @param   other   set
     * 
     * @return          new set which equal to (*this ternary OR other)
     */
    TritSet         operator|   (const TritSet& other)  const;

    /**
     * ternary XOR
     *
     * @param   other   set
     * 
     * @return          new set which equal to (*this ternary XOR other)
     */
    TritSet         operator^   (const TritSet& other)  const;

    /**
     * ternary NOT
     *
     * @return          new set which equal to (ternary NOT *this)
     */
    TritSet         operator~   ()                      const;

    /**
     * assign ternary AND
     *
     * @param   other   set
     * 
     * @return          same set which equal to (*this ternary AND other)
     */
    TritSet&        operator&=  (const TritSet& other);

    /**
     * ternary OR
     *
     * @param   other   set
     * 
     * @return          same set which equal to (*this ternary OR other)
     */
    TritSet&        operator|=  (const TritSet& other);

    /**
     * ternary XOR
     *
     * @param   other   set
     * 
     * @return          same set which equal to (*this ternary XOR other)
     */
    TritSet&        operator^=  (const TritSet& other);

    /**
     * resize set, so it can fit new_capacity elements
     * crop set if new size less than old size
     *
     * @param   new_capacity  new required capacity
     *
     * @return                same set which was resized
     */
    TritSet&        resize      (std::size_t new_capacity);

    /**
     * resize set, so it can fit all significant trits
     *
     * @return  same set which was resized
     */
    TritSet&        shrink      ();

    /**
     * forget all trits after lastIndex
     *
     * @param   lastIndex  index from which start to forget
     *
     * @return             same set in which all trits after lastIndex was forgotten
     */
    void            trim        (std::size_t lastIndex);

    /**
     * destructor of TritSet
     */
    virtual ~TritSet();
private:
    /**
     * current capacity
     */
    std::size_t _capacity;

    /**
     * basic set of TritSet
     */
    uint        *data;

    /**
     * subclass that provides access to the elements in TritSet by index
     */
    class reference : public TritBase<reference> {
    public:
        /**
         * TritSet constructor of TritSet::reference
         */
        reference(TritSet &set, std::size_t pos);

        /**
         * copy constructor of TritSet::reference
         */
        reference(const reference& other);

        /**
         * assign TritBase<A, B> operator
         * 
         * @param   other   class of trit, which was inherited from TritBase<A, B>
         *
         * @return          same reference
         */
        template<typename A, typename B>
        reference&  operator=(const TritBase<A, B>& other){
            return *this = other.state();
        }

        /**
         * assign Tritenum
         * 
         * @param   other   Tritenum {_False, _Unknown, _True}
         *
         * @return          same reference
         */
        virtual reference&  operator= (Tritenum state);

        /**
         * current state of Trit which accessed by TritSet::reference
         *
         * @return  state
         */
        virtual Tritenum    state     () const;

        /**
         * destructor of TritSet::reference
         */
        virtual             ~reference();
    protected:
        /**
         * default constructor of TritSet::reference
         */
        reference();
        /**
         * pointer to TritSet which associated with reference
         */
        TritSet *rset;
        /**
         * position of element which associated with reference
         */
        std::size_t  rpos;
    };
};

/**
 * overload of stream out operator
 *
 * @param   os  output stream
 *
 * @param   set TritSet to print in stream
 *
 * @return      reference to used std::ostream
 */
std::ostream &operator<<(std::ostream &os, const TritSet &set);

}
#endif

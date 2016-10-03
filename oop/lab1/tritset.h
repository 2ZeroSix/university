// TODO add noexcept modifiers
#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
#include <vector>
#include <ostream>
#include <iostream>
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
 * dynamic container for three-value logic elements
 */
class TritSet {
private:
    class reference;
    friend reference;
    // convenient internal representation of Tritenum
    enum class TritenumReal: unsigned char {Unknown=0, True, False};
    // covert standard representation to internal representation
    static TritenumReal toReal(Tritenum state);
    // covert internal representation to standard representation
    static Tritenum fromReal(TritenumReal state);
    // class for iterator and const_iterator
    template<typename ReferenceClass, typename TritSetClass>
    class base_iterator :
        public std::iterator
         <std::random_access_iterator_tag, ReferenceClass,
          std::ptrdiff_t, ReferenceClass, ReferenceClass> {
    private:
        friend TritSet;
    public:
        // default constructor of base_trit
        base_iterator() : rset(nullptr), rpos(0), out_of_range(true) {}
        // TritSet constructor of base_trit
        base_iterator(TritSetClass& set,  std::size_t pos) :
            rset(&set), rpos(pos), out_of_range(false) {
            if (!set.capacity()) {
                out_of_range = true;
            }
        }
        // copy constructor of base_trit
        base_iterator(const base_iterator<ReferenceClass, TritSetClass>& other) : 
            rset(other.rset), rpos(other.rpos), out_of_range(other.out_of_range) {}
        // cast to const version of base_iterator
        operator base_iterator<const reference, const TritSet>() const {
            base_iterator<const reference, const TritSet> buf;
            buf.rset = rset;
            buf.rpos = rpos;
            return buf;
        }
        bool            operator==  (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            return (rset == other.rset) && (rpos == other.rpos);
        }
        bool            operator!=  (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            return (rset != other.rset) || (rpos != other.rpos);
        }
        bool            operator<   (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            if (rset != other.rset) {
                return false;
            }
            if (out_of_range) {
                return true;
            }
            return rpos < other.rpos;
        }
        bool            operator>   (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            if (rset != other.rset) {
                return false;
            }
            if (other.out_of_range) {
                return true;
            }
            return rpos > other.rpos;
        }
        bool            operator<=  (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            if (rset != other.rset) {
                return false;
            }
            return !(*this > other);
        }
        bool            operator>=  (const base_iterator<ReferenceClass, TritSetClass>& other) const {
            if (rset != other.rset) {
                return false;
            }
            return !(*this < other);
        }
        ReferenceClass operator*   () {
            if (rset) {
                return tritspace::TritSet::reference(*const_cast<TritSet*>(rset), rpos);
            }
            return reference();
        }
        ReferenceClass operator->  () {
            if (rset) {
                return tritspace::TritSet::reference(*const_cast<TritSet*>(rset), rpos);
            }
            return reference();
        }
        base_iterator<ReferenceClass, TritSetClass>  operator+   (size_t range) const {
            if (out_of_range) {
                out_of_range = false;
            }
            return base_iterator<ReferenceClass, TritSetClass>(*rset, rpos + range);
        }
        base_iterator<ReferenceClass, TritSetClass>& operator+=  (size_t range) {
            if (out_of_range) {
                out_of_range = false;
            }
            rpos += range;
            return *this;
        }
        base_iterator<ReferenceClass, TritSetClass>& operator++  () {
            if (out_of_range) {
                out_of_range = false;
            }
            ++rpos;
            return *this;
        }
        base_iterator<ReferenceClass, TritSetClass>  operator++  (int) {
            if (out_of_range) {
                out_of_range = false;
            }
            return base_iterator(*rset, rpos++);
        }
        base_iterator<ReferenceClass, TritSetClass>  operator-   (size_t range) const {
            base_iterator<ReferenceClass, TritSetClass> buf = *this;
            return buf -= range;
        }
        base_iterator<ReferenceClass, TritSetClass>& operator-=  (size_t range) {
            if (!out_of_range) {
                if (rpos < range) {
                    out_of_range = true;
                    rpos = 0;
                }
                else {
                    rpos = rpos - range;
                }
            }
            return *this;
        }
        base_iterator<ReferenceClass, TritSetClass>& operator--  () {
            if(!out_of_range) {
                if(rpos == 0) {
                    out_of_range = true;
                }
                else {
                    --rpos;
                }
            }
            return *this;
        }
        base_iterator<ReferenceClass, TritSetClass>  operator--  (int) {
            base_iterator<ReferenceClass, TritSetClass> buf = *this;
            --(*this);
            return buf;
        }
        ReferenceClass operator[]  (size_t pos) const {
            return tritspace::TritSet::reference(*const_cast<TritSet*>(rset), rpos + pos);
        }
        virtual ~base_iterator() noexcept{
            TritSetClass* volatile &bufset = rset;
            volatile size_t &bufpos = rpos;
            volatile bool &bufoor = out_of_range;
            bufset = nullptr;
            bufpos = 0;
            bufoor = true;
        }
    private:
        /**
         * pointer to TritSet which associated with iterator
         */
        TritSetClass *rset;
        /**
         * position of iterator
         */
        std::size_t  rpos;
        bool out_of_range;
    };
public:
    typedef base_iterator<reference, TritSet>               iterator;
    typedef base_iterator<const reference, const TritSet>   const_iterator;

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
    TritSet(const Trit arrt[], std::size_t count);

    /**
     * initializer list constructor of TritSet
     */
    TritSet(const std::initializer_list<Trit> list);

    /**
     * copy constructor of TritSet
     */
    TritSet(const TritSet& other);

    /**
     * move constructor of TritSet
     */
    TritSet(TritSet&& other);

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
     * @return         number of trits, which state is equal to other.state(), in set
     */
    std::size_t     cardinality (const Trit& other)const{
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
     * assign ternary OR
     *
     * @param   other   set
     * 
     * @return          same set which equal to (*this ternary OR other)
     */
    TritSet&        operator|=  (const TritSet& other);

    /**
     * assign ternary XOR
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

    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end() {
        return iterator(*this, capacity());
    }

    const_iterator begin() const {
        return const_iterator(*this, 0);
    }

    const_iterator end() const {
        return const_iterator(*this, capacity());
    }

    const_iterator cbegin() const {
        return const_iterator(*this, 0);
    }

    const_iterator cend() const {
        return const_iterator(*this, capacity());
    }
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
     *
     * note:
     *     will not change anything if defined as const,
     *     so if you need to get element of const TritSet
     *     as TritSet::reference you must use *const_cast<TritSet*>(&set)
     */
    class reference : public TritBase<reference> {
    private:
        friend TritSet;
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
         * assign Tritenum
         * 
         * @param   other   Tritenum::[False|Unknown|True]
         *
         * @return          same reference
         */
        virtual reference&  operator= (Tritenum state) override;
        
        // it's necessary because previous definition
        // hides other overloads of operator=
        using TritBase<reference>::operator=;

        /**
         * current state of Trit which accessed by TritSet::reference
         *
         * @return  state
         */
        virtual Tritenum    state     () const override;

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
    private:
        // for use in iterators
        reference* operator->(){
            return this;
        }
        const reference* operator->() const{
            return this;
        }
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

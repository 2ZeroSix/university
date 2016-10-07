// TODO add noexcept modifiers
#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
#include <vector>
#include <ostream>
#include <iostream> //for test
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
    // convert standard representation to internal representation
    static TritenumReal toReal(Tritenum state);
    // convert internal representation to standard representation
    static Tritenum fromReal(TritenumReal state);


    // class for iterator and const_iterator
    template<typename ReferenceClass, typename TritSetClass>
    class base_iterator :
        public std::iterator
         <std::random_access_iterator_tag, ReferenceClass,
          std::ptrdiff_t, ReferenceClass*, ReferenceClass> {
    private:
        friend TritSet;
    public:
        // default constructor of base_trit
        base_iterator() noexcept
         : rset( nullptr), rpos(0) {}

        // TritSet constructor of base_trit
        base_iterator(TritSetClass& set,  std::size_t pos) noexcept
         : rset(&set), rpos(pos) {}

        // copy constructor of base_trit
        base_iterator(const base_iterator<ReferenceClass, TritSetClass>& other) noexcept
         : rset(other.rset), rpos(other.rpos) {}

        // cast to const version of base_iterator
        operator base_iterator<const reference, const TritSet>() const noexcept{
            base_iterator<const reference, const TritSet> buf;
            buf.rset = rset;
            buf.rpos = rpos;
            return buf;
        }
       
        bool            operator==  (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return (rset == other.rset) && (rpos == other.rpos);
        }

        bool            operator!=  (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return (rset != other.rset) || (rpos != other.rpos);
        }

        bool            operator<   (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return rpos < other.rpos;
        }

        bool            operator>   (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return rpos > other.rpos;
        }

        bool            operator<=  (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return rpos <= other.rpos;
        }

        bool            operator>=  (const base_iterator<const reference, const TritSet>& other) const noexcept{
            return rpos >= other.rpos;
        }

        ReferenceClass  operator*   () const noexcept{
            if (rset) {
                return reference(*const_cast<TritSet*>(rset), rpos);
            }
            return reference();
        }

        ReferenceClass  operator->  () const noexcept{
            if (rset) {
                return reference(*const_cast<TritSet*>(rset), rpos);
            }
            return reference();
        }

        base_iterator<ReferenceClass, TritSetClass>  operator+   (std::ptrdiff_t range) const noexcept{
            return base_iterator<ReferenceClass, TritSetClass>(*rset, rpos + range);
        }

        base_iterator<ReferenceClass, TritSetClass>& operator+=  (std::ptrdiff_t range) noexcept{
            rpos += range;
            return *this;
        }

        base_iterator<ReferenceClass, TritSetClass>& operator++  () noexcept{
            ++rpos;
            return *this;
        }

        base_iterator<ReferenceClass, TritSetClass>  operator++  (int) noexcept{
            base_iterator<ReferenceClass, TritSetClass> buf = *this;
            ++rpos;
            return buf;
        }

        base_iterator<ReferenceClass, TritSetClass>  operator-   (std::ptrdiff_t range) const noexcept{
            base_iterator<ReferenceClass, TritSetClass> buf = *this;
            return buf -= range;
        }

        base_iterator<ReferenceClass, TritSetClass>& operator-=  (std::ptrdiff_t range) noexcept{
            rpos = rpos - range;
            return *this;
        }

        base_iterator<ReferenceClass, TritSetClass>& operator--  () noexcept{
            --rpos;
            return *this;
        }

        base_iterator<ReferenceClass, TritSetClass>  operator--  (int) noexcept{
            base_iterator<ReferenceClass, TritSetClass> buf = *this;
            --rpos;
            return buf;
        }

        ReferenceClass operator[]  (std::ptrdiff_t pos) const noexcept{
            if (rset) {
                return reference(*const_cast<TritSet*>(rset), rpos + pos);
            }
            return reference();
        }

        virtual ~base_iterator() noexcept{
            TritSetClass* volatile  &bufset = rset;
            volatile std::ptrdiff_t         &bufpos = rpos;
            bufset = nullptr;
            bufpos = 0;
        }
    private:
        /**
         * pointer to TritSet which associated with iterator
         */
        TritSetClass *rset;

        /**
         * position of iterator
         */
        mutable std::ptrdiff_t  rpos;
    };
public:
    typedef base_iterator<reference, TritSet>               iterator;
    typedef base_iterator<const reference, const TritSet>   const_iterator;
    // TODO resolve problem with dereference of reverse_iterator
    // typedef std::reverse_iterator<iterator>                 reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>           const_reverse_iterator;
    // iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    // reverse_iterator rbegin();
    // reverse_iterator rend();
    // const_reverse_iterator rbegin() const;
    // const_reverse_iterator rend() const;
    // const_reverse_iterator crbegin() const;
    // const_reverse_iterator crend() const;

    /**
     * default constructor of TritSet
     */
    TritSet() noexcept;

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
    explicit TritSet(const TritSet& other);

    /**
     * move constructor of TritSet
     */
    TritSet(TritSet&& other);

    /**
     * @return  current capacity
     */
    std::size_t                 capacity    ()            const;

    /**
     * counts the number of trits are in a certain state
     * until the last significant trit
     *
     * @return vector in which
     *         [casted to [unsigned] integer [True|Unknown|False]]
     *         ==
     *         number of [True|Unknown|False] trits in set
     */
    std::vector<std::size_t>    cardinality ()            const;

    /**
     * counts the number of trits are in a certain state
     * until the last significant trit
     *
     * @param   state  which trit.state() to count
     *
     * @return         number of trits with state which equals to passed state, in set
     */
    std::size_t                 cardinality (Tritenum state)const;

    /**
     * assign ternary NOT
     *
     * @return  same set
     */
    TritSet&                    flip        ();

    /**
     * number of significant trits
     *
     * @return          same set which equal to (ternary NOT *this)
     */
    std::size_t                 length      ()          const;

    /**
     * copy assign operator of TritSet
     *
     * @param   other   TritSet
     *
     * @return          same set which was changed
     */
    TritSet& operator= (const TritSet& other);

    /**
     * move assign operator of TritSet
     *
     * @param   other   TritSet
     *
     * @return          same set which was changed
     */
    TritSet& operator= (TritSet&& other);

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
     * Inequality operator
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

    friend void swap(TritSet& first, TritSet& second) noexcept {
        std::swap(first.data, second.data);
        std::swap(first._capacity, second._capacity);
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
        reference(reference&& other)
         :rset(other.rset), rpos(other.rpos) {
            other.rset = nullptr;
            other.rpos = 0;
         }

        using TritBase<reference>::operator=;
        /**
         * destructor of TritSet::reference
         */
        virtual             ~reference();

        // for use in iterators only
        reference* operator->();
        const reference* operator->() const;
    protected:
        /**
         * assign Tritenum
         * 
         * @param   other   Tritenum::[False|Unknown|True]
         *
         * @return          same reference
         */
        virtual reference&  set (Tritenum state) override;

        /**
         * current state of Trit which accessed by TritSet::reference
         *
         * @return  state
         */
        virtual Tritenum    get () const override;

        /**
         * default constructor of TritSet::reference
         */
        reference();
    private:
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

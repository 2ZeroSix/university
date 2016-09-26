#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
#include <vector>
#include <ostream>

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
    // convenient internal representation of trits
    enum TritenumReal : unsigned char {_UnknownReal=0, _TrueReal, _FalseReal};
    static TritenumReal toReal(Tritenum state);
    static Tritenum fromReal(TritenumReal state);
public:
    explicit TritSet():_capacity(0), data(nullptr) { }
    explicit TritSet(std::size_t reserve);
    explicit TritSet(const Trit *arrt, std::size_t count);
    TritSet(const TritSet& other);
    std::size_t     capacity    ()                      const;
    std::vector<std::size_t>  cardinality ()            const;
    std::size_t     cardinality(Tritenum state)         const;
    template<typename A, typename B>
    std::size_t     cardinality (const TritBase<A, B>& other)const{
        return cardinality(other.state());
    }
    TritSet&        flip        ();
    std::size_t     length      ()                      const;
    TritSet&        operator=   (const TritSet& other);
    bool            operator==  (const TritSet& other)  const;
    bool            operator!=  (const TritSet& other)  const;
    reference       operator[]  (std::size_t id);
    const Trit      operator[]  (std::size_t id)        const;
    TritSet         operator&   (const TritSet& other)  const;
    TritSet         operator|   (const TritSet& other)  const;
    TritSet         operator^   (const TritSet& other)  const;
    TritSet         operator~   ()                      const;
    TritSet&        operator&=  (const TritSet& other);
    TritSet&        operator|=  (const TritSet& other);
    TritSet&        operator^=  (const TritSet& other);
    TritSet&        resize      (std::size_t new_capacity);
    TritSet&        shrink      ();
    void            trim        (std::size_t lastIndex);
    virtual ~TritSet();
private:
    std::size_t _capacity;
    uint        *data;
    class reference : public TritBase<reference, Trit> {
    public:
        reference(TritSet &set, std::size_t pos);
        reference(const reference& other);
        template<typename A, typename B>
        reference&  operator=(const TritBase<A, B>& other){
            return *this = other.state();
        }
        virtual reference&  operator= (Tritenum state);
        virtual Tritenum    state     () const;
        virtual             ~reference();
    private:
        reference();
        TritSet *rset;
        std::size_t  rpos;
    };
};

std::ostream &operator<<(std::ostream &os, const TritSet &set);

}
#endif

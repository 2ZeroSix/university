#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
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
 * initialize uint by Unknown trits
 *
 * @return  initialized uint
 */
uint unknown_uint();

/**
 * dynamic container for trit logic elements
 */
class TritSet {
private:
    class reference;
public:
    explicit TritSet(std::size_t reserve);
    TritSet(const TritSet& other);
    std::size_t     capacity    ()                      const;
    std::vector<std::size_t>  cardinality ()            const;
    std::size_t     cardinality (Tritenum value)  const;
    TritSet&        flip        ();
    std::size_t     length      ()                      const;
    TritSet&        operator=   (const TritSet& other);
    reference       operator[]  (std::size_t id);
    const Trit      operator[]  (std::size_t id)        const;
    TritSet         operator&   (const TritSet& other)  const;
    TritSet         operator|   (const TritSet& other)  const;
    TritSet            operator^(const TritSet& other)  const;
    TritSet         operator~   ()                      const;
    TritSet&        operator&=  (const TritSet& other);
    TritSet&        operator|=  (const TritSet& other);
    TritSet&        operator^=  (const TritSet& other);
    TritSet&        shrink      ();
    void            trim        (std::size_t lastIndex);
    virtual ~TritSet();
private:
    TritSet&    resize          (std::size_t new_capacity);
    uint        *data;
    std::size_t _capacity;
    class reference : public TritBase<reference, Trit> {
    public:
        reference(TritSet &set, std::size_t pos);
        reference(const reference& other);
        template<typename A, typename B>
        reference&  operator=(const TritBase<A, B>& other){
            return *this = other.state();
        }
        virtual reference&  operator=(Tritenum state);
        virtual Tritenum    state    () const;
        virtual             ~reference();
    private:
        reference();
        TritSet *rset;
        std::size_t  rpos;
    };
};

}
#endif

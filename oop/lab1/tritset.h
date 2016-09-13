#ifndef _TRITSET_H_
#define _TRITSET_H_
#include <cstddef>
#include "trit.h"
namespace tritspace{

    class TritSet {
    private:
        class reference{
        public:
            reference(TritSet &set, size_t pos);
            reference(const reference& other);
            operator   Trit      () const;
            operator   Trit      ();
            reference& operator= (const Trit other);
            reference& operator= (const reference& other);
            template<class T,
            class = typename std::enable_if<std::is_convertible<T, Trit>::value>::type>
            const Trit operator&(const T &other)    const{
                return Trit(*this)&other;
            }
            template<class T,
            class = typename std::enable_if<std::is_convertible<T, Trit>::value>::type>
            const Trit operator|(const T &other)    const{
                return Trit(*this)|other;
            }
            template<class T,
            class = typename std::enable_if<std::is_convertible<T, Trit>::value>::type>
            const Trit operator^(const T &other)    const{
                return Trit(*this)^other;
            }
            reference& flip      ();  
            ~reference();
        private:
            friend class TritSet;
            reference();
            TritSet *rset;
            size_t  rpos;
        };
        friend class reference;
    public:
        typedef unsigned int uint;
        TritSet(size_t reserve) {
            if ((_capacity = extend_to_capacity(reserve))){
                data = new uint[(_capacity * 2) / (8 * sizeof(uint))];
                for (size_t i = 0; i < (_capacity * 2) / (8 * sizeof(uint)); ++i) {
                    data[i] = static_cast<uint>(0x5555555555555555);
                }
            }
        }
        TritSet(const TritSet& other);
        size_t     capacity   () const;
        const Trit operator[] (size_t id) const;
        reference  operator[] (size_t id);
        TritSet&   operator=  (const TritSet& other);
        TritSet    operator&  (const TritSet& other) const;
        TritSet    operator|  (const TritSet& other) const;
        TritSet    operator^  (const TritSet& other) const;
        TritSet    operator~  () const;
        TritSet&   operator&= (const TritSet& other);
        TritSet&   operator|= (const TritSet& other);
        TritSet&   operator^= (const TritSet& other);
        TritSet&   flip       ();
        TritSet&   resize     (size_t new_capacity);
        ~TritSet();
    private:
        size_t extend_to_capacity(size_t num) {
            return  ((num)/(4 * sizeof(uint)))*4*sizeof(uint) 
                    + (((2 * num) % (8 * sizeof(uint)))
                            ? sizeof(uint)*4 : 0);
        }
        uint   *data;
        size_t _capacity;
    };

}
#endif

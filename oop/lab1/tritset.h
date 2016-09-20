#ifndef _TRITSET_H_
#define _TRITSET_H_
#include "trit.h"
namespace tritspace{

    std::size_t extend_to_capacity(std::size_t num);

    class TritSet {
    private:
        class reference;
        friend class reference;
    public:
        typedef unsigned int uint;
        explicit TritSet(std::size_t reserve);
        TritSet(const TritSet& other);
        std::size_t     capacity    ()                      const;
        // don't forget to use delete[] after call of this function
        std::size_t*    cardinality ()                      const;
        std::size_t     cardinality (const Trit value)      const;
        TritSet&        flip        ();
        std::size_t     length      ()                      const;
        TritSet&        operator=   (const TritSet& other);
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
        uint        *data;
        std::size_t _capacity;
        class reference : public TritBase<reference, Trit> {
        public:
            reference(TritSet &set, std::size_t pos);
            reference(const reference& other);
            virtual reference&  operator=   (const Tritenum state);
            virtual Tritenum state() const;
            virtual ~reference();
        private:
            friend class TritSet;
            reference();
            TritSet *rset;
            std::size_t  rpos;
        };
    };

}
#endif

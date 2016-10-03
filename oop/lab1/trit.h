#ifndef _TRIT_H_
#define _TRIT_H_
#include <ostream>
#include <iostream>
#include "trit_base.h"

namespace tritspace{

    Tritenum operator+(Tritenum a, Tritenum b);

    /**
     * standard Trit realization
     *
     * note:
     *     all trit realizations,
     *     which was inherited from TritBase<realization>,
     *     can be casted to Trit
     */
    class Trit : public TritBase<Trit>{
    public:
        // default constructor of trit
        explicit Trit() noexcept;
        // copy constructor of Trit
        Trit(const Trit& other) noexcept;
        // Tritenum constructor of Trit
        // 
        // don't checks if it's one of significant Tritenum values
        Trit(Tritenum state) noexcept;
        // integral constructor of Trit
        // 
        // _state = Tritenum(state mod 3)
        explicit Trit(std::size_t state) noexcept;
        // assign operator of Trit
        // 
        // doesn't checks if it's one of significant Tritenum values
        virtual  Trit& operator=(Tritenum state) noexcept override;
        using TritBase<Trit>::operator=;
        // returns current state of Trit
        virtual  Tritenum state() const noexcept override;
        // destructor of trit
        virtual ~Trit() noexcept;
    private:
        // current state of Trit
        Tritenum _state;
    };

    // define default Trits
    const Trit False  (Tritenum::False);
    const Trit Unknown(Tritenum::Unknown);
    const Trit True   (Tritenum::True);

    /**
     * overload of stream out operator
     * for main realization of trit
     *
     * @param   os  output stream
     *
     * @param   set Trit to print in stream
     *
     * @return      reference to used std::ostream
     */
    std::ostream& operator<<(std::ostream &os, const Trit &trit);

}

#endif

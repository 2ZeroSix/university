#include "trit.h"

namespace tritspace {
using namespace std;

    Tritenum operator+(Tritenum a, Tritenum b) {
        return static_cast<Tritenum>((static_cast<unsigned char>(a) + static_cast<unsigned char>(b)) % 3);
    }

    Trit::Trit() noexcept
     : _state(Tritenum::Unknown) {}

    Trit::Trit(const Trit& other) noexcept
     :_state(other.state()) {}

    Trit::Trit(std::size_t state) noexcept{
        _state = static_cast<Tritenum>(state % 3);
    }

    Trit::Trit(Tritenum state) noexcept{
        _state = state;
    }

    Trit& Trit::operator=(Tritenum state) noexcept{
        _state = state;
        return *this;
    }

    Tritenum Trit::state() const noexcept{
        return _state;
    }

    Trit::~Trit() noexcept{
        // avoid optimizations which can delete assigning
        volatile Tritenum &buf = _state;
        buf = Tritenum::Unknown;
    }
    std::ostream& operator<<(std::ostream &os, const Trit &trit) {
        os << trit.to_string();
        return os;
    }
}
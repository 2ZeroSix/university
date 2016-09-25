#ifndef _TRIT_H_
#define _TRIT_H_
// #include <type_traits>
#include "trit_base.h"
namespace tritspace{

class Trit : public TritBase<Trit>{
public:
    explicit Trit() : _state(_Unknown) {}
    template<typename A, typename B>
    Trit(const TritBase<A, B>& other):_state(other.state()) {}
    explicit Trit(const int state) {
        _state = Tritenum((state < 0) ? _False : (state > 0 ? _True : _Unknown));
    }
    virtual  Trit& operator=(const Tritenum state) {
        _state = Tritenum((state < 0) ? _False : (state > 0 ? _True : _Unknown));
        return *this;
    }
    virtual  Tritenum state() const {
        return _state;
    }
    virtual ~Trit() {
        _state = _Unknown;
    }
private:
    Tritenum _state;
};

const Trit False  (_False);
const Trit Unknown(_Unknown);
const Trit True   (_True);

}
#endif

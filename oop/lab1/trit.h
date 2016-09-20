#ifndef _TRIT_H_
#define _TRIT_H_
#include <type_traits>
#include "trit_base.h"
namespace tritspace{

class Trit : public TritBase<Trit>{
public:
    Trit() : _state(_Unknown) { };
    Trit(const int state) {
        _state = Tritenum((state < 0) ? -(state % 3) : state % 3);
    }
    virtual Trit& operator=(const Tritenum state) {
        _state = Tritenum(state % 3);
        return *this;
    }
    Trit& operator=(const Trit &other) {
        _state = other._state;
        return *this;
    }
    virtual     Tritenum state() const {
        return _state;
    }
    virtual ~Trit() { }
private:
    Tritenum _state;
};

const Trit False  (_False);
const Trit Unknown(_Unknown);
const Trit True   (_True);

}
#endif

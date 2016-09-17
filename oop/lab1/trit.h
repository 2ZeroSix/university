#ifndef _TRIT_H_
#define _TRIT_H_
#include <type_traits>
#include "trit_base.h"
namespace tritspace{

class Trit : public TritBase<Trit>{
public:
    Trit() : _state(_Unknown) { };
    Trit(const Tritenum state);
    template <class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit(T state) {
        _state = Tritenum((state < 0) ? -(state % 3) : state % 3);
    }
    virtual Trit& operator=(Tritenum state) {_state = state; return *this;} 
    Trit& operator=(const Trit &other);
    virtual     Tritenum state()        const {return _state;}
    virtual ~Trit() { }
private:
    Tritenum _state;
};

const Trit False  (_False);
const Trit Unknown(_Unknown);
const Trit True   (_True);

}
#endif

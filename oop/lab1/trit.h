#ifndef _TRIT_H_
#define _TRIT_H_
#include <type_traits>
namespace tritspace{

class Trit {
public:
    enum Tritenum : unsigned char {_False, _Unknown, _True};
    Trit() : _state(_Unknown) { };
    Trit(Tritenum state);
    template <class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit(T state) {
        _state = Tritenum((state < 0) ? -(state % 3) : state % 3);
    }
    Trit& operator=(const Trit &other);
    template <class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit& operator=(T other) {
        _state = Tritenum((other < 0) ? -(other % 3) : other % 3);
        return *this;
    }
    operator Tritenum()               const;
    // Trit operator&(const Trit &other) const;
    template<class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit operator&(const T &other)    const{
        return (_state < static_cast<Tritenum>(other)) ? _state : static_cast<Tritenum>(other);
    }
    // Trit operator|(const Trit &other) const;
    template<class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit operator|(const T &other)    const{
        return (_state > Tritenum(other)) ? _state : Tritenum(other);
    }
    // Trit operator^(const Trit &other) const;
    template<class T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
    Trit operator^(const T &other)    const{
        return (_state + Tritenum(other));
    }
    Trit operator~()                  const;
    const char* to_string()           const; 
    ~Trit();
private:
    Tritenum _state;
};

const Trit False  (Trit::_False);
const Trit Unknown(Trit::_Unknown);
const Trit True   (Trit::_True);

}
#endif

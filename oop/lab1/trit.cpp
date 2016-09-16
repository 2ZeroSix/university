#include "trit.h"
#include <iostream>
namespace tritspace {

    Trit::Trit(Tritenum state) {
        _state = Tritenum((state < 0) ? -(state % 3) : state % 3);
    }

    Trit& Trit::operator=(const Trit &other) {
        _state = other._state;
        return *this;
    }

    Trit::operator Tritenum() const{
        return _state;
    }

    Trit Trit::operator~() const{
        switch (_state) {
            case _False:
                return True;
            case _Unknown:
                return Unknown;
            case _True:
                return False;
        }
    }

    const char* Trit::to_string() const{
        switch (_state) {
            case _False:
                return "False";
            case _Unknown:
                return "Unknown";
            case _True:
                return "True";
        }    
    }

    Trit::~Trit() { };

}

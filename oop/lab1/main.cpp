#include "tritset.h"
#include <iostream>

using namespace std;
using namespace tritspace;

int main() {
    TritSet set(10);
    for (int i = 0; i <= 11; ++i) {
        set[i] = Trit(i);
    }
    for (int j = 0; j <= 11; ++j)
    {
        cout << Trit(set[j]).to_string() << endl;
    }
    cout << endl;
    cout << (set[1] | True | set[2] & set[0]).to_string() << endl << endl;
    const TritSet cset = set;
    for (int j = 0; j <= 100; ++j)
    {
        cout << Trit(set[j]).to_string() << endl;
    }
    cout << endl;
        
        cout << (True    | True)    << " ";
        cout << (True    | Unknown) << " ";
        cout << (True    | False)   << endl;
        cout << (Unknown | True)    << " ";
        cout << (Unknown | False)   << " ";
        cout << (Unknown | Unknown) << endl;
        cout << (True    | False)   << " ";
        cout << (Unknown | False)   << " ";
        cout << (False   | False)   << endl << endl;
        cout << (True    ^ True)    << " ";
        cout << (True    ^ Unknown) << " ";
        cout << (True    ^ False)   << endl;
        cout << (True    ^ Unknown) << " ";
        cout << (Unknown ^ False)   << " ";
        cout << (Unknown ^ Unknown) << endl;
        cout << (True    ^ False)   << " ";
        cout << (Unknown ^ False)   << " ";
        cout << (False   ^ False)   << endl << endl;
        cout << (True    & True)    << " ";
        cout << (True    & Unknown) << " ";
        cout << (True    & False)   << endl;
        cout << (True    & Unknown) << " ";
        cout << (Unknown & Unknown) << " ";
        cout << (Unknown & False)   << endl;
        cout << (True    & False)   << " ";
        cout << (Unknown & False)   << " ";
        cout << (False   & False)   << endl << endl;
        cout << ~True               << " ";
        cout << ~Unknown            << " ";
        cout << ~False              << endl << endl;
    
    const Trit a;
    // a = -11;
    cout << a.to_string()           << endl;
    cout << (Unknown|Trit(2)).to_string() << endl;
    // cout << (Unknown|2) << endl;
    auto v = set.cardinality();
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    return 0;
}

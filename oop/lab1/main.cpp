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
    
    
        cout << (True    | True).to_string()    << " ";
        cout << (True    | Unknown).to_string() << " ";
        cout << (True    | False).to_string()   << endl;
        cout << (Unknown | True).to_string()    << " ";
        cout << (Unknown | False).to_string()   << " ";
        cout << (Unknown | Unknown).to_string() << endl;
        cout << (True    | False).to_string()   << " ";
        cout << (Unknown | False).to_string()   << " ";
        cout << (False   | False).to_string()   << endl << endl;
        cout << (True    ^ True).to_string()    << " ";
        cout << (True    ^ Unknown).to_string() << " ";
        cout << (True    ^ False).to_string()   << endl;
        cout << (True    ^ Unknown).to_string() << " ";
        cout << (Unknown ^ False).to_string()   << " ";
        cout << (Unknown ^ Unknown).to_string() << endl;
        cout << (True    ^ False).to_string()   << " ";
        cout << (Unknown ^ False).to_string()   << " ";
        cout << (False   ^ False).to_string()   << endl << endl;
        cout << (True    & True).to_string()    << " ";
        cout << (True    & Unknown).to_string() << " ";
        cout << (True    & False).to_string()   << endl;
        cout << (True    & Unknown).to_string() << " ";
        cout << (Unknown & Unknown).to_string() << " ";
        cout << (Unknown & False).to_string()   << endl;
        cout << (True    & False).to_string()   << " ";
        cout << (Unknown & False).to_string()   << " ";
        cout << (False   & False).to_string()   << endl << endl;
        cout << (~True).to_string()    << " ";
        cout << (~Unknown).to_string() << " ";
        cout << (~False).to_string()   << endl << endl;
    
    const Trit a;
    // // a = -11;
    cout << a.to_string()           << endl;
    cout << (Unknown|Trit(2)).to_string() << endl;
    // cout << (Unknown|2) << endl;
    auto v = set.cardinality();
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    return 0;
}

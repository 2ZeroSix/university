#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv) {
    int* a[10];
    int (*b)[10];

    cout << typeid(a).name() << endl << typeid(b).name() << endl;
    a[9] = new int(1);
    (*b)[9] = int(1);
    for (auto& elem : a) cout << elem << " ";
    cout << endl;
    for (auto& elem : *b) cout << elem << " ";
    cout << endl;
}

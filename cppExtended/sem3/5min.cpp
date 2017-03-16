#include <string>
#include <iostream>
using namespace std;
template<typename Head>
void print(const string& form, size_t place, Head head) {
    for(size_t i = place; i < form.size(); ++i) {
        if(form[i] == '%') {
            cout << head;
        } else {
            cout << form[i];
        }
    }
}
template<typename Head, typename... Tail>
void print(const string& form, size_t place, Head head, Tail... tail) {
    for(size_t i = place; i < form.size(); ++i) {
        if(form[i] == '%') {
            cout << head;
            print(form, i + 1, tail...);
            return;
        } else {
            cout << form[i];
        }
    }
}

int main() {
    print("hi % lol % %\n", 1, "hey", 'c');
}
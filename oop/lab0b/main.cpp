#include "sort_strings.h"

using namespace sort_strings_h;
using namespace std;
int main(int argc, char *argv[]) {
    if (argc == 3) {
        ifstream fin(argv[1]);
        ofstream fout(argv[2]);
        if (fin.is_open() && fout.is_open()) {
            sort_strings(&fin, &fout);
            return 0;
        }
        else {
            return 1;
        }
    }
    if (argc == 2) {
        ifstream fin(argv[1]);
        if (fin.is_open())
            sort_strings(&fin, &cout);
    }
    sort_strings(&cin, &cout);
    return 0;
}
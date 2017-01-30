#include "MainRoutines.h"

using namespace std;
using namespace SearcherSpace;

int main(int argc, char *argv[]) {
    auto bufargs = parser(argc, argv);
    int errs = bufargs.first;
    try {
        if (!errs) {
            errs |= solveAnyLabyrinth(get<0>(bufargs.second), get<1>(bufargs.second), get<2>(bufargs.second), get<3>(bufargs.second));
        }
        if (!errs) {
            cout << "COMPLETE. Check file: " << get<1>(bufargs.second) << endl;
        }
    }
    catch (std::invalid_argument e) {
        cout << "exception: " << e.what() << endl;
    }
    printErrors(errs);
    return errs >> 1;
}
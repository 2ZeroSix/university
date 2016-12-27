#include <list>
#include <queue>
#include <tuple>
#include <iostream>
#include "Plane.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Searcher.h"
using namespace std;
using namespace SearcherSpace;

struct comparator {
    bool operator()(const tuple<list<int>, int>& a, const tuple<list<int>, int>& b) {
        return get<1>(a) > get<1>(b);
    }
};

int main() {
    Torus pl;
    cin >> pl;
    cout << pl << endl << endl;
    Searcher<TwoDimPoint, size_t> robot(pl);
    pl.drawPath(robot.search());
    cout << pl;
    return 0;
}
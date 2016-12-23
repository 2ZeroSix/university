#include <list>
#include <queue>
#include <tuple>
#include <iostream>
#include "Plane.h"
#include "Searcher.h"
using namespace std;
using namespace SearcherSpace;

struct comparator {
    bool operator()(const tuple<list<int>, int>& a, const tuple<list<int>, int>& b) {
        return get<1>(a) > get<1>(b);
    }
};

int main() {
    Plane pl;
    cin >> pl;
    cout << pl;
    Searcher<TwoDimPoint, size_t> robot(pl);
    auto vec = robot.search();

}
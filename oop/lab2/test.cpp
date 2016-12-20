#include <list>
#include <queue>
#include <tuple>
#include <iostream>
#include "TwoDimSurface.h"
#include "Searcher.h"
using namespace std;
using namespace SearcherSpace;

struct comparator {
    bool operator()(const tuple<list<int>, int>& a, const tuple<list<int>, int>& b) {
        return get<1>(a) > get<1>(b);
    }
};

int main() {
    priority_queue<tuple<list<int>, int>, vector<tuple<list<int>, int>>, comparator>
    que(comparator(),
        vector<tuple<list<int>, int>>(1, make_tuple(list<int>(1, 1), 99)));
    que.push(make_tuple(list<int>(10), 10));
    que.push(make_tuple(list<int>(10), 7));
    que.push(make_tuple(list<int>(10), 11));
    while(!que.empty()) {
        cout << get<1>(que.top()) << endl;
        que.pop();
    }
    cout << int() << endl << float() << endl << uint() << endl;
    Searcher<TwoDimPoint, uint> robot;

}
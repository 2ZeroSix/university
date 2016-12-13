#ifndef _SEARCHER_H_
#define _SEARCHER_H_
#include "Surface.h"
#include <queue>
#include <functional>

template<typename P, typename M>
P minPoint (const std::vector<tuple<P, M>>& vec) {
    std::tuple<P, M> min;
    for (auto& point: vec) {
        if (point[1] < min[1]) {
            min = point;
        }
    }
    return min[0];
}

/**
 * P - type of point
 * M - type of metric
 */
template<typename P, typename M>
int Search(Surface<P, M>& start, const P& end) {
    while(start != end) {
        auto vec = start.lookup();
        if(vec.empty()) {
            return 1;
        }
        P next = minPoint();
        start.move(next);
    }
    return 0;
}

#endif

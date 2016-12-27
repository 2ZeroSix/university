#ifndef _SEARCHER_H_
#define _SEARCHER_H_
#include "Surface.h"
#include <unordered_map>
#include <queue>
#include <functional>


namespace SearcherSpace {

template<typename P, typename M>
struct pathGT{
    bool operator()(const std::tuple<std::vector<P>, M> &a,
                    const std::tuple<std::vector<P>, M> &b) {
        return std::get<1>(a) > std::get<1>(b);
    }

};

template<typename P, typename M>
struct pointGT{
    bool operator()(const std::tuple<P, M> &a, const std::tuple<P, M> &b) {
        return std::get<1>(a) > std::get<1>(b);
    }

};


template<typename P, typename M>
std::tuple<P, M> minPoint (const std::vector<std::tuple<P, M>>& vec) {
    std::tuple<P, M> min;
    if (!vec.empty()) {
        min =  vec[0];
        for (auto& point: vec) {
            if (std::get<1>(point) < std::get<1>(min)) {
                min = point;
            }
        }
    }
    return min;
}


template<typename P, typename M>
class Searcher {
private:
    Surface<P, M>* surf;
    std::tuple<std::vector<P>, M> current;
public:
    Searcher()                      : surf( nullptr ), current(std::vector<P>(0), M()) {}
    Searcher(Surface<P, M> &surface): surf(&surface ), current(std::vector<P>(0), M()) {}
    Searcher(Surface<P, M> *surface): surf( surface ), current(std::vector<P>(0), M()) {}
    std::vector<P> search() {
        if(surf) {
            std::vector<P> closed;
            // priority queue based on vector of paths
            // paths is vectors,
            //  which contains tuple of path (vector of P) and distance to finish (M).
            // Comparator == pathGT
            // initialized by
            //  object of pathGT
            //  empty vector of vectors of tuples in which contains vectors (of P) and M
            std::priority_queue<std::tuple<std::vector<P>, M>,
                std::vector<std::tuple<std::vector<P>, M>>, pathGT<P,M>>
                open(pathGT<P,M>(), std::vector<std::tuple<std::vector<P>, M>>(0));
            auto min = minPoint(surf->lookup());
            open.emplace(std::vector<P>(1, std::get<0>(min)), std::get<1>(min));
            while (!open.empty()) {
                auto path = std::move(open.top());
                open.pop();
                auto last = std::get<0>(path).back();
                bool check = false;
                for (auto& cur : closed) {
                    if (cur == last) {
                        check = true;
                        break;
                    }
                }
                if (check) {
                    continue;
                }
                closed.push_back(last);
                for (auto cur = std::get<0>(current).rbegin(); cur != std::get<0>(current).rend(); ++cur) {
                    surf->move(*cur);
                }
                for (auto cur = std::get<0>(path).begin(); cur != std::get<0>(path).end(); ++cur) {
                    surf->move(*cur);
                }
                current = std::move(path);
                std::vector<std::tuple<P, M>> successors = surf->lookup();
                for (auto&&i : std::move(successors)) {
                    if (std::get<1>(i) == M()) {
                        surf->move(std::get<0>(i));
                        std::get<0>(current).push_back(std::get<0>(i));
                        return std::get<0>(current); /// TODO check
                    }
                    auto buf = std::get<0>(current);
                    buf.push_back(std::get<0>(i));
                    open.emplace(buf, std::get<1>(i));
                }
            }
        }
        return std::vector<P>(0);
    }
};

}


#endif

#ifndef _SEARCHER_H_
#define _SEARCHER_H_
#include "Surface.h"
#include <unordered_map>
#include <queue>
#include <functional>
#include <ostream>

namespace SearcherSpace {

template<typename P, typename M>
struct pathGT{
    bool operator()(const std::tuple<std::vector<P>, M> &a,
                    const std::tuple<std::vector<P>, M> &b) {
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
    std::size_t _lim;
    Surface<P, M>* surf;
public:
    Searcher(std::size_t limit = std::numeric_limits<std::size_t>::max())
    : _lim( limit), surf( nullptr ) {}
    
    Searcher(Surface<P, M> &surface, std::size_t limit = std::numeric_limits<std::size_t>::max())
    : _lim( limit), surf(&surface ) {}
    
    Searcher(Surface<P, M> *surface, std::size_t limit = std::numeric_limits<std::size_t>::max())
    : _lim( limit), surf( surface ) {}

    void loadSurface(Surface<P, M> &surface) {
        surf    = &surface;
    }

    void loadSurface(Surface<P, M> *surface) {
        surf    = surface;
    }

    void loadLimit(std::size_t limit = std::numeric_limits<std::size_t>::max()) {
        _lim    = limit;
    }

    void reload(Surface<P, M> &surface, std::size_t limit = std::numeric_limits<std::size_t>::max()) {
        _lim    = limit;
        surf    = &surface;
    }

    void reload(Surface<P, M> *surface, std::size_t limit = std::numeric_limits<std::size_t>::max()) {
        _lim    = limit;
        surf    = surface;
    }


    std::vector<P> search() {
        std::tuple<std::vector<P>, M> current(std::vector<P>(0), M());
        if(surf) {
            std::vector<std::tuple<P, M>> successors = surf->lookup();
            if (!successors.empty()) {
                std::vector<P> closed;
                // priority queue based on vector of paths
                // paths is vectors,
                //  which contains tuple of path (vector of P) and distance to finish (M).
                // Comparator == pathGT
                // initialized by
                //  object of pathGT,
                //  empty vector of vectors of tuples in which contains vectors (of P) and M
                std::priority_queue<std::tuple<std::vector<P>, M>,
                std::vector<std::tuple<std::vector<P>, M>>, pathGT<P,M>>
                open(pathGT<P,M>(), std::vector<std::tuple<std::vector<P>, M>>(0));
                auto min = minPoint(successors);
                open.emplace(std::vector<P>(1, std::get<0>(min)), std::get<1>(min));
                while (!open.empty()) {
                    auto path = std::move(open.top());
                    open.pop();
                    if (std::get<1>(path) > _lim || std::get<0>(path).size() >= _lim) {
                        continue;
                    }
                    auto last = std::get<0>(path).back();
                    bool check = true;
                    for (auto& cur : closed) {
                        if (cur == last) {
                            check = false;
                            break;
                        }
                    }
                    if (check) {
                        // std::cout << "last: " << last << std::endl;
                        // std::cout << "backward" << std::endl;
                        closed.push_back(last);
                        for (auto cur = std::get<0>(current).rbegin(); cur < std::get<0>(current).rend(); ++cur) {
                            // std::cout << *cur << std::endl;
                            surf->move(*cur);
                        }
                        // std::cout << "forward" << std::endl;
                        for (auto cur = std::get<0>(path).begin(); cur < std::get<0>(path).end(); ++cur) {
                            // std::cout << *cur << std::endl;
                            surf->move(*cur);
                        }
                        // std::cout << "OK" << std::endl;
                        current = std::move(path);
                        successors = surf->lookup();
                        if (successors.empty()) {
                            continue;
                        }
                        for (auto& i : successors) {
                            if (std::get<1>(i) == M()) {
                                surf->move(std::get<0>(i));
                                std::get<0>(current).push_back(std::get<0>(i));
                                return std::get<0>(current);
                            }
                            auto buf = std::get<0>(current);
                            buf.push_back(std::get<0>(i));
                            open.emplace(buf, std::get<1>(i));
                        }
                    }
                }
            }
        }
        return std::vector<P>(0);
    }
};


}


#endif

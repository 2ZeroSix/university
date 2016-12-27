#include "Plane.h"

namespace SearcherSpace {

Plane::Plane  () noexcept
: TwoDimSurface() {}


Plane::Plane  (const std::vector<std::vector<dot>> &map) 
: TwoDimSurface( map) {}

Plane::Plane  (std::vector<std::vector<dot>> &&map)
: TwoDimSurface(std::move(map)) {}


std::vector<std::tuple<TwoDimPoint, std::size_t>> Plane::lookup() noexcept {
    std::vector<std::tuple<TwoDimPoint, std::size_t>> vec(0);
    if (!_map.empty()) {
        TwoDimPoint p;

        p.y = _cur.y;
        if (_cur.x > 0) {
            p.x = _cur.x  - 1;
            if (_map[p.y][p.x] != dot::block)
                vec.emplace_back(p, distance(p, _fin));
        }
        if (_cur.x < _map[0].size() - 1) {
            p.x = _cur.x  + 1;
            if (_map[p.y][p.x] != dot::block)
                vec.emplace_back(p, distance(p, _fin));
        }

        p.x = _cur.x;
        if (_cur.y > 0) {
            p.y = _cur.y  - 1;
            if (_map[p.y][p.x] != dot::block)
                vec.emplace_back(p, distance(p, _fin));
        }
        if (_cur.y < _map.size() - 1) {
            p.y = _cur.y  + 1;
            if (_map[p.y][p.x] != dot::block)
                vec.emplace_back(p, distance(p, _fin));
        }
    }
    return vec;
}

std::size_t Plane::distance(const TwoDimPoint &a, const TwoDimPoint &b) const noexcept {
    return (a.x > b.x ? a.x - b.x : b.x - a.x) + (a.y > b.y ? a.y - b.y : b.y - a.y);
}



}

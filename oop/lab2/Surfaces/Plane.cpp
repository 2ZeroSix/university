#include "Plane.h"

namespace SearcherSpace {

Plane::Plane  (std::size_t limit) noexcept
: TwoDimSurface( limit) {}


Plane::Plane  (const std::vector<std::vector<dot>> &map,
        std::size_t limit) noexcept
: TwoDimSurface(map, limit) {}

Plane::Plane  (std::vector<std::vector<dot>> &&map,
        std::size_t limit) noexcept
: TwoDimSurface(std::move(map), limit) {}


std::vector<std::tuple<TwoDimPoint, std::size_t>> Plane::lookup() noexcept {
    std::vector<std::tuple<TwoDimPoint, std::size_t>> vec;
    if (_cur.x > 0) {
        TwoDimPoint p;
        p.x = _cur.x  - 1;
        p.y = _cur.y;
        vec.emplace_back(p, distance(p, _fin));
    }
    if (_cur.x < _map[0].size() - 1) {
        TwoDimPoint p;
        p.x = _cur.x  + 1;
        p.y = _cur.y;
        vec.emplace_back(p, distance(p, _fin));
    }
    if (_cur.y > 0) {
        TwoDimPoint p;
        p.y = _cur.y  - 1;
        p.x = _cur.x;
        vec.emplace_back(p, distance(p, _fin));
    }
    if (_cur.y < _map[0].size() - 1) {
        TwoDimPoint p;
        p.y = _cur.y  + 1;
        p.x = _cur.x;
        vec.emplace_back(p, distance(p, _fin));
    }
    return vec;
}

std::size_t Plane::distance(const TwoDimPoint &a, const TwoDimPoint &b) const noexcept {
    return (a.x > b.x ? a.x - b.x : b.x - a.x) + (a.y > b.y ? a.y - b.y : b.y - a.y);
}



}

#include "Cylinder.h"

namespace SearcherSpace {

Cylinder::Cylinder  () noexcept
: TwoDimSurface( ) {}


Cylinder::Cylinder  (const std::vector<std::vector<dot>> &map) 
: TwoDimSurface(map) {}

Cylinder::Cylinder  (std::vector<std::vector<dot>> &&map) 
: TwoDimSurface(std::move(map)) {}


std::vector<std::tuple<TwoDimPoint, std::size_t>> Cylinder::lookup() noexcept {
    std::vector<std::tuple<TwoDimPoint, std::size_t>> vec;
    if (!_map.empty()) {
        TwoDimPoint p;

        p.y = _cur.y;
        p.x = (_map[0].size() + _cur.x  - 1)    % _map[0].size();
        if (_map[p.y][p.x] != dot::block)
            vec.emplace_back(p, distance(p, _fin));
        p.x = (_cur.x  + 1)                     % _map[0].size();
        if (_map[p.y][p.x] != dot::block)
            vec.emplace_back(p, distance(p, _fin));

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

std::size_t Cylinder::distance(const TwoDimPoint &a, const TwoDimPoint &b) const noexcept {
    return  std::min((a.x > b.x ? a.x - b.x : b.x - a.x),
                     (a.x < b.x ? _map[0].size() + a.x - b.x : _map[0].size() + b.x - a.x))
            + (a.y > b.y ? a.y - b.y : b.y - a.y);
}


}

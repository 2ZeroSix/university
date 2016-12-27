#include "Torus.h"

namespace SearcherSpace {

Torus::Torus  () noexcept
: TwoDimSurface() {}


Torus::Torus  (const std::vector<std::vector<dot>> &map) 
: TwoDimSurface(map) {}

Torus::Torus  (std::vector<std::vector<dot>> &&map) 
: TwoDimSurface(std::move(map)) {}


std::vector<std::tuple<TwoDimPoint, std::size_t>> Torus::lookup() noexcept {
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
        p.y =  (_map.size() + _cur.y  - 1)      % _map.size();
        if (_map[p.y][p.x] != dot::block)
            vec.emplace_back(p, distance(p, _fin));
        p.y = (_cur.y  + 1)                     % _map.size();
        if (_map[p.y][p.x] != dot::block)
            vec.emplace_back(p, distance(p, _fin));
    }
    return vec;
}

std::size_t Torus::distance(const TwoDimPoint &a, const TwoDimPoint &b) const noexcept {
    return  std::min((a.x > b.x ? a.x - b.x : b.x - a.x),
                     (a.x < b.x ? _map[0].size() + a.x - b.x : _map[0].size() + b.x - a.x))
            +
            std::min((a.y > b.y ? a.y - b.y : b.y - a.y),
                     (a.y < b.y ? _map.size() + a.y - b.y : _map.size() + b.y - a.y));
}


}

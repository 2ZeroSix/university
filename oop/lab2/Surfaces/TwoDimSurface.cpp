#include "TwoDimSurface.h"

namespace SearcherSpace {

bool TwoDimPoint::operator==(const TwoDimPoint& other) const {
    return (x == other.x) && (y == other.y);
}
bool TwoDimPoint::operator!=(const TwoDimPoint& other) const {
    return !(*this == other);
}


TwoDimSurface::dot intToDot(int ch) {
    TwoDimSurface::dot point;
    switch(ch) {
        case '#':
            point = TwoDimSurface::dot::block;
            break;
        case '.':
            point = TwoDimSurface::dot::free;
            break;
        case '*':
            point = TwoDimSurface::dot::passed;
            break;
        case 'S':
            point = TwoDimSurface::dot::start;
            break;
        case 'F':
            point = TwoDimSurface::dot::finish;
            break;
        default:
            throw std::invalid_argument("unknown intToDot");
    }
    return point;
}
char dotToChar(TwoDimSurface::dot point) {
    char ch;;
    switch(point) {
        case TwoDimSurface::dot::block:
            ch = '#';
            break;
        case TwoDimSurface::dot::free:
            ch = '.';
            break;
        case TwoDimSurface::dot::passed:
            ch = '*';
            break;
        case TwoDimSurface::dot::start:
            ch = 'S';
            break;
        case TwoDimSurface::dot::finish:
            ch = 'F';
            break;
        default:
            throw std::invalid_argument("unknown dotToChar");
    }
    return ch;
}


std::istream &operator>>(std::istream &is, TwoDimSurface::dot &point) {
    point = intToDot(is.get());
    return is;
}

std::istream &operator>>(std::istream &is, TwoDimSurface &surf) {
    std::size_t i = 0;
    while (is.good()) {
        std::string str;
        getline(is, str);
        surf._map.emplace_back(str.size());
        for (std::size_t j = 0; j < surf._map[i].size(); ++j) {
            surf._map[i][j] = intToDot(str[j]);
        }
        ++i;
    }
    surf.findDots();
    return is;
}

std::ostream &operator<<(std::ostream &os, TwoDimSurface::dot &point) {
    os << dotToChar(point);
    return os;
}

std::ostream &operator<<(std::ostream &os, TwoDimSurface &surf) {
    for (auto& vec : surf._map) {
        for (auto& cur : vec)
            os << cur;
        os << std::endl;
    }
    return os;
}



TwoDimSurface::TwoDimSurface(std::size_t limit) noexcept
: _lim( limit) {}

TwoDimSurface::TwoDimSurface(const TwoDimSurface &field) noexcept
: _cur(field._cur), _fin(field._fin), _map(field._map), _lim(field._lim) {}
TwoDimSurface::TwoDimSurface(TwoDimSurface &&field) noexcept
: _cur(std::move(field._cur)), _fin(std::move(field._fin)),
    _map(std::move(field._map)), _lim(std::move(field._lim)) {}

TwoDimSurface::TwoDimSurface(const TwoDimPoint &beg, const TwoDimPoint &end, 
                             const std::vector<std::vector<dot>> &map,
                             std::size_t limit) noexcept
: _cur( beg), _fin(end), _map(map), _lim(limit) {
    initMap(beg, end);
}
TwoDimSurface::TwoDimSurface(const TwoDimPoint &beg, const TwoDimPoint &end, 
                             std::vector<std::vector<dot>> &&map,
                             std::size_t limit) noexcept
: _cur( beg), _fin(end), _map(std::move(map)), _lim(limit) {
    initMap(beg, end);
}

TwoDimSurface::TwoDimSurface(const std::vector<std::vector<dot>> &map,
                             std::size_t limit)noexcept
: _map( map), _lim(limit) {
    findDots();
}
TwoDimSurface::TwoDimSurface(std::vector<std::vector<dot>> &&map,
                             std::size_t limit)noexcept
: _map( std::move(map)), _lim(limit) {
    findDots();
}


std::size_t TwoDimSurface::move(TwoDimPoint point) throw (BadMove){
    if( distance(_cur, point)   >  1            ||
        _map.size()             <= point.y      ||
        _map[point.y].size()    <= point.x      ||
        _map[point.y][point.x]  == dot::block   ){
        throw BadMove();
    }
    _cur.x = point.x;
    _cur.y = point.y;
}


void TwoDimSurface::initMap(const TwoDimPoint &beg, const TwoDimPoint &end) {
    for(auto& vec: _map) {
        for(auto& cur: vec) {
            if (cur != dot::block) {
                cur = dot::free;
            }
        }
    }
    _map[_cur.y][_cur.x] = dot::start;
    _map[_fin.y][_fin.x] = dot::finish;
}

void TwoDimSurface::drawPath(const std::vector<TwoDimPoint> &path){
    for(auto cur = path.rbegin() + 1; cur < path.rend(); ++cur) {
        if (_map[cur->y][cur->x] == dot::start) {
            break;
        }
        _map[cur->y][cur->x] = dot::passed;
    }
}

void TwoDimSurface::findDots() {
    size_t rows = _map.size();
    size_t colons = _map[0].size();
    size_t counters = 0;
    size_t counterf = 0;
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < colons; ++j) {
            if (_map[i][j] == dot::start) {
                if(counters) {
                    _map[i][j] = dot::free;
                    continue;
                }
                _cur.y = i;
                _cur.x = j;
                ++counters;
            }
            if (_map[i][j] == dot::finish) {
                if(counterf) {
                    _map[i][j] = dot::free;
                    continue;
                }
                _fin.y = i;
                _fin.x = j;
                ++counterf;
            }
        }
    }
}


}
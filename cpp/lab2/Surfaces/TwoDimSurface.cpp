#include "TwoDimSurface.h"

namespace SearcherSpace {

bool TwoDimPoint::operator==(const TwoDimPoint& other) const {
    return (x == other.x) && (y == other.y);
}
bool TwoDimPoint::operator!=(const TwoDimPoint& other) const {
    return !(*this == other);
}


TwoDimSurface::dot intToDot(int ch) {
    TwoDimSurface::dot dot;
    switch(ch) {
        case '#':
            dot = TwoDimSurface::dot::block;
            break;
        case '.':
            dot = TwoDimSurface::dot::free;
            break;
        case '*':
            dot = TwoDimSurface::dot::passed;
            break;
        case 'S':
            dot = TwoDimSurface::dot::start;
            break;
        case 'F':
            dot = TwoDimSurface::dot::finish;
            break;
        default:
            throw std::invalid_argument("unknown intToDot");
    }
    return dot;
}
char dotToChar(TwoDimSurface::dot dot) {
    char ch;;
    switch(dot) {
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


std::istream &operator>>(std::istream &is, TwoDimSurface::dot &dot) {
    dot = intToDot(is.get());
    return is;
}

std::istream &operator>>(std::istream &is, TwoDimSurface &surf) {
    std::size_t i = 0;
    while (is.good()) {
        std::string str;
        getline(is, str);
        if (str.empty()) {
            throw std::invalid_argument("can't read map");
        }
        surf._map.emplace_back(str.size());
        for (std::size_t j = 0; j < surf._map[i].size(); ++j) {
            surf._map[i][j] = intToDot(str[j]);
        }
        ++i;
    }
    surf.findDots();
    return is;
}

std::ostream &operator<<(std::ostream &os, const TwoDimSurface::dot &dot) {
    os << dotToChar(dot);
    return os;
}

std::ostream &operator<<(std::ostream &os, const TwoDimSurface &surf) {
    for (auto& vec : surf._map) {
        for (auto& cur : vec)
            os << cur;
        os << std::endl;
    }
    return os;
}



TwoDimSurface::TwoDimSurface() noexcept{}

TwoDimSurface::TwoDimSurface(const TwoDimSurface &field) noexcept
: _cur(field._cur), _fin(field._fin), _map(field._map) {}
TwoDimSurface::TwoDimSurface(TwoDimSurface &&field) noexcept
: _cur(std::move(field._cur)), _fin(std::move(field._fin)),
    _map(std::move(field._map)) {}

TwoDimSurface::TwoDimSurface(const TwoDimPoint &beg, const TwoDimPoint &end, 
                             const std::vector<std::vector<dot>> &map)
: _cur( beg), _fin(end), _map(map) {
    initMap(beg, end);
}
TwoDimSurface::TwoDimSurface(const TwoDimPoint &beg, const TwoDimPoint &end, 
                             std::vector<std::vector<dot>> &&map)
: _cur( beg), _fin(end), _map(std::move(map)){
    initMap(beg, end);
}

TwoDimSurface::TwoDimSurface(const std::vector<std::vector<dot>> &map)
: _map( map){
    findDots();
}
TwoDimSurface::TwoDimSurface(std::vector<std::vector<dot>> &&map)
: _map( std::move(map)) {
    findDots();
}


std::size_t TwoDimSurface::move(TwoDimPoint point) throw (BadMove){
    if( distance(_cur, point)   >  1            ||
        _map.size()             <= point.y      ||
        _map[point.y].size()    <= point.x      ||
        _map[point.y][point.x]  == dot::block   ){
        throw BadMove();
    }
    // switch (_map[point.y][point.x]) {
    //     case dot::passed:
    //         _map[point.y][point.x] = dot::free;
    //         break;
    //     case dot::free:
    //         _map[point.y][point.x] = dot::passed;
    //         break;
    //     default:
    //         break;
    // }
    _cur.y = point.y;
    _cur.x = point.x;
    return distance(_cur, _fin);
}


void TwoDimSurface::initMap(const TwoDimPoint &beg, const TwoDimPoint &end) {
    for(auto& vec: _map) {
        for(auto& cur: vec) {
            if (cur != dot::block) {
                cur = dot::free;
            }
        }
    }
    _cur = beg;
    _fin = end;
    _map[_cur.y][_cur.x] = dot::start;
    _map[_fin.y][_fin.x] = dot::finish;
}

void TwoDimSurface::drawPath(const std::vector<TwoDimPoint> &path){
    for(auto cur = path.rbegin(); cur < path.rend(); ++cur) {
        if (_map[cur->y][cur->x] == dot::start) {
            break;
        }
        if (_map[cur->y][cur->x] == dot::finish) {
            continue;
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
        if(_map[i].size() != colons) {
            throw std::invalid_argument("map must have equal number of colons");
        }
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
#include "WordSurface.h"

namespace SearcherSpace {

std::istream &operator>>(std::istream &is, WordSurface &surf) {
    is >> surf._cur;
    surf._strt = surf._cur;
    surf._map[surf._cur] = WordSurface::dot::start;
    is >> surf._fin;
    surf._map[surf._fin] = WordSurface::dot::finish;
    std::string str;
    while (is.good()) {
        is >> str;
        surf._map[str] = WordSurface::dot::free;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const WordSurface &surf) {
    os << surf._strt << std::endl;
    for (auto& cur : surf.path) {
        os << cur << std::endl;
    }
    return os;
}



WordSurface::WordSurface() noexcept{}

WordSurface::WordSurface(const WordSurface &field) noexcept
: _strt(field._strt), _cur(field._cur), _fin(field._fin), _map(field._map) {}
WordSurface::WordSurface(WordSurface &&field) noexcept
: _strt(std::move(field._strt)), _cur(std::move(field._cur)), _fin(std::move(field._fin)),
    _map(std::move(field._map)) {}

WordSurface::WordSurface(const WordPoint &beg, const WordPoint &end, 
                             const std::unordered_map<std::string, dot> &map)
: _strt( beg), _cur(beg), _fin(end), _map(map) {
    initMap(beg, end);
}
WordSurface::WordSurface(const WordPoint &beg, const WordPoint &end, 
                             std::unordered_map<std::string, dot> &&map) 
: _strt( beg), _cur( beg), _fin(end), _map(std::move(map)){
    initMap(beg, end);
}

WordSurface::WordSurface(const std::unordered_map<std::string, dot> &map)
: _map( map){
    findDots();
}
WordSurface::WordSurface(std::unordered_map<std::string, dot> &&map)
: _map( std::move(map)) {
    findDots();
}


std::size_t WordSurface::move(WordPoint point) throw (BadMove){
    if( distance(_cur, point)   >  1    ||
        _map.find(point) == _map.end()  ){
        std::cout << "bad point: " << point << std::endl;
        throw BadMove();
    }
    _cur = point;
    return distance(_cur, _fin);
}

std::vector<std::tuple<WordPoint, std::size_t>> WordSurface::lookup() {
    std::vector<std::tuple<WordPoint, std::size_t>> vec(0);
    for (auto& cur : _map) {
        if (distance(_cur, cur.first) == 1) {
            vec.push_back(make_tuple(cur.first, distance(cur.first, _fin)));
        }
    }
    return vec;
}


void WordSurface::initMap(const WordPoint &beg, const WordPoint &end) {
    for(auto& cur: _map) {
        cur.second = dot::free;
    }
    _strt   = beg;
    _cur    = beg;
    _fin    = end;
    _map[_cur] = dot::start;
    _map[_fin] = dot::finish;
}

void WordSurface::drawPath(const std::vector<WordPoint> &path){
    this->path = path;
}

void WordSurface::findDots() {
    size_t counters = 0;
    size_t counterf = 0;
    for (auto& cur : _map) {
        if(cur.second == dot::start) {
            if(counters) {
                cur.second = dot::free;
            }
            _strt = cur.first;
            _cur = cur.first;
            ++counters;
        }
        if(cur.second == dot::finish) {
            if(counterf) {
                cur.second = dot::free;
            }
            _fin = cur.first;
            ++counterf;
        }
    }
}

std::size_t WordSurface::distance(const WordPoint &s1, const WordPoint &s2)  const noexcept {
    std::size_t s1len = s1.size();
    std::size_t s2len = s2.size();
    
    auto column_start = (decltype(s1len))1;
    
    auto column = new decltype(s1len)[s1len + 1];
    std::iota(column + column_start, column + s1len + 1, column_start);
    
    for (auto x = column_start; x <= s2len; x++) {
        column[0] = x;
        auto last_diagonal = x - column_start;
        for (auto y = column_start; y <= s1len; y++) {
            auto old_diagonal = column[y];
            auto possibilities = {
                column[y] + 1,
                column[y - 1] + 1,
                last_diagonal + (s1[y - 1] == s2[x - 1]? 0 : 1)
            };
            column[y] = std::min(possibilities);
            last_diagonal = old_diagonal;
        }
    }
    auto result = column[s1len];
    delete[] column;
    return result;
}


}
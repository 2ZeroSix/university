#include "Searcher.h"
typedef unsigned int uint;

struct Point{
    uint x;
    uint y;
};

class PlainSurface : public Surface<Point, uint> {
public:
    PlainSurface(Point start, Point end)
        : _cur(start), _end(end) {}
    virtual move(Point point) {
        if (metric(_cur, point) == 1) {
            _cur = point;
        }
        else {
            throw BadMove;
        }
        return metric(_cur, _end);
    }
    virtual std::vector<std::tuple<Point, uint>> lookup() {
        std::vector<std::tuple<P, M>> vec(9);
        
    }
private:
    uint metric(Point first, Point second) {
        return abs(first.x - second.x) + abs(first.y - second.y);
    }
    Point _cur;
    Point _end;
};

int main() {
}
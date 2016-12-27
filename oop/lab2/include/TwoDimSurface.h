#ifndef _TWODIMSURFACE_H_
#define _TWODIMSURFACE_H_
#include "Surface.h"
#include <iostream>
#include <stdexcept>

namespace SearcherSpace {


struct TwoDimPoint {
    bool operator==(const TwoDimPoint& other) const;
    bool operator!=(const TwoDimPoint& other) const;
    friend std::ostream &operator<<(std::ostream& os, const TwoDimPoint& point) {
        return os << "x: " << point.x << " y: " << point.y << std::endl;
    }
    std::size_t x, y;
};

class TwoDimSurface : public Surface<TwoDimPoint, std::size_t> {
public:
    enum class dot : uchar {block, free, passed, start, finish};

    TwoDimSurface  ()                                                           noexcept;

    TwoDimSurface  (const TwoDimSurface &field)                                 noexcept;
    TwoDimSurface  (TwoDimSurface &&field)                                      noexcept;

    TwoDimSurface  (const TwoDimPoint &beg, const TwoDimPoint &end,
                    const std::vector<std::vector<dot>> &map);
    TwoDimSurface  (const TwoDimPoint &beg, const TwoDimPoint &end,
                    std::vector<std::vector<dot>> &&map);

    TwoDimSurface  (const std::vector<std::vector<dot>> &map);
    TwoDimSurface  (std::vector<std::vector<dot>> &&map);

    virtual std::size_t move(TwoDimPoint point)                                 throw(BadMove) final;

    void initMap(const TwoDimPoint &beg, const TwoDimPoint &end);

    void drawPath(const std::vector<TwoDimPoint> &path);
    
    friend std::istream &operator>>(std::istream &is, TwoDimSurface &surf);
    friend std::ostream &operator<<(std::ostream &os, const TwoDimSurface &surf);
protected:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)    const noexcept = 0;
    TwoDimPoint _cur;
    TwoDimPoint _fin;
    std::vector< std::vector< dot > > _map;
    void findDots();
};


TwoDimSurface::dot intToDot(int ch);
char dotToChar(TwoDimSurface::dot dot);
std::istream &operator>>(std::istream &is, TwoDimSurface::dot &dot);
std::ostream &operator<<(std::ostream &os, const TwoDimSurface::dot &dot);


}


#endif

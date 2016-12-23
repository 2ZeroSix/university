#ifndef _TWODIMSURFACE_H_
#define _TWODIMSURFACE_H_
#include "Surface.h"
#include <limits>
#include <iostream>
#include <stdexcept>

namespace SearcherSpace {


struct TwoDimPoint {std::size_t x, y;};

class TwoDimSurface : public Surface<TwoDimPoint, std::size_t> {
public:
    enum class dot : uchar {block, free, passed, start, finish};

    TwoDimSurface  (std::size_t limit = std::numeric_limits<std::size_t>::max())            noexcept;

    TwoDimSurface  (const TwoDimSurface &field)                                             noexcept;
    TwoDimSurface  (TwoDimSurface &&field)                                                  noexcept;

    TwoDimSurface  (const TwoDimPoint &beg, const TwoDimPoint &end,
                    const std::vector<std::vector<dot>> &map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max())            noexcept;
    TwoDimSurface  (const TwoDimPoint &beg, const TwoDimPoint &end,
                    std::vector<std::vector<dot>> &&map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max())            noexcept;

    TwoDimSurface  (const std::vector<std::vector<dot>> &map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max())            noexcept;
    TwoDimSurface  (std::vector<std::vector<dot>> &&map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max())            noexcept;

    virtual std::size_t move(TwoDimPoint point)                             throw (BadMove) final;

    void initMap(const TwoDimPoint &beg, const TwoDimPoint &end);
    
    friend std::istream &operator>>(std::istream &is, TwoDimSurface &surf);
    friend std::ostream &operator<<(std::ostream &os, TwoDimSurface &surf);
protected:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)      const noexcept = 0;
    TwoDimPoint _cur;
    TwoDimPoint _fin;
    std::vector< std::vector< dot > > _map;
    std::size_t _lim;
    void findDots();
};


TwoDimSurface::dot intToDot(int ch);
char dotToChar(TwoDimSurface::dot point);
std::istream &operator>>(std::istream &is, TwoDimSurface::dot &point);
std::ostream &operator<<(std::ostream &os, TwoDimSurface::dot &point);


}


#endif

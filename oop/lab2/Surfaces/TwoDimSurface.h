#ifndef _TWODIMSURFACE_H_
#define _TWODIMSURFACE_H_
#include "Surface.h"
#include <limits>


namespace SearcherSpace {


struct TwoDimPoint {std::size_t x, y;};
class TwoDimSurface : Surface<TwoDimPoint, std::size_t> {
public:
    enum class dot : uchar {block, free, passed, start, finish};
    TwoDimSurface  (std::size_t limit = std::numeric_limits<std::size_t>::max());
    TwoDimSurface  (const TwoDimSurface &field);
    TwoDimSurface  (TwoDimSurface &&field);
    TwoDimSurface  (TwoDimPoint beg, TwoDimPoint end, 
                    const std::vector<std::vector<dot>> &map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max());
    TwoDimSurface  (TwoDimPoint beg, TwoDimPoint end, 
                    std::vector<std::vector<dot>> &&map,
                    std::size_t limit = std::numeric_limits<std::size_t>::max());
    void init(TwoDimPoint beg, TwoDimPoint end, const std::vector<std::vector<dot>>& map);
    void init(TwoDimPoint beg, TwoDimPoint end, std::vector<std::vector<dot>>&& map);
    virtual M move(P point)  override throw (BadMove);
    virtual std::vector<std::tuple<P, M>> lookup() override noexcept;
private:
    TwoDimPoint current, start, finish;
    std::vector< std::vector< dot > > map;
    std::size_t limit;
};


}


#endif

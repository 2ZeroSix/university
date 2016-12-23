#ifndef _PLANE_H_
#define _PLANE_H_
#include "TwoDimSurface.h"


namespace SearcherSpace {

class Plane : public TwoDimSurface {
public:
    Plane  (std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    Plane  (const std::vector<std::vector<dot>> &map,
            std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    Plane  (std::vector<std::vector<dot>> &&map,
            std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    virtual std::vector<std::tuple<TwoDimPoint, std::size_t>> lookup()      noexcept override;
private:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)const noexcept override;
};


}


#endif

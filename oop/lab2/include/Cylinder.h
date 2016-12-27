#ifndef _CYLINDER_H_
#define _CYLINDER_H_
#include "TwoDimSurface.h"


namespace SearcherSpace {

class Cylinder : public TwoDimSurface {
public:
    Cylinder  (std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    Cylinder  (const std::vector<std::vector<dot>> &map,
            std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    Cylinder  (std::vector<std::vector<dot>> &&map,
            std::size_t limit = std::numeric_limits<std::size_t>::max())    noexcept;
    virtual std::vector<std::tuple<TwoDimPoint, std::size_t>> lookup()      noexcept override;
private:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)const noexcept override;
};


}


#endif

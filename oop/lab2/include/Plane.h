#ifndef _PLANE_H_
#define _PLANE_H_
#include "TwoDimSurface.h"


namespace SearcherSpace {

class Plane : public TwoDimSurface {
public:
    Plane  ()    noexcept;
    Plane  (const std::vector<std::vector<dot>> &map);
    Plane  (std::vector<std::vector<dot>> &&map);
    virtual std::vector<std::tuple<TwoDimPoint, std::size_t>> lookup()      noexcept override;
private:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)const noexcept override;
};


}


#endif

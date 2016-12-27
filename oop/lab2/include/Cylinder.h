#ifndef _CYLINDER_H_
#define _CYLINDER_H_
#include "TwoDimSurface.h"


namespace SearcherSpace {

class Cylinder : public TwoDimSurface {
public:
    Cylinder  ()    noexcept;
    Cylinder  (const std::vector<std::vector<dot>> &map);
    Cylinder  (std::vector<std::vector<dot>> &&map);
    virtual std::vector<std::tuple<TwoDimPoint, std::size_t>> lookup()      noexcept override;
private:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)const noexcept override;
};


}


#endif

#ifndef _TORUS_H_
#define _TORUS_H_
#include "TwoDimSurface.h"


namespace SearcherSpace {

class Torus : public TwoDimSurface {
public:
    Torus  ()    noexcept;
    Torus  (const std::vector<std::vector<dot>> &map);
    Torus  (std::vector<std::vector<dot>> &&map);
    virtual std::vector<std::tuple<TwoDimPoint, std::size_t>> lookup()      noexcept override;
private:
    virtual std::size_t distance(const TwoDimPoint &a, const TwoDimPoint &b)const noexcept override;
};


}


#endif

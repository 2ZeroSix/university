#include "TwoDimSurface.h"

using namespace SearcherSpace;
using namespace std;

TwoDimSurface::TwoDimSurface(std::size_t limit) : limit(limit){}
TwoDimSurface::TwoDimSurface(const TwoDimSurface &field)
    : current(field.current), start(field.start),
      finish(field.finish), map(field.map), limit(field.limit){}
TwoDimSurface::TwoDimSurface(TwoDimSurface &&field)
    : current(std::move(field.current)), start(std::move(field.start)),
      finish(std::move(field.finish)), map(std::move(field.map)), limit(std::move(field.limit)) {}



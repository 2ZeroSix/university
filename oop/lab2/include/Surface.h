#ifndef _SURFACE_H_
#define _SURFACE_H_
#include <exception>
#include <vector>
#include <tuple>
#include <cstddef>
#include <utility>
#include <algorithm>


namespace SearcherSpace {


typedef unsigned int uint;
typedef unsigned char uchar;
class BadMove : public std::exception {};

template<typename P, typename M>
class Surface{
public:
    typedef P PointType;
    typedef M MetricType;
    /**
     * Продвигает в новую соседнюю точку и возвращает
     * расстояние до цели в новой точке
     */
    virtual M move(P point) throw (BadMove) = 0;
    /**
     * Расстояние до цели для соседних точек
     * в которые возможно перемещение
     */
    virtual std::vector<std::tuple<P, M>> lookup() = 0;
};


}


#endif

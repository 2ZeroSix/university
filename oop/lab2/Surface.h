#ifndef _SURFACE_H_
#define _SURFACE_H_
#include <exception>
#include <vector>
#include <tuple>
typedef unsigned int uint;

class BadMove : public std::exception {};
/**
 * P - тип точки в пространстве
 * M - метрика пространства
 */
template<typename P, typename M>
class Surface{
public:
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

#endif

#ifndef _WORDSURFACE_H_
#define _WORDSURFACE_H_
#include "Surface.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>


namespace SearcherSpace {


typedef std::string WordPoint;
class WordSurface : public Surface<WordPoint, std::size_t> {
public:
    enum class dot : uchar {free, start, finish};

    WordSurface  ()                                                             noexcept;

    WordSurface  (const WordSurface &field)                                     noexcept;
    WordSurface  (WordSurface &&field)                                          noexcept;

    WordSurface  (const WordPoint &beg, const WordPoint &end,
                    const std::unordered_map<WordPoint, dot> &map);
    WordSurface  (const WordPoint &beg, const WordPoint &end,
                    std::unordered_map<WordPoint, dot> &&map);

    WordSurface  (const std::unordered_map<WordPoint, dot> &map);
    WordSurface  (std::unordered_map<WordPoint, dot> &&map);

    virtual std::size_t move(WordPoint point)                       throw(BadMove) final;
    virtual std::vector<std::tuple<WordPoint, std::size_t>> lookup()               final;

    void initMap(const WordPoint &beg, const WordPoint &end);

    void drawPath(const std::vector<WordPoint> &path);
    
    friend std::istream &operator>>(std::istream &is, WordSurface &surf);
    friend std::ostream &operator<<(std::ostream &os, const WordSurface &surf);
protected:
    virtual std::size_t distance(const WordPoint &a, const WordPoint &b)  const noexcept;
    WordPoint _strt;
    WordPoint _cur;
    WordPoint _fin;
    std::unordered_map<WordPoint, dot> _map;
    std::vector<WordPoint> path;
    void findDots();
};


}


#endif

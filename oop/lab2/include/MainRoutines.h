#ifndef _MAIN_ROUTINES_
#define _MAIN_ROUTINES_

#include <iostream>
#include <algorithm>
#include <utility>
#include "Searcher.h"
#include "Plane.h"
#include "Torus.h"
#include "Cylinder.h"
#include "WordSurface.h"
#include "anyoption.h"

enum LabyrinthErrors {helperr=1, spaceerr=2, routeerr=4, limiterr=8, topologyerr=16, solveerr=32};

std::pair< int, std::tuple< std::string, std::string, std::size_t, std::string > > parser(int argc, char** argv);

template<typename Surface>
int readSolvePrintLabyrinth(const std::string &space, const std::string& out, std::size_t limit) {
    std::ifstream is(space);
    Surface surf;
    is >> surf;
    is.close();
    SearcherSpace::Searcher<typename Surface::PointType, typename Surface::MetricType> robot(surf, limit);
    auto path = robot.search();
    surf.drawPath(path);
    std::ofstream os(out);
    os << surf;
    return path.empty() ? solveerr : 0;    
}

int solveAnyLabyrinth(const std::string &space, const std::string& out, std::size_t limit, const std::string topology);

void printErrors(int errs);

#endif
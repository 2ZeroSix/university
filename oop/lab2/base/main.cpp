#include <iostream>
#include <algorithm>
#include <utility>
#include "Searcher.h"
#include "Plane.h"
#include "Torus.h"
#include "Cylinder.h"
#include "WordSurface.h"
#include "anyoption.h"


using namespace std;
using namespace SearcherSpace;

enum LabyrinthErrors {helperr=1, spaceerr=2, routeerr=4, limiterr=8, topologyerr=16, solveerr=32};
const std::string LabyrinthErrorsInfo[] = {"", "Can't open input file", "Can't open output file",
                                        "Bad limit", "Unknown topology", "Can't solve labyrinth"};
AnyOption opt[1];
std::pair< int, std::tuple<std::string, std::string, std::size_t, std::string> > parser(int argc, char** argv) {
    std::string space = "space.txt", out = "route.txt", topology = "plane";
    std::size_t limit = 1000;

    opt->addUsage( "Usage: " );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help                 Prints this help " );
    opt->addUsage( " -s  --space space.txt      File with space description " );
    opt->addUsage( " -o  --out   route.txt      Output file " );
    opt->addUsage( " -l  --limit 1000           Max length of path " );
    opt->addUsage( " -t  --topology plane       Type of topology " );
    
    opt->setFlag("help",        'h');
    opt->setOption("space",     's');
    opt->setOption("out",       'o');
    opt->setOption("limit",     'l');
    opt->setOption("topology",  't');

    opt->processCommandArgs(argc, argv);
    int errCounter = 0;
    char *arg;
    if(opt->getFlag("help") || opt->getFlag('h')){
        opt->printUsage();
        return make_pair(helperr, make_tuple(space, out, limit, topology));
    }
    if((arg = opt->getValue('s')) != nullptr ||  (arg = opt->getValue("space")) != nullptr) {
        space = arg;
    }
    if((arg = opt->getValue('o')) != nullptr ||  (arg = opt->getValue("out")) != nullptr) {
        out = arg;
    }
    if((arg = opt->getValue('l')) != nullptr ||  (arg = opt->getValue("limit")) != nullptr) {
        try {
            if(sizeof(limit) == sizeof(unsigned long long))
                limit = stoull(arg);
            else 
                limit = stoul(arg);
            if (arg[0] == '-') throw std::invalid_argument("negative limit");
        }
        catch (std::invalid_argument) {
            errCounter |= limiterr;
        }
    }
    if((arg = opt->getValue('t')) != nullptr ||  (arg = opt->getValue("topology")) != nullptr) {
        topology = arg;
        std::transform(topology.begin(), topology.end(), topology.begin(), ::tolower);
    }
    if (!std::ifstream(space)) {
        errCounter |= spaceerr;
    }
    if (!std::ofstream(out)) {
        errCounter |= routeerr;
    }
    return make_pair(errCounter, make_tuple(space, out, limit, topology));
}

template<typename Surface>
int readSolvePrintLabyrinth(const std::string &space, const std::string& out, std::size_t limit) {
    std::ifstream is(space);
    std::ofstream os(out);
    Surface surf;
    is >> surf;
    Searcher<typename Surface::PointType, typename Surface::MetricType> robot(surf, limit);
    auto path = robot.search();
    surf.drawPath(path);
    os << surf;
    return path.empty() ? solveerr : 0;    
}

int solveAnyLabyrinth(const std::string &space, const std::string& out, std::size_t limit, const std::string topology) {
    if (topology == "plane") {
        return readSolvePrintLabyrinth<Plane>       (space,out, limit);
    }
    else if (topology == "cylinder") {
        return readSolvePrintLabyrinth<Cylinder>    (space,out, limit);
    }
    else if (topology == "torus") {
        return readSolvePrintLabyrinth<Torus>       (space,out, limit);
    }
    else if (topology == "wordsurface") {
        return readSolvePrintLabyrinth<WordSurface> (space,out, limit);
    }
    else {
        return topologyerr; 
    }
}

int printErrors(int errs) {
    int i = 1;
    bool check = false;
    for (auto& cur : LabyrinthErrorsInfo) {
        if (errs & i) {
            if (i != 32) check = true;
            cout << cur << endl;
        }
        i <<= 1;
    }
    if (check) opt->printUsage();
    return errs;
}

int main(int argc, char *argv[]) {
    auto bufargs = parser(argc, argv);
    int errs = bufargs.first;
    if(!errs) {
        auto args = std::move(bufargs.second);
        errs |= solveAnyLabyrinth(get<0>(args), get<1>(args), get<2>(args), get<3>(args));
    }
    return printErrors(errs);
}
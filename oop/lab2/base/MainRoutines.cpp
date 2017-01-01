#include "MainRoutines.h"

using namespace SearcherSpace;

namespace {
    const std::string LabyrinthErrorsInfo[] = {"", "Can't open input file", "Can't open output file",
                                            "Bad limit", "Unknown topology", "Can't solve labyrinth"};
    AnyOption opt[1];
}
std::pair< int, std::tuple<std::string, std::string, std::size_t, std::string> > parser(int argc, char** argv) {
    std::string space = "space.txt", out = "route.txt", topology = "plane";
    std::size_t limit = 1000;

    opt->addUsage( "Usage (with values by default): " );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help             Prints this help " );
    opt->addUsage( " -s  --space space.txt  File with space description " );
    opt->addUsage( " -o  --out   route.txt  Output file " );
    opt->addUsage( " -l  --limit 1000       Max length of path " );
    opt->addUsage( "                        l > 0 " );
    opt->addUsage( " -t  --topology plane   Type of topology " );
    opt->addUsage( "                        {plane, cylinder, torus, wordsurface} " );
    
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
    if (!std::ofstream(out, ios_base::app)) {
        errCounter |= routeerr;
    }
    return make_pair(errCounter, make_tuple(space, out, limit, topology));
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

void printErrors(int errs) {
    int i = 1;
    bool check = false;
    for (auto& cur : LabyrinthErrorsInfo) {
        if (errs & i) {
            if (i != 32) check = true;
            cout << "error: " << cur << endl;
        }
        i <<= 1;
    }
    if (check) opt->printUsage();
}

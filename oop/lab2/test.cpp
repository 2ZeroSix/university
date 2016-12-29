#include <iostream>
#include "Plane.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Searcher.h"
#include "anyoption.h"

using namespace std;
using namespace SearcherSpace;
int parser(int argc, char* argv[]) {
    AnyOption *opt = new AnyOption();
    Surface *surf;

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

    char *arg;
    if(opt->getFlag("help") || opt->getFlag('h')){
        opt->printUsage();
        return 1;
    }
    if((arg = opt->getValue('s')) != nullptr ||  (arg = opt->getValue("space")) != nullptr) {
        space = arg;
    }
    if((arg = opt->getValue('o')) != nullptr ||  (arg = opt->getValue("out")) != nullptr) {
        out = arg;
    }
    if((arg = opt->getValue('l')) != nullptr ||  (arg = opt->getValue("limit")) != nullptr) {
        limit = arg;
    }
    if((arg = opt->getValue('t')) != nullptr ||  (arg = opt->getValue("topology")) != nullptr) {
        topology = arg;
    }

    delete opt;
    return 0;
}

int main(int argc, char *argv[]) {
    int err;
    if((err = parser(argc, argv)) > 1) {
        return err;
    }
    // Plane pl;
    // cin >> pl;
    // cout << pl << endl << endl;
    // Searcher<TwoDimPoint, size_t> robot(pl);
    // auto path = robot.search();
    // cout << "search complete" << endl << endl;
    // // pl.drawPath(path);
    // cout << robot;
    return 0;
}
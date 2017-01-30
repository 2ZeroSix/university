#include "sort_strings.h"
namespace sort_strings_h {

    std::list<std::string>* read_stream_strings(std::istream &fin) {
        std::list<std::string>* strs = new std::list<std::string>;
        while(fin.good()) {
            std::string tmp("");
            getline(fin, tmp);
            strs->push_back(tmp);
        }
        if(strs->back() == "") {
            strs->pop_back();
        }
        return strs;
    }

    void print_stream_strings(std::ostream &fout, const std::list<std::string> *strs) {
        for (auto it = strs->begin(), end = strs->end(); it != end; ++it) {
            fout << *it << std::endl;
        }
    }

    void sort_strings(std::list<std::string> *strs){
        strs->sort();
    }

    void sort_strings(std::istream &fin, std::ostream &fout) {
        std::list<std::string>* strs = read_stream_strings(fin);
        sort_strings(strs);
        print_stream_strings(fout, strs);
        delete strs;
    }

    int sort_strings(std::ifstream &fin, std::ofstream &fout) {
        if (fin.is_open() && fout.is_open()) {
            sort_strings(*static_cast<std::istream*>(&fin), *static_cast<std::ostream*>(&fout));
            return 0;
        }
        return 1;
    }

    int sort_strings(std::ifstream &fin, std::ostream &fout) {
        if (fin.is_open()) {
            sort_strings(*static_cast<std::istream*>(&fin), *static_cast<std::ostream*>(&fout));
            return 0;
        }
        return 1;
    }

    int sort_strings(std::istream &fin, std::ofstream &fout) {
        if (fout.is_open()) {
            sort_strings(fin, *static_cast<std::ostream*>(&fout));
            return 0;
        }
        return 1;
    }

}

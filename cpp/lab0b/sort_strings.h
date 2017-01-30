#ifndef _SORT_H_
#define _SORT_H_
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
namespace sort_strings_h {

    /**
     * read file by strings into list
     *
     * @param   fin  input file
     *
     * @return       list of strings
     */
    std::list<std::string>* read_stream_strings(std::istream &fin);

    /**
     * print list of strings in file
     *
     * @param  fout  output file
     * @param  strs  list of strings
     */
    void print_stream_strings(std::ostream &fout, std::list<std::string> strs);

    /**
     * sort list
     *
     * @param  strs  list of string
     */
    void sort_strings(std::list<std::string> *strs);

    /**
     * read sort and print strings
     *
     * @param  fin   input stream
     * @param  fout  output stream
     */
    void sort_strings(std::istream &fin, std::ostream &fout);

    //versions, which check that files are open
    int sort_strings(std::ifstream &fin, std::ofstream &fout);
    int sort_strings(std::ifstream &fin, std::ostream &fout);
    int sort_strings(std::istream &fin, std::ofstream &fout);

}
#endif
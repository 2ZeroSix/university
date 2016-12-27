#ifndef _CSV_PARSER_H_
#define _CSV_PARSER_H_
#include <tuple>
#include <iterator>
#include <iostream>
#include <string>
#include "TupleUtil.h"
#include "exception"

class CSVReadError : std::exception {
private:
    std::string error;
public:
    CSVReadError(std::size_t row, std::size_t colon)
    : error("error at " + std::to_string(row) + "X" + std::to_string(colon)){}
    CSVReadError(std::string error) : error( error) {}
    
    virtual const char* what() const noexcept override{
        return error.c_str();
    }
};

template<typename... Types>
class CSVParser {
private:
    char colonDelim;
    char rowDelim;
    char escChar;
    std::istream &is;
    std::size_t curRow = 0;
public:
    class iterator;
    typedef const iterator const_iterator; 
    CSVParser(std::istream& is=std::cin, std::size_t skipRows=0, char colonDelim=',', char rowDelim='\n', char escChar='"')
    : colonDelim(colonDelim), rowDelim(rowDelim), escChar(escChar), is(is), curRow(skipRows){
        std::size_t count = 0;
        while(count < skipRows && is.good()) {
            char c;
            is >> c;
            if (c == rowDelim) {
                ++count;
            }
        }
    }
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator();
    }
    class iterator : std::iterator<std::input_iterator_tag, std::tuple<Types...>> {
    private:
        std::tuple<Types...> cur;
        CSVParser *parser;
        void parseRow() {
            std::string str, finstr;
            if(!parser->is.good()) {
                TupleUtil::DefaultInitTuple(cur);
                return;
            }
            getline(parser->is, str, parser->rowDelim);
            // if ((pos = str.find(parser->escChar)) != std::string::npos) {
                
            // }
            // finstr = str.substr(0, pos - 1);
            // getline(parser->is, str, parser->rowDelim);
            // finstr+=str;
            std::size_t colon;
            if(( colon = TupleUtil::assignTupleToString(cur, str, parser->colonDelim))) {
                throw  CSVReadError(parser->curRow, colon);
            }
            parser->curRow++;
        }
    public:
        iterator() {
            TupleUtil::DefaultInitTuple(cur);
        }
        iterator(CSVParser& par) : parser(&par) {
            parseRow();
        }
        iterator(const iterator& oth) : cur(oth.cur), parser(oth.parser) {}
        iterator& operator=(const iterator& oth) {
            cur = oth.cur;
            parser = oth.parser;
        }
        ~iterator() {}
        bool operator==(const iterator& oth) const {
            return cur == oth.cur;
        }
        bool operator!=(const iterator& oth) const {return !operator==(oth);}
        std::tuple<Types...>&       operator*() {
            return cur;
        }
        const std::tuple<Types...>& operator*() const{
            return cur;
        }
        std::tuple<Types...>*       operator->() {
            return &cur;
        }
        const std::tuple<Types...>*       operator->() const{}
        iterator& operator++() {
            parseRow();
            return *this; 
        }
        iterator operator++(int) {
            iterator buf = *this;
            ++this;
            return buf;
        }
        friend void swap(iterator& a, iterator& b) {
            std::swap(a.str,b.str);
            std::swap(a.parser, b.parser);
        }
    };
};


#endif
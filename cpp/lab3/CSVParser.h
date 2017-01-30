#ifndef _CSV_PARSER_H_
#define _CSV_PARSER_H_
#include <tuple>
#include <iterator>
#include <iostream>
#include <string>
#include "TupleUtils.h"
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
    : colonDelim(colonDelim), rowDelim(rowDelim), escChar(escChar), is(is), curRow(0){
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
            if(!parser->is.good()) {
                TupleUtils::DefaultInitTuple(cur);
                return;
            }
            parser->curRow++;
            bool screened = false;
            bool mayBeEscapeSymbol = false;
            char c;
            std::vector<std::string> vec(sizeof...(Types));
            for (std::size_t i = 0; i < sizeof...(Types) - 1; ++i) {
                while(true) {
                    if (!parser->is.good()) {
                        throw  CSVReadError(parser->curRow, i + 1);
                    }
                    parser->is.get(c);
                    if(screened) {
                        if (c == parser->escChar) {
                            screened = false;
                            if (mayBeEscapeSymbol) {
                                mayBeEscapeSymbol = false;
                            }
                            else {
                                mayBeEscapeSymbol = true;
                                continue;
                            }
                        }
                    }
                    else {
                        if (c == parser->escChar) {
                            screened = true;
                            if (mayBeEscapeSymbol) {
                                mayBeEscapeSymbol = false;
                            }
                            else {
                                mayBeEscapeSymbol = true;
                                continue;
                            }
                        }
                        if (c == parser->colonDelim) {
                            break;
                        }
                        if (c == parser->rowDelim) {
                            throw  CSVReadError(parser->curRow, i + 1);
                        }
                    }
                    mayBeEscapeSymbol = false;
                    vec[i].push_back(c);
                }
            }
            while(true) {
                if (!parser->is.good()) {
                    break;
                }
                parser->is.get(c);
                if(screened) {
                    if (c == parser->escChar) {
                        screened = false;
                        if (mayBeEscapeSymbol) {
                            mayBeEscapeSymbol = false;
                        }
                        else {
                            mayBeEscapeSymbol = true;
                            continue;
                        }
                    }
                }
                else {
                    if (c == parser->escChar) {
                        screened = true;
                        if (mayBeEscapeSymbol) {
                            mayBeEscapeSymbol = false;
                        }
                        else {
                            mayBeEscapeSymbol = true;
                            continue;
                        }
                    }
                    if (c == parser->colonDelim) {
                        throw CSVReadError(parser->curRow, sizeof...(Types));
                    }
                    if (c == parser->rowDelim) {
                        break;
                    }
                }
                mayBeEscapeSymbol = false;
                vec[sizeof...(Types) - 1].push_back(c);
            }
            TupleUtils::assignTupleToVector(cur, vec);
        }
    public:
        iterator() {
            TupleUtils::DefaultInitTuple(cur);
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
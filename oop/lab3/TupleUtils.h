#ifndef _TUPLE_UTILS_H_
#define _TUPLE_UTILS_H_

#include <tuple>
#include <ostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

namespace TupleUtils {

///////////////////////////
// OUTPUT TUPLE OPERATOR //
///////////////////////////
    namespace {
        template<typename Type, unsigned N, unsigned Last>
        struct TuplePrintHelper {
            static void print(std::ostream& os, const Type& tuple) {
                os << std::get<N>(tuple) << ", ";
                TuplePrintHelper<Type, N + 1, Last>::print(os, tuple);
            }
        };
        template<typename Type, unsigned N>
        struct TuplePrintHelper<Type, N, N> {
            static void print(std::ostream& os, const Type& tuple) {
                os << std::get<N>(tuple);
            }
        };
    }
    template<typename... Types>
    std::ostream& operator<<(std::ostream& os, const std::tuple<Types...>& tuple) {
        os << "(";
        TuplePrintHelper<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, tuple);
        os << ")";
        return os;
    }
    template<>
    std::ostream& operator<<(std::ostream& os, const std::tuple<>& tuple) {
        os << "(" << ")";
        return os;
    }

//////////////////
// DEFAULT INIT //
//////////////////
    namespace {
        template<typename Type, unsigned N, unsigned Last>
        struct TupleDefaultInitHelper {
            using NthType = typename std::tuple_element<N, Type>::type;
            static void init(Type& tuple, std::size_t start) {
                if (N >= start)
                    std::get<N>(tuple) =  NthType();
                TupleDefaultInitHelper<Type, N + 1, Last>::init(tuple, start);
            }
        };
        template<typename Type, unsigned N>
        struct TupleDefaultInitHelper<Type, N, N> {
            using NthType = typename std::tuple_element<N, Type>::type;
            static void init(Type& tuple, std::size_t start) {
                if (N >= start)
                    std::get<N>(tuple) = NthType();
            }
        };
    }
    template<typename... Types>
    void DefaultInitTuple(std::tuple<Types...>& tpl, std::size_t start = 0) {
        TupleDefaultInitHelper<std::tuple<Types...>, 0, sizeof...(Types) - 1>::init(tpl, start);
    }


////////////////////
// TUPLE = STRING //
////////////////////
    namespace {
        template<typename Type, unsigned N, unsigned Last>
        struct TupleAssignHelper {
            static std::size_t assign(Type& tuple, std::string str, char delim) {
                size_t idDelim = str.find(delim);
                if (idDelim == std::string::npos) {
                    return N + 1;
                }
                std::stringstream sstr(str.substr(0, idDelim));
                sstr >> std::get<N>(tuple);
                str = str.substr(idDelim + 1);
                return TupleAssignHelper<Type, N + 1, Last>::assign(tuple, str, delim);
            }
        };
        template<typename Type, unsigned N>
        struct TupleAssignHelper<Type, N, N> {
            static std::size_t assign(Type& tuple, std::string str, char delim) {
                size_t idDelim = str.find(delim);
                if (str.empty()) {
                    return N + 1;
                }
                else if (idDelim != std::string::npos) {
                    return N + 2;
                }
                std::stringstream sstr(str);
                sstr >> std::get<N>(tuple);
                return 0;
            }
        };
    }

////////////////////
// TUPLE = VECTOR //
////////////////////
    namespace {
        template<typename Type, unsigned N, unsigned Last>
        struct TupleAssignVectorHelper {
            static void assign(Type& tuple, const std::vector<std::string>& vec) {
                std::stringstream sstr(vec[N]);
                sstr >> std::get<N>(tuple);
                return TupleAssignVectorHelper<Type, N + 1, Last>::assign(tuple, vec);
            }
        };
        template<typename Type>
        struct TupleAssignElemntOfVectorHelper {
            static void assign(Type& elem, const std::string& str) {
                std::stringstream sstr(str);
                sstr >> elem;
            }
        };
        template<>
        struct TupleAssignElemntOfVectorHelper<std::string> {
            static void assign(std::string& elem, const std::string& str) {
                elem = str;                                
            }
        };
        template<typename Type, unsigned N>
        struct TupleAssignVectorHelper<Type, N, N> {
        using NthType = typename std::tuple_element<N, Type>::type;
            static void assign(Type& tuple, const std::vector<std::string>& vec) {
                TupleAssignElemntOfVectorHelper<NthType>::assign(std::get<N>(tuple), vec[N]);
            }
        };
    }


    template<typename... Types>
    void assignTupleToVector(std::tuple<Types...>& tuple, const std::vector<std::string>& vec) {
        DefaultInitTuple(tuple);
        TupleAssignVectorHelper<std::tuple<Types...>, 0, sizeof...(Types) - 1>::assign(tuple, vec);
    }


}


#endif
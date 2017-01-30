#include "CSVParser.h"
#include "TupleUtils.h"
#include <iostream>
#include <fstream>
using namespace TupleUtils;
using namespace std;

int main() {
    cout << "test.csv:" << endl;
    ifstream file("test.csv");
    CSVParser<int, string> parser(file, 0);
    try{
        for (auto rs : parser) {
            cout<<rs<<endl;
        }
    }
    catch (CSVReadError e) {
        cout << e.what() << endl;
    }
    cout << "testFail.csv:" << endl;
    ifstream filefail("testFail.csv");
    CSVParser<int, string> parserfail(filefail, 0);
    try{
        for (auto rs : parserfail) {
            cout<<rs<<endl;
        }
    }
    catch (CSVReadError e) {
        cout << e.what() << endl;
    }
    cout << endl << "test2.csv:" << endl;
    ifstream file2("test2.csv");
    CSVParser<int, string> parser2(file2, 4, '?', 'U', 'I');
    try{
        for (auto rs : parser2) {
            cout<<rs<<endl;
        }
    }
    catch (CSVReadError e) {
        cout << e.what() << endl;
    }
    cout << endl << "test2Fail.csv:" << endl;
    ifstream file2fail("test2Fail.csv");
    CSVParser<int, string> parser2fail(file2fail, 4, '?', 'U', 'I');
    try{
        for (auto rs : parser2fail) {
            cout<<rs<<endl;
        }
    }
    catch (CSVReadError e) {
        cout << e.what() << endl;
    }
    return 0;
}

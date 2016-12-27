#include "CSVParser.h"
#include <iostream>
#include <fstream>
using namespace TupleUtil;
using namespace std;

int main() {
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
}

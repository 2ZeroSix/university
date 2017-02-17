#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<int> foo() {return vector<int>();}

int main(int argc, char** argv) {
    vector<int> v = move(foo());
}
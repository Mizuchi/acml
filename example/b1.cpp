#include"../include/acml/extension/boost/variant.hpp"
#include"../include/acml/extension/cpp/vector.hpp"
#include"../include/acml/json.hpp"
#include<string>
#include<iostream>
using namespace std;

std::vector<boost::variant<int, string, double> > s;

int main() {
    s.push_back(string("hello world"));
    s.push_back(int(10));
    s.push_back(double(20));
    cout << acml::json::dumps(s) << endl;    
}

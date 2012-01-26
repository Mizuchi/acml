#include"../include/acml/extension/boost/variant.hpp"
#include"../include/acml/json.hpp"
#include<string>
#include<iostream>
using namespace std;

boost::variant<int, string, double> s;

int main() {
    s = "3.14";
    cout << acml::json::dumps(s) << endl;    
}

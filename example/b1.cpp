#include"../include/acml/extension/boost/variant.hpp"
#include"../include/acml/extension/cpp/map.hpp"
#include"../include/acml/json.hpp"
#include<string>
#include<iostream>
using namespace std;

map<string, boost::variant<int, string, double> > s;

int main() {
    s["Varchar"] = string("hello world");
    s["Int"] = int(10);
    s["Float"] = double(20);
    cout << acml::json::dumps(s) << endl;    
}

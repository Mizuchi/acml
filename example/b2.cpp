#include"../include/acml/extension/boost/optional.hpp"
#include"../include/acml/json.hpp"
#include<string>
#include<iostream>
using namespace std;

boost::optional<string> s;

int main() {
    s = string("hello world");
    cout << acml::json::dumps(s) << endl;    
}

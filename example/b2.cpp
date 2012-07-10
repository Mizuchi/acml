#include<acml/extension/notation/sci_float.hpp>
#include<acml/extension/boost/variant.hpp>
#include<acml/extension/boost/optional.hpp>
#include<acml/extension/cpp/vector.hpp>
#include<acml/json.hpp>
#include<string>
#include<iostream>
using namespace std;

boost::optional<boost::variant<int, vector<double>, string> > s;

typedef boost::variant<int, vector<double>, string> MultiValue;

ACML_TYPENAME_HANDLE(MultiValue) {
    return "MultiValue(int, vector<double>, string)";
}

int main() {
    vector<double> a;
    a.push_back(2.718);
    a.push_back(3.14);
    a.push_back(0.618);
    s = a;
    cout << acml::json::dumps(s) << endl;    
}

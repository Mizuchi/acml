#include"../include/acml/extension/cpp11/all.hpp"
#include"../include/acml/json.hpp"

#include<iostream>

int main() {
    using namespace std;
    unordered_multimap<int, int> a;
    a.insert(make_pair(1, 1));
    a.insert(make_pair(1, 2));
    a.insert(make_pair(2, 3));
    a.insert(make_pair(2, 3));
    a.insert(make_pair(3, 2));
    a.insert(make_pair(3, 1));
    cout << acml::json::dumps(a) << endl;
}


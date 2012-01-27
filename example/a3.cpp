#include"../include/acml/xml.hpp"

template<class T1, class T2, class T3>
struct Data {
    T1 t1;
    T2 t2;
    T3 t3;
};

ACML_REGISTER_TEMPLATE(Data, 3, ,(t1)(t2)(t3))

int main () {
    using namespace std;

    Data<string, double, int> data;
    data.t1 = "hello<world";
    data.t2 = 1.23;
    data.t3 = 200240;

    cout << acml::xml::dumps(data) << endl;
}

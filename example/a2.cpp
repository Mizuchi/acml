//
// http://stackoverflow.com/questions/8220130/converting-c-class-to-json
//

#include"../include/acml/extension/cpp/vector.hpp"
#include"../include/acml/extension/cpp/map.hpp"
#include"../include/acml/json.hpp"

class Example {
        std::string string;
        std::map<std::string, std::string> map;
        std::vector<int> vector;
        friend class acml::Reflector<Example>;
    public:
        Example() {
            string = "the-string-value";
            map["key1"] = "val1";
            map["key2"] = "val2";
            int vd[] = {1, 2, 3, 4};
            vector.assign(vd, vd + 4);
        }
};

ACML_REGISTER(Example , , (string)(map)(vector));

int main() {

    Example example;
    std::string result = acml::json::dumps(example);
    std::cout << result << std::endl;
}


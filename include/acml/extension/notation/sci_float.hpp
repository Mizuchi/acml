#ifndef __ACML_HPP__NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP__NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include<sstream>

namespace acml {
template<class T> std::string print(const T &value);

template<>
std::string print<>(const float &value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

template<>
std::string print<>(const double &value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

template<>
std::string print<>(const long double &value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

} /* namespace acml */
#endif /* __ACML_HPP_NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */

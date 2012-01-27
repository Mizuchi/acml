#ifndef __ACML_HPP__NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP__NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../../print.hpp"
#include<sstream>

ACML_PRINT_HANDLE(float, value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

ACML_PRINT_HANDLE(double, value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

ACML_PRINT_HANDLE(long double, value) {
    std::ostringstream os;
    os << std::scientific << value;
    return os.str();
}

#endif /* __ACML_HPP_NOTATION_SCI_FLOAT_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */

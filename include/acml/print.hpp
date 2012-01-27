#ifndef __ACML_HPP_printfwd_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_printfwd_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include<string>
namespace acml { 
template<class T> std::string print(const T &);
}

#define ACML_PRINT_HANDLE(TYPE, VALUE)                        \
    namespace acml {                                          \
    template<> std::string print<>(const TYPE &);             \
    } /* namespace acml */                                    \
    template<> inline std::string acml::print<>(const TYPE &VALUE)

#endif /* __ACML_HPP_printfwd_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */

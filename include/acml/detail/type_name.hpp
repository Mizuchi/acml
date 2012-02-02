#ifndef __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include<string>
#include<vector>
#include<cctype>
#include<cassert>
#include<cstdlib>

namespace acml {
namespace typeName {
using std::string;
using std::vector;
using std::isspace;

struct TypeAST {
    string name;
    vector<TypeAST> params;
    string type;
};


inline char next_token(const char *&s) {
    while (isspace(*s)) ++s;
    return *s;
}

inline bool is_name(char c) {
    return c != '<' && c != '>' && c != ',' && c != '\0';
}

inline string get_name(const char*&s) {
    next_token(s);
    string ret;
    while (is_name(*s)) ret += *s++;
    return ret;
}

inline TypeAST parser(const char *&s) {
    TypeAST ret;
    ret.name = get_name(s);
    if (next_token(s) == '<') {
        do ret.params.push_back(parser(++s));
        while (next_token(s) == ',');
        assert(next_token(s) == '>');
        ++s;
    }
    ret.type = get_name(s);
    return ret;
}

inline string last_name(string s) {
    string::size_type i = s.find_last_of(':');
    if (i == string::npos) return s;
    return s.substr(i + 1);
}

inline bool cut_tail(string s) {
    return s == "allocator" || s == "void_";
}

inline void simplify(TypeAST &a) {
    vector<TypeAST> &s = a.params;
    vector<TypeAST>::iterator i;
    for (i = s.begin(); i != s.end(); ++i)
        if (cut_tail(last_name(i->name))) {
            s.erase(i, s.end());
            break;
        }
    for (i = s.begin(); i != s.end(); ++i)
        simplify(*i);
}

inline string print(const TypeAST &a) {
    string ret = a.name;
    const vector<TypeAST> &s = a.params;
    vector<TypeAST>::const_iterator i;
    for (i = s.begin(); i != s.end(); ++i)
        ret += (i == s.begin() ? "<" : ", ") + print(*i);
    ret = s.empty() ? ret : ret + "> ";
    return ret + a.type;
}

inline string pretty_print(const char *s) {
    const char *tmp = s;
    TypeAST ast = parser(tmp);
    simplify(ast);
    string ret = print(ast);
    std::free((void *)s);
    return ret;
}
} // namespace typeName
} // namespace acml
#endif /* __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */

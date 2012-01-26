#ifndef __ACML_HPP_std__map_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP_std__map_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../container.hpp"
#include<map>
ACML_REGISTER_TEMPLATE_HANDLE(std::map, 4, visitor, value) {
    typedef typename Value::const_iterator Iter;             
    for(Iter i = value.begin(); i != value.end(); ++i)       
        visitor(i->second, print(i->first).c_str());                     
}

ACML_REGISTER_CONTAINER(std::multimap, 4)
#endif /* __ACML_HPP_std__map_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */


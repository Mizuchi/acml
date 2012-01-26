#!/usr/bin/env python3

import os
import os.path

kTemplate = '''\
#ifndef __ACML_HPP_{headname}_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP_{headname}_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../container.hpp"
#include<{include}>
ACML_REGISTER_CONTAINER({name}, {template_parameters_length})
#endif /* __ACML_HPP_{headname}_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */
'''

containers = None
with open('container_information.json', 'r', encoding='utf-8') as f:
    import json
    containers = json.load(f)

directories = {}

for info in containers:
    filename = info["name"][info["name"].rfind(":")+1:] + ".hpp"
    path = os.path.join(info["directory"], filename)

    if info["directory"] in directories:
        directories[info["directory"]] += [filename]
    else:
        directories[info["directory"]] = [filename]
        if not os.path.isdir(info["directory"]):
            os.makedirs(info["directory"])

    with open(path, 'w') as output:
        print(kTemplate.format(headname = info["name"].replace(":","_"), **info), file=output)

kAllTemplate = '''\
#ifndef __ACML_ALLHPP_{directory}_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_ALLHPP_{directory}_AUTHOR__YTJ__YTJ000_AT_GMAIL_
{body}
#endif /* __ACML_ALLHPP_{directory}_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */
'''


for directory in directories:
    path = os.path.join(directory, "all.hpp")
    with open(path, "w") as output:
        body = ''
        for name in directories[directory]:
            body += '#include"{}"\n'.format(name)
        print(kAllTemplate.format(directory = directory, body = body), file=output)


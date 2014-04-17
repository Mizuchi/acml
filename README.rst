#####
ACML
#####
:Author: Tianjiao Yin <ytj000@gmail.com>

Deprecated
==========

Warning: I am not going to maintain this project any more since no one use it. This repository will be deleted soon. Fork it if you still want to use this project or even take over it.

Here are some replacements,

1. https://github.com/Loki-Astari/ThorsSerializer
2. http://fossil.wanderinghorse.net/repos/nosjob/index.cgi/wiki?name=s11n
3. https://code.google.com/p/cjson/


Intro
=====

ACML is a header-only C++ xml/json dump/serialization library.
It requires C++ Boost Library.

BTW, ACML means "Another C++ struct to Markup Language library".

Quick Start
============

In the beginning::

    struct Person {
        std::string name;
        double height;
        int weight;
        Person(std::string n, double h, int w):
            name(n), height(h), weight(w) {}
    };

    ACML_REGISTER(Person, ,(name)(height)(weight))

And later::

    Person noumi("Kudryavka Anatolyevna Strugatskaya", 1.45, 39);
    std::string result = acml::json::dumps(noumi);
    std::cout << result << std::endl;

The output is::

    {
        "name": "Kudryavka Anatolyevna Strugatskaya",
        "height": "1.45",
        "weight": "39"
    }

For Arch Linux Users
====================

Use ``yaourt -S libacml-git`` to install it.
Examples are placed in ``/usr/share/doc/acml``.


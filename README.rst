#####
ACML
#####
:Author: Tianjiao Yin <ytj000@gmail.com>

Intro
=====

ACML is a C++ xml/json dump/serialization library.
It required C++ Boost Library.

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


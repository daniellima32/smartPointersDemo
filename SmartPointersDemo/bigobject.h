#ifndef BIGOBJECT_H
#define BIGOBJECT_H

#include <iostream>

/*!
 * \brief The BigObject class: it is a class that represents
 * something big. It is not necessary to have several instances
 * of it.
 */
class BigObject
{
public:
    BigObject(int a, std::string m): a(a), m(m){}

    void doSomethind(){std::cout << "doSomethind in BigObject" << std::endl;}
private:
    int a;
    std::string m;
};

#endif // BIGOBJECT_H

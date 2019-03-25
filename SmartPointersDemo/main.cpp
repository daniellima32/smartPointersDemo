#include <QCoreApplication>

#include <memory>
#include <iostream>

#include "bigobject.h"
#include "anyclass.h"
#include "type1.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Creates a unique ptr, becasuse we will not need
    //several instances of it
    //First way of create unique ptr
    std::unique_ptr<BigObject> ptr1 (new BigObject(10, "Jesus"));

    //Second way of create unique ptr
    std::unique_ptr<BigObject> ptr2 =
            std::unique_ptr<BigObject>(new BigObject(7, "Jesus Christ"));

    //Third way of create unique ptr
    std::unique_ptr<BigObject> ptr3 =
            std::make_unique<BigObject>(777, "J C");

    //Creating shared_ptr
    //It is used to have several smart pointers
    //pointing to the same element
    //In this case, the is not a loop of pointers
    std::shared_ptr<AnyClass> ptr4 (new AnyClass());

    //Second way of create shared_ptr
    std::shared_ptr<AnyClass> ptr5 =
            std::shared_ptr<AnyClass>(new AnyClass());

    //Third way of create shared_ptr
    std::shared_ptr<AnyClass> ptr6 =
            std::make_shared<AnyClass>();

    //Pass the pointer to other pointers
    //Always use the smart_pointer
    //Do not use the raw pointer, because, if so, the memory
    //will leak
    //std::shared_ptr<AnyClass> ptrDont =
            //std::shared_ptr<AnyClass>(ptr6.get());


    std::shared_ptr<AnyClass> ptr7 = ptr6;
    std::shared_ptr<AnyClass> ptr8 = ptr6;

    //The . operator acess the functions of std::shared_pointer
    //The -> operator acess the functions of pointed object
    //To access the raw pointer, you can use *(smart)
    AnyClass ptemp = *ptr6;
    AnyClass* ptemp2 = ptr6.get();

    //Creating wek_pointer
    //it is used if you have a loop in the pointers
    std::shared_ptr<Type1> ptr9 = std::make_shared<Type1>();
    std::weak_ptr<Type1> ptr10 (ptr9);
    std::weak_ptr<Type1> ptr11  = std::weak_ptr<Type1>(ptr9);

    std::cout << "The end of code" << std::endl;
    std::cout.flush();

    return a.exec();
}

#include "gameobject.h"
#include <iostream>
#include <string>

int main()
{
    gameobject TestObject;
    TestObject.addcomponent<TestType>();

    TestType* TestComponent = test_object.getComponent<TestType>();
    std::cout << TestObject.removeComponent<TestType>() << std::endl;
    std::cout << TestComponent -> test_string << std::endl;

    return 0;
}

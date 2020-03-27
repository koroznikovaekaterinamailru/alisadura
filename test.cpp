#include <iostream>
#include <string>
#include <vector>  
#include "GameObject.h"

int main()
{
	GameObject TestObject;
	test.addComponent<TestType>();

	TestType* TestComponent = TestObject.getComponent<TestType>();
	std::cout<<TestObject.removeComponent<TestType>() <<std::endl;
	std::cout<<TestComponent->test_string<<std::endl;

	return 0;

}

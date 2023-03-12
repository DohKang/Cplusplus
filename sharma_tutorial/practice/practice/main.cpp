#include <iostream>


int main() 
{
	int a = 120;
	int b = 110;

	int* r = &b;
	int* w = r;

	std::cout << r << std::endl;
	std::cout << &r << std::endl;
	std::cout << &w << std::endl;
	std::cout << w << std::endl;
	std::cout << &b << std::endl;
	std::cout << b << std::endl;
	//int* p1 = &a;
	//int* p2 = &b;
	//p1 = p2;

	//std::cout << p1 << std::endl;
	//std::cout << p2 << std::endl;
	//std::cout << &a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << &b << std::endl;
	//std::cout << b << std::endl;
	//std::cout << *p1 << std::endl;
	//std::cout << *p2 << std::endl;
	//std::cout << &a << std::endl;
	std::cout << a << std::endl;

	system("PAUSE");
	return 0;
}
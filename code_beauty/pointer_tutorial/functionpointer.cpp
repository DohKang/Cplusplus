#include <iostream>
using namespace std;

//store address of function

int add(int a, int b)
{
	return a + b;
}

int functionmain()
{
	int(*funcPtr)(int, int) = add;
	cout << add(2, 3) << endl;
	cout << funcPtr(3,4) <<endl;
	
	system("pause>0");
	return 0;
}
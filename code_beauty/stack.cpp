#include <iostream>
#include <stack>
using namespace std;

// 5 functions for stack
// empty, size, top, push, pop
//LIFO ->Last in First out

void printStackElements(stack<int> stack) 
{
	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "There is no more element in the stack" << endl;
}


int stackmain()
{
	stack<int>numbersStack;
	numbersStack.push(25);//take one parameter.
	numbersStack.push(3);
	numbersStack.push(5);
	cout << numbersStack.top() << endl;
	printStackElements(numbersStack);
	//numbersStack.pop();
	//

	//if (numbersStack.empty())
	//{
	//	cout << "Stack is empty" << endl;

	//}
	//else
	//{
	//	cout << "Stack is not empty" << endl;
	//}
	//cout << "Stack size is " << numbersStack.size() << endl;

	system("pause>0");
	return 0;
}
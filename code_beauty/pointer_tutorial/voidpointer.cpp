#include <iostream>
using namespace std;

void printNumber(int* numberPtr) 
{
	cout << *numberPtr << endl;
}

void printLetter(char* charPtr)
{
	cout << *charPtr << endl;
}
void print(void* ptr, char type) //can point to any data type //since it is void as parameter, it can accept any type of data
{
	switch (type) 
	{
	case 'i': cout << *((int*)ptr) << endl;
	break;
	case 'c': cout << *((char*)ptr) << endl;
	break;
	}
} 

int voidmain() 
{
	int number = 5;
	char letter = 'a';
	print(&number, 'i');
	print(&letter, 'c');
	//printNumber(&number);
	//printLetter(&letter);
	system("pause>0");
	return 0;
}
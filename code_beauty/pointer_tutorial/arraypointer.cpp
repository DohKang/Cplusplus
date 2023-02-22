#include <iostream>
using namespace std;

int arraymain() 
{
	int luckyNumbers[5];
	//cout << luckyNumbers << endl; //address of first element of array
	//cout << &luckyNumbers[0] << endl;
	//cout << luckyNumbers[2] << endl;
	//cout << *(luckyNumbers + 2) << endl;

	for (int i = 0; i < 5; i++) 
	{
		cout << "Number: ";
		cin >> luckyNumbers[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Number: ";
		cout << luckyNumbers[i]<< " ";
	}
	system("pause>0");
	return 0;
}
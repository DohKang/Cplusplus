#include <iostream>
#include<vector>
using namespace std;

int vectmain()
{




	vector<int> numbers; //we don't specify size . it automatically resize itself
	/*numbers.push_back(0)*/; //push_back = insert. inserting element into a vector.
	for (int i = 1; i <= 10; i++)
	{
		numbers.push_back(i);
	}
	numbers.insert(numbers.begin() + 5, 88); //insert value 88 at index[5].total 11 elements after inserting.
	numbers.erase(numbers.begin()+5); //remove value at specific position // back to 10.
	numbers.pop_back();
	for (auto n : numbers)
		cout << n << endl;



	//cout << "Size: " << numbers.size() << endl; //know size of the vector
	//cout << "Max size: " << numbers.max_size() << endl; //what is the maximum number of elements that i can add to the vector.
	//cout << "Capacity: " << numbers.capacity() << endl; // before resizing vector, how many elements can be hold in the vectore.
	//numbers.resize(5); //resizing vector
	//cout << "Size: " << numbers.size() << endl; //resize the vector size
	//if (numbers.empty())
	//	cout << "Vector is empty \n";
	//else
	//	cout << "Vector is not empty\n";

	//cout << "Element [0] is " << numbers[0] << endl;
	//cout << "Element at(0) is " << numbers.at(0) << endl;
	//cout << "Front: " << numbers.front() << endl;
	//cout << "back: " << numbers.back() << endl;
	//numbers.clear();
	//cout << "Size: " << numbers.size() << endl;










/*	auto it = numbers.begin();
	cout << *(it + 5);*/ //works like array.

	//for (auto it = numbers.cbegin(); it != numbers.cend(); it++) //constant function will not allow user to change it's value in the subscope.
	//{
	//	*it = 20;
	//	cout << *it << endl;
	//}


	//for (auto it = numbers.begin(); it != numbers.end(); it++) //automatically assign numbers.begin() to variable it
	//{
	//	cout << *it << endl; //value of variable it
	//	cout << &it << endl; //address of it
	//	cout << &(*it) << endl; // address of value
	//}

	cin.get();
	return 0;
}
#include <iostream>
#include <memory>
using namespace std;

class MyClass 
{
public:
	MyClass() {
		cout << "Constructor invoke" << endl;
	}
	~MyClass() {
		cout << "Destructor invoke" << endl;
	}
};
//unique
int main()
{
	weak_ptr<int>wePtr1;
	{
		shared_ptr<int>shptr1 = make_shared<int>(25);
		wePtr1 = shptr1;

	}
	//when last owner left the scope, weak pointer will be deallocated.



	//shared pointer
	//{
	//	shared_ptr<MyClass>shptr1 = make_shared<MyClass>();
	//	cout << "Shared count: " << shptr1.use_count() << endl;
	//	{
	//		shared_ptr<MyClass>shptr2 = shptr1;
	//		cout << "Shared count: " << shptr1.use_count() << endl; // give number of owner of that memory location
	//		//when there is no pointer pointing that memory address, the shared_pointer will be deallocated itself.  //smart_pointer also destroyed if it is out of scope. 

	//	}
	//	cout << "Shared count: " << shptr1.use_count() << endl;
	//}



	//unique
	//unique_ptr<int>unptr1 = make_unique<int>(25); //unique_ptr -create unique pointer
	//// <int> :integer value, unptr1 : name, make_unique <int> :make integer type. (25): assign value 25.
	//cout << unptr1 << endl;
	//cout << *unptr1 << endl;
	////unique pointer can not be shared

	//unique_ptr<int>unptr2 = move(unptr1); //become owner of unptr1 address
	////unptr1 becomes nullptr. 
	//cout << *unptr2 << endl; 
	//end of scope, the unique ptr will be deallocated automatically.
	//{
	//	unique_ptr<MyClass>unptr1 = make_unique<MyClass>();
	//}



	system("pause>0");
}
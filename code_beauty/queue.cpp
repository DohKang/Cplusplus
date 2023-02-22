#include <iostream>
#include <queue>
using namespace std;
//push, pop,   
//first come first sesrve

void printQueue(queue<int> queue)
{
	while (!queue.empty())
	{
		cout << queue.front() << " " << endl;
		queue.pop();
	}
	cout << "You've finished all your tasks!" << endl;
}



int main() 
{
	queue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	cout << "Size is " << myQueue.size() << endl;
	cout << "First element is " << myQueue.front() << endl;
	cout << "Last element is " << myQueue.back() << endl;

	cout << "My queue: " << endl;
	printQueue(myQueue);



	system("pause>0");
	return 0;
}
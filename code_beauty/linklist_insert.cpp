#include <iostream>
using namespace std;

class Node
{
public:
	int Value;
	Node* Next;
};

void printList(Node* n)
{
	while (n != NULL)
	{
		cout << n->Value << endl;
		n = n->Next;
	}

}

void insertAtTheFront(Node**head, int newValue) 
{
	//prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	//put it in front of current head
	newNode->Next = *head;
	//move head of the list to point to the newNode
	*head = newNode;
}

void inseretAtTheEnd(Node** head, int newvalue) {
	//prepare a new node
	Node* newNode = new Node();
	newNode->Value = newvalue;
	newNode->Next = NULL;
	//If Linked list is empty, newnode will be a head node
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
//Find the last node
	Node* last = *head;
	while (last->Next != NULL)
	{
		last = last->Next;
	}
//Insert newNode after lasst node
	last->Next = newNode;



}

void insertAfer(Node *previous, int newvalue) 
{
	//check if previous node is null
	if (previous == NULL)
	{
		cout << "Previous can not be NULL";

	}
	Node* newNode = new Node();
	newNode->Value = newvalue;
	newNode->Next = previous->Next;
	previous->Next = newNode;

}
int limain()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;

	//insertAtTheFront(&head, -1);
	//insertAtTheFront(&head, -2);
	inseretAtTheEnd(&head, 4);
	insertAfer(head, -1);
	printList(head);
	system("pause>0");
	return 0;
}
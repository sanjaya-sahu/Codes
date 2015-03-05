#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * next;
};

Node * insertElem(Node * list, int elem)
{
	Node * newNode = new Node();
	newNode->data = elem;
	newNode->next = list;
	return newNode;
}

void printList(Node * list)
{
	Node * iter = list;
	while (iter != NULL)
	{
		cout << iter->data << "-->";
		iter = iter->next;
	}
}

Node * reverseList(Node * list)
{
	if (list == NULL)
		return list;
	else if (list->next == NULL)
		return list;
	else {
		Node * reversedRest = reverseList(list->next);
		Node * iter = reversedRest;
		while (iter->next != NULL)
			iter = iter->next;
		list->next = NULL;
		iter->next = list;
		return reversedRest;
	}
}
int main() {
	// your code goes here
	Node * myList = NULL;
	myList = insertElem(myList, 50);
	myList = insertElem(myList, 40);
	myList = insertElem(myList, 30);
	myList = insertElem(myList, 20);
	myList = insertElem(myList, 10);
	printList(myList);
	cout << endl;
	myList = reverseList(myList);
	printList(myList);
	cout << endl;
	return 0;
}

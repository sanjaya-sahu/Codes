#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
	int m_data;
	struct node * m_next;
};

typedef struct node* Node;

void push(Node & head_ref, int new_value)
{
	Node new_node = new node;
	new_node->m_data = new_value;
	new_node->m_next = head_ref;
	head_ref = new_node;
}

void reverse(Node & head_ref)
{
	Node prev = NULL;
	Node curr = head_ref;
	Node next = NULL;
	while (curr != NULL)
	{
		next = curr->m_next;
		curr->m_next = prev;
		prev = curr;
		curr = next;
	}
	head_ref = prev;
}

void printList(const Node & head_ref)
{
	Node temp = head_ref;
	while (temp != NULL)
	{
		cout << temp->m_data << "->";
		temp = temp->m_next;
	}
	cout << endl;
}

int main() {
	// your code goes here
	Node head = NULL;
	
	push(head, 20);
	push(head, 4);
	push(head, 15);
	push(head, 85);
	push(head, 73);
	push(head, 64);
	printList(head);
	reverse(head);
	printList(head);
	cout << "Done" << endl;
	return 0;
}
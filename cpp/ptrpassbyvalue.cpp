#include <iostream>
using namespace std;

void func(int *p)
{
	++p;
	cout << "Incrementing ptr address p inside func " << endl;
	cout << "Address of ptr after incr in func : " << p << endl;
}

int main()
{
	int j = 10;
	int *ptr = &j;

	cout << "Address of ptr in main before func call : " << ptr << endl;
	cout << "Value of ptr in main before func call : " << *ptr << endl;

	cout << endl;

	func(ptr);

	cout << endl;

	cout << "Address of ptr in main after func call : " << ptr << endl;
	cout << "Value of ptr in main after func call : " << *ptr << endl;

	cout << endl;

	return 0;
}


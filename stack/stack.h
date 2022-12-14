#include<iostream>
using namespace std;

class stack
{
	int* pstack;
	int size;
	int top;
	
	public:
	stack(int);
	bool IsEmpty();
	bool IsFull();
	bool push(int);
	bool pop();
	void display();
	~stack();
};

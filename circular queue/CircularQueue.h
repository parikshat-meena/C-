#include<iostream>
using namespace std;

class CircularQueue
{
	int front,rear,size;
	int *pCque;
	
	public:
		
	CircularQueue(int);
	bool IsFull();
	bool IsEmpty();
	bool EnQueue(int&);
	bool DeQueue(int&);
	void display();
	~CircularQueue();
};

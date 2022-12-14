#include<iostream>
using namespace std;

class Queue
{
	int *pQueue;
	int front,end,size;
	public:
	Queue(int);
	bool IsFull();
	bool IsEmpty();
	bool EnQueue(int);
	bool deQueue();
	void display();
	~Queue();
};

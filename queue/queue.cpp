#include "Queue.h"

	Queue :: Queue(int s)
	{
		this->front = -1;
		this->end = -1;
		pQueue = new int[s];
	}
	//////////////////////////
	bool Queue :: IsFull()
	{
		if(front == size-1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	//////////////////////////	
	bool Queue :: IsEmpty()
	{
		if(end==-1&&front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
//////////////////////////	
	bool EnQueue(int ele)
	{
		if(IsFull())
		{
			cout<<"\tQueue is full";
		}
		else
		{
			if(IsEmpty())
			{
				this->front= 0;
			}
		
			this->pQueue[++end]= ele;
			cout<< "\tElement added successfully"; 
		}
	}
//////////////////////////	
	bool deQueue()
	{
		if(IsEmpty())
		{
			cout<<"Queue is empty";	
		}	
		else
		{
			this->pQueue[++front];	
		}
	}
	//////////////////////////	
	void display()
	{
		
	}
	//////////////////////////	
	~Queue()
	{
			
	}
	//////////////////////////	

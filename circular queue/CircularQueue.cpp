#include "CircularQueue.h"

CircularQueue ::CircularQueue(int ele)
{
	this->size = ele;
	this->front = this->rear = -1;
	pCque = new int[size];//creating queue of size = ele
}
///////////////////////////////////////////
bool CircularQueue :: IsFull()
{
	if((rear == size-1 && front == 0) || front == rear + 1 )
	{  // is full for new queue      // isfull when element got deleted and inserted again 
		return true;
	}
	else
	{
		return false;
	}
}
///////////////////////////////////////////
bool CircularQueue :: IsEmpty()
{
	if(front == -1 && rear == -1)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
///////////////////////////////////////////
bool CircularQueue :: EnQueue(int &ele)
{
	if(IsFull())
	{
		cout<<"\n\tThe Queue is full";
		return false;
	}
	else
	{
		if(IsEmpty())//if entering first element in queue
		{
			front = 0;
			pCque[++rear] = ele;
		}
		else
		{
			if(rear == size -1 && front!=0)//checking if zeroth poistion is empty
			{
				rear = 0;
			}
			else
			{
				++rear;
			}
			pCque[rear] = ele;//Enqueuing element
		}
		return true;
	}
}
///////////////////////////////////////////
bool CircularQueue :: DeQueue(int &ele)
{
	if(IsEmpty())
	{
		cout<<"\n\tEmpty Queue";
		return false;
	}
	else
	{
		//storing value of element getting pop
		ele = pCque[front];
		
		// if only one element present
		if(rear == front)
		{
			rear = -1;
			front = -1;
		}
		else if(front==size-1)//traversing from last index to first index
		{
			front = 0;
		}
		else //just poping element from queue
		{
			++front;
		}
	}
	return true;
}
///////////////////////////////////////////
void CircularQueue :: display()
{	
	if(IsEmpty())
	{
		cout<<"No element to be display";
	}
	else
	{
		int i= front;
		while(i!=rear)
		{	
			cout<<pCque[i]<<" ";
			if(i==size-1)
			{
				i = 0;
			}		
			else
			{
				i++;
			}	
		}
		cout<<pCque[rear];		
	}
}
///////////////////////////////////////////
CircularQueue :: ~CircularQueue()
{
	delete []pCque;
}
///////////////////////////////////////////

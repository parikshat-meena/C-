#include "stack.h"

///////////////////////////////////
	stack::stack(int s)
	{
		this->size= s;
		this->top = -1;
		this->pstack = new int[size];	
	}
///////////////////////////////////
	bool stack :: IsEmpty()
	{
		if(top == -1)
		return true;
		else
		return false;
	}
///////////////////////////////////
	bool stack :: IsFull()
	{
		if(top == size-1)
		return true;
		else 
		return false;
	}
///////////////////////////////////
	bool stack::pop()
	{
		if(IsEmpty())
		{
			cout<<"\tStack Underflow... stack is Empty";
			return false;
		}
		else
		{
			this->pstack[--top];
			return true;
		}
	}
///////////////////////////////////	
	bool stack :: push(int ele)
	{
		if(IsFull())
		{
			cout<<"Stack overflow... stack is Full";
			return false;
		}
		else
		{
			this->pstack[++top] = ele;
			return true;
		}
	}
///////////////////////////////////	
	void stack :: display()
	{
		int i;
		if(IsEmpty())
		{
			cout<< "No element to display";
		}
		else
		{
			for(i=0;i<=top;i++)
			{
				cout<<"\t"<<this->pstack[i];
			}
		}
	}
///////////////////////////////////	
	stack::~stack()
	{
		if(pstack!=NULL)
		{
			delete []pstack;	
		}
	
	}
	
	


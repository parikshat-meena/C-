#include "dll.h"

dll::dll()
{
	start = NULL;
}
/////////////////////////////////////////////////////
void dll::insertAtPos(int data, int pos)
{
	Node*temp = new Node(data);
	if(start == NULL)
	{
		start = temp;
		return;
	}
	if(pos == 1)
	{
		temp->setNext(start);
		start->setPrev(temp);
		start = temp;
		return;
	}
	int i = 1;
	Node*p = start;
	while(p->getNext()!=NULL && i<pos-1)
	{
		p = p->getNext();
		i++;
	}
	temp->setNext(p->getNext());
	temp->setPrev(p);
	if(p->getNext()!= NULL)
	{
		p->getNext()->setPrev(temp);	
	}
	p->setNext(temp);	
}
//////////////////////////////////////////////////////
void dll::Display()
{
	if(start == NULL)
	{
		cout<<"\n\tNo element to display";
		return;
	}
	Node*p = start;
	while(p->getNext()!=NULL)
	{
		cout<<p->getData()<<" ";
		p = p->getNext();
	}
	cout<<p->getData()<<" ";
}
//////////////////////////////////////////////////////
void dll:: deleteAtPos(int pos)
{
	if(start == NULL)
	{
		cout<<"\n\t No element to delete";
		return;
	}
	Node*p = start;
	if(pos == 1)
	{
		start = p->getNext();
		if(start!= NULL)
		start->setPrev(NULL);
		cout<<"\n"<<p->getData()<<" is deleted";
		delete p;
		return;
	}
	int i = 1;
	while(i<pos && p->getNext() != NULL)
	{
		p = p->getNext();
		i++;
	}
	if(i==pos)
	{
		p->getPrev()->setNext(p->getNext());
		if(p->getNext() != NULL)
		{
			p->getNext()->setPrev(p->getPrev());
		}
		cout<<"\n"<<p->getData()<<" is deleted";
		delete p;
		return;	
	}
	else
	{
		cout<<"Invalid Position";
	}
}
//////////////////////////////////////////////////////
dll ::~dll()
{
	if(start != NULL)
	{
		Node*p = start;
		while(p->getNext()!=NULL)
		{
			start= start->getNext();
			delete p;
			p = start;
		}
		delete p;
		start = NULL;
	}
}

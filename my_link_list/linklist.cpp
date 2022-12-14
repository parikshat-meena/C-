#include "linklist.h"
//////////////////////////////////////////////
LinkList ::LinkList()
{
	this->start = NULL;
}
//////////////////////////////////////////////
void LinkList:: insertAtBeg(int d)
{
		Node*temp = new Node(d);
		temp->setNext(start);
		start = temp;
}
//////////////////////////////////////////////
void LinkList::display()
{
	if(start == NULL)
	{
		cout<<"No element to display";
	}
	else
	{
		Node*p = start;
		while(p!=NULL)
		{
			cout<<"\t"<<p->getData();
			p = p->getNext();
		}
	}
}
//////////////////////////////////////////////
void LinkList::insertEnd(int d)
{
	Node*temp = new Node(d);
	if(start == NULL)
	{
		start = temp;
		return;
	}
	Node*p = start;
	while(p->getNext() != NULL)
	{
		p = p->getNext();
	}
		p->setNext(temp);
}
//////////////////////////////////////////////
void LinkList::insertAtPos(int d,int pos)
{
	Node*temp = new Node(d);
	if(start == NULL)
	{
		start = temp;
		return;
	}
	if(pos == 1)
	{
		temp->setNext(start);
		start = temp;
		return;	
	}	

	Node*p = start;
	int i=1;

		while(i<pos-1)
		{
			if(p->getNext()==NULL)
			{
				p->setNext(temp);
				return;
			}
			p = p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
}
//////////////////////////////////////////////
void LinkList :: deleteAtBeg()
{
	if(start == NULL)
	{
		cout<<"No element to delete";
	}
	else
	{
		Node*p = start;
		start = p->getNext();
		cout<< p->getData()<<" deleted from beginning";
		delete p;
	}
}
//////////////////////////////////////////////
void LinkList :: deleteAtPos(int pos)
{
	if(start == NULL)
	{
		cout<<"No element to delete";
		return;
	}
	else
	{
		Node*p = start;
//		delete from beginning
		if(pos == 1)
		{	
			start = p->getNext();
			cout<<p->getData()<<" deleted from position"<<pos;
			delete p;
			return;
		}
		int i=1;
		while(i<pos-1 && p->getNext() != NULL)
		{
			p = p->getNext();
			i++;
		}
		if(i== pos -1)
		{
			Node*q = p->getNext();
			p->setNext(q->getNext());
			cout<<q->getData()<<" deleted from position"<<pos;
			delete q;	
		}
		else
		{
			cout<<"Invalid position";
		}
	}
}
//////////////////////////////////////////////
LinkList::~LinkList()
{
	if(start != NULL)
	{
		
		Node*p = start;
		while(p!= NULL)
		{
			start = start->getNext();
			delete p;
			p = start;
		}
	}
}
//////////////////////////////////////////////

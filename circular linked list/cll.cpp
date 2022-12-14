#include"cll.h"

cll::cll()
{
	start = NULL;
}
////////////////////////////////////////////////////////////
void cll:: insetAtPos(int d,int pos)
{
	Node*temp = new Node(d);
	if(start == NULL)
	{
		start = temp;
		temp->setNext(start);
		cout<<temp->getData()<<" is inserted ";
		return;
	}
	Node*p = start;
	if(pos == 1)
	{
	
		while(p->getNext()!= start)
		{
			p = p->getNext();
		}
		temp->setNext(start);
		start = temp;
		p->setNext(start);
		cout<<temp->getData()<<" is inserted at beg";
		return;
	}
	int i = 1;
	while(p->getNext() != NULL && i<pos-1)
	{
		p = p->getNext();
		i++;
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
	cout<<temp->getData()<<" is inserted at position "<<pos;
}
////////////////////////////////////////////////////////////
void cll::deleteAtPos(int pos) 
{
	if(start == NULL)
	{
		cout<<"No element to delete";
		return;
	}
	Node*p = start;
	if(pos == 1 )
	{
		cout<<p->getData()<<" is deleted ";
		if(start->getNext()==start)
		{
			delete start;
			start = NULL;
			return;
		}
		while(p->getNext()!=start)
		{
			p=p->getNext();
		}	
		p->setNext(start->getNext());
		delete start;
		start = p ->getNext();
		return;
	}
	int i = 1;
	while(p->getNext()!= start && i<pos-1)
	{
		p=p->getNext();
		i++;
	}
	if(i == pos-1)
	{
	Node* q = p->getNext();
	p->setNext(q->getNext());
	cout<<q->getData()<<" is deleted at "<<pos;
	delete q;	
 	}
 	else
 	{
 		cout<<"\n\tInvalid position";
 	}
}
////////////////////////////////////////////////////////////
void cll:: display()
{
	if(start == NULL)
	{
		cout<<"No element to display";
		return;
	}
	Node*p = start;
	while(p->getNext()!= start)
	{
		cout<<p->getData()<<" ";
		p = p->getNext();
	}
	cout<<p->getData();
}
////////////////////////////////////////////////////////////
cll::~cll()
{
	Node*p=start;
	while(p->getNext()!=start)
	{
		p = p->getNext();
		delete start;
		start = p;
	}
	delete p;
	start = NULL;
}
////////////////////////////////////////////////////////////

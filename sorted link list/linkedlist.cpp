#include"linkedlist.h"
linkedlist::linkedlist()
{
	start=NULL;
}

void linkedlist::insert(int d)
{
	node *temp=new node(d);//creating new node
	if(start == NULL)//no element condition
	{
	start=temp;
	return;	
	}

	if(temp->getdata() <= start->getdata())//repeated element and smallest element at first position
	{
		temp->setnext(start);
		start = temp;
		return;
	}
	node*p = start;
	node*q = start;
	
	while(p->getnext()!= NULL && p->getdata() < temp->getdata())// traversing p until p data is greater than temp data
	{
		p = p->getnext();
	}

	if(p->getnext() == NULL && p->getdata() < temp->getdata())// temp will be last node
	{
		p->setnext(temp);
		return;
	}
	while(q->getnext()!= p)//traversing q upto position before p
	{
		q = q->getnext();
	}
	
	temp->setnext(p);//inserting between the nodes
	q->setnext(temp);
}

void linkedlist::display()
{
	if(start==NULL)
	{
		cout<<"\n NO NODES TO PRINT";
	}
	else
	{
		node *p=start;
		while(p!=NULL)
		{
			cout<<"\t"<<p->getdata();
			p=p->getnext();
		}
	}
}
linkedlist::~linkedlist()
{
}

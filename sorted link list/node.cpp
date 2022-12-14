#include"node.h"
node::node(int d)
{
	data=d;
	next=NULL;	
}
int node:: getdata()
{
	return data;
}
node *node::getnext()
{
	return next;	
}
void node:: setdata(int d)
{
	data=d;
}
void node::setnext(node * nt)
{
	next=nt;
}

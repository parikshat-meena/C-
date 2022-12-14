#include<iostream>
using namespace std;

class node
{
	int data;
	node *next;
	public:
		node(int);
		int getdata();
		node *getnext();
		void setdata(int);
		void setnext(node *);
};

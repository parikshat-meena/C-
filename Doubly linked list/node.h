#include<iostream>
using namespace std;

class Node
{
	protected:
	Node*Prev;
	Node*Next;	
	int Data;
	public:
	Node(int);
	void setNext(Node*);
	void setPrev(Node*);
	void setData(int);
	int getData();
	Node* getNext();
	Node* getPrev();
	
};

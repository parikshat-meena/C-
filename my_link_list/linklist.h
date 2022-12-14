#include "node.h"

class LinkList
{
	Node*start;
	public:
	LinkList();
	void insertAtBeg(int);
	void display();
	void insertEnd(int);
	void insertAtPos(int,int);
	void deleteAtBeg();
	void deleteAtPos(int);
	~LinkList();
};

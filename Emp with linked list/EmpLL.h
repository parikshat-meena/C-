#include "node.h"

class LinkList
{
	Node*start;
	public:
	LinkList();
	void display();
	void insertAtPos(Emp,int);
	void deleteAtPos(int);
	~LinkList();
};

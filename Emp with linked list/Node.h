#include "emp.h"
using namespace std;

class Node
{
	protected:
	Emp data;
	Node *next;
	public:
		Node(Emp);
		void setData(Emp);
		void setNext(Node*);
		Emp getData();
		Node* getNext();
		
};

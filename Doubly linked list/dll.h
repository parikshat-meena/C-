#include"node.h"

class dll
{
	Node* start;
	public:
		dll();
		void insertAtPos(int, int);
		void Display();
		void deleteAtPos(int);
		~dll();
};

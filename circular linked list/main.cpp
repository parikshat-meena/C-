#include "cll.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cll c;
	int choice=0;

	while(choice != 10)
	{	cout<<"\n\t1.Insert at position";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Delete at position";
		cout<<"\n\t10.Exit";
		cout<<"\n\tEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					int data,pos;
					cout<<"\n\tEnter data and position of element to be inserted : ";
					cin>>data>>pos;
					c.insetAtPos(data,pos);
					break;
				}
			case 2:
				{
					c.display();
					break;
				}
			case 3:
				{
					int pos;
					cout<<"\n\tEnter position for deleting element";
					cin>>pos;
					c.deleteAtPos(pos);
					break;
				}
			case 10:
				{
					cout<<"------------------End of Program---------------";
					break;
				}
			default :
				{
					cout<<"Invalid Input";
					break;
				}
		}
	}
	
	return 0;
}

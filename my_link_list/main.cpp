#include "linklist.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	LinkList l;
	int choice =0;
	while(choice!=10)
	{
		cout<<"\n\n\t1.Insert at beginnning";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Insert at End";
		cout<<"\n\t4.Insert at Position";
		cout<<"\n\t5.Delete at Beg";
		cout<<"\n\t6.Delete from Position";
		cout<<"\n\t10.Exit";
		cout<<"\n\tEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
				int data;
				cout<<"\n\tEnter Element to be inserted : ";
				cin>>data;
				l.insertAtBeg(data);
				cout<<data<<" is inserted at beginning";
				break;		
			}
			case 2:
				{
					l.display();
					break;
				}
			case 3:
				{
					int data;
					cout<<"\n\tEnter Element to be inserted : ";
					cin>>data;
					l.insertEnd(data);
					cout<<"\n\t"<<data<<" is inserted at End";
					break;		
				}
			case 4: 
				{
					int data,pos;
					cout<<"\n\tEnter Element and Position to be inserted";
					cin>>data>>pos;
					l.insertAtPos(data,pos);
					cout<<"\n\t"<<data<<" inserted at "<<pos;
					break;
				}
			case 5: 
				{
					l.deleteAtBeg();
					break;
				}
			case 6:
				{
					int pos;
					cout<<"\n\tEnter Position to be deleted";
					cin>>pos;
					l.deleteAtPos(pos);
					break;	
				}
			case 10:
				{
					cout<<"=======End of program =======";
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

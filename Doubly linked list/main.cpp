#include "dll.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	dll d;
	int choice=0;
	while(choice != 10)
	{
		cout<<"\n\t1.Insert at Position";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Delete at Position";
		cout<<"\n\t10.Exit";
		cout<<"\n\tEnter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					int data,pos;
					cout<<"Enter Data  and Position to be inserted : ";
					cin>> data>>pos;
					d.insertAtPos(data,pos);
					break;
				}
			case 2: 
				{
					d.Display();
					break;
				}
			case 3: 
				{
					int pos;
					cout<<"Enter position for deleting element";
					cin>>pos;
					d.deleteAtPos(pos);
					break;
				}
			case 10:
				{
					cout<<"---------------End of Program--------------";
					break;
				}
			default:
				{
					cout<<"Invalid Input";
					break;
				}
		}
	}
	return 0;
}

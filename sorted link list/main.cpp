#include "linkedlist.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
linkedlist ll;
	int choice=0;
	while(choice!=10)
	{
		cout<<"\n  1.INSERT AT BEIGINING";
		cout<<"\n  2.display";
		cout<<"\n  10.exit  ";
		cout<<"\n ENTER YOUR CHOICE ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					int data;
					cout<<"Enter Element to be inserted : ";
					cin>>data;
					ll.insert(data);
					break;
				}
			
				case 2:
					{
					ll.display();
					break;
					}
				case 10:
					{
						cout<<"\n____________end of prgm__________";
						break;
					}
				default:
					{
					cout<<"\n Invalid choice";
					break;
					}
		}
	}
	return 0;
}

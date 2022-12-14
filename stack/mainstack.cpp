#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	stack st(5);
	int choice =0;

	while(choice!=5)
	{
		cout<<"\n\n\n\t1.Push";
		cout<<"\n\t2.Pop";
		cout<<"\n\t3.Display";
		cout<<"\n\t5.Exit";
		cout<<"\n\tEnter your choice : ";
		cin>>choice;
		cout<<"\n";
		switch(choice)
		{
			case 1: 
			{
				int ele;
				cout<<"\n\tEnter Element : ";
				cin>> ele;
				if(st.push(ele))
				{
					cout<<"\n\t Push Successfull";
				}
				else
				{
					cout<<"\n\t Push failed";
				}
				break;
			}
			case 2:
				{
					if(st.pop())
					{
						cout<<"\n\tElement poped successfully";
					}
					else
					{
						cout<<"\n\tpop failed";
					}
					break;
				}
			case 3:
				{
					st.display();
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

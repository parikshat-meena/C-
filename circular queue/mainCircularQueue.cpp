#include "CircularQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int choice,size;
	cout<<"Enter the size of Circular Queue";
	cin>>size;
	CircularQueue cq(size);

	while(choice!=10)
	{
		cout<<"\n\n\t1.EnQueue";
		cout<<"\n\t2.DeQueue";
		cout<<"\n\t3.Display";
		cout<<"\n\t10.Exit";
		cout<<"\n\n\tEnter your choice";
		cin>> choice;
		switch(choice)
		{
			case 1:
			{
				int ele;
				cout<<"\n\n\tEnter Element to be EnQueued";
				cin>>ele;
				if(cq.EnQueue(ele))
				{
					cout<<"\n\n\tSuccessfully EnQueued";
				}
				else
				{
					cout<<"\n\n\tFailed";
				}
				break;
			}
			case 2:
				{
					int ele;
					if(cq.DeQueue(ele))
					{
						cout<<"\n\n\t"<<ele<<" is poped";
					}
					else
					{
						cout<<"\n\n\tFailed";
					}
					break;
				}
			case 3:
				{
					cq.display();
					break;
				}
			case 10:
				{
					cout<<"\n\n\tProgram Ends Here";
					break;
				}
			default : 
			{
				cout<<"Invalid Choice";
				break;
			}
		}
	}
	return 0;
}

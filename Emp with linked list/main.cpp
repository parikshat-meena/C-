#include"EmpLL.h"

int main()
{
	LinkList l;
	int choice = 0;
	while (choice!=4)
	{
		cout<<"\n\t\t1.Insert at the pos";
		cout<<"\n\t\t2.Display";
		cout<<"\n\t\t3.Delete at pos";
		cout<<"\n\t\t4.Exit";
		cout<<"\n\t\tEnter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					int eid;
					char ename[20];
					double basic;
					cout<<"\nEnter eid,ename and basic";
					cin>>eid>>ename>>basic;
					int pos;
					Emp e(eid,ename,basic);
					
					cout<<"\nEnter position";
					cin>>pos;
					l.insertAtPos(e,pos);
					break;
				}
			case 2:
				l.display();
				break;
			case 3:
				{
				int pos;
				cout<<"\nEnter position";
				cin>>pos;
				l.deleteAtPos(pos);
				break;
				}
			case 4:
				{
					cout<<"============End of Program=============";
					break;
				}
			default:
				cout<<"\nInvalid Choice";
		}
	}
	return 0;
}

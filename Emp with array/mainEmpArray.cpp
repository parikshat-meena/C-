#include "EmpArray.h" 
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
 
int main(int argc, char** argv) 
{ 
	int choice=0; 
	Array a1(5); 
	while(choice!=10) 
	{ 
		cout<<"\n\t 1. Add Employee."; 
		cout<<"\n\t 2. Display Employees."; 
		cout<<"\n\t 3. Search Employee by id."; 
		cout<<"\n\t 4. Search Employee by name."; 
		cout<<"\n\t 5. Delete Employee array by Id."; 
		cout<<"\n\t 6. Update Employee by id."; 
		
		cout<<"\n\t 10.exit."; 
		cout<<"\n\t Enter your choice = "; 
		cin>>choice; 
		switch (choice) 
		{ 
			case 1: 
			{ 
				Emp *pEmp; 
				int id; 
				char nm[20]; 
				float bs; 
				cout<<"\n\t Enter the Employee's Id , Name , Basic = "; 
				cin>>id>>nm>>bs; 
				char ans,ans1; 
			
				cout<<"\n\t Do you want to add Salesman data (y/n) = "; 
				cin>>ans; 
				if(ans=='y' || ans=='Y') 
				{ 
					int tg,ic; 
					cout<<"\n\t Enter the target = "; 
					cin>>tg; 
					cout<<"\n\t Enter the incentive = "; 
					cin>>ic; 
					pEmp =new Salesman(id,nm,bs,tg,ic); 
				} 
				else
				{
					cout<<"\n\t Do you want to add Admin data (y/n) = "; 
					cin>>ans1; 
					if(ans1=='y' || ans1=='Y') 
					{ 
						int all; 
						cout<<"\n\t Enter Allowance = "; 
						cin>>all; 
						pEmp = new Admin(id,nm,bs,all); 
					} 
					else 
					{ 
						pEmp =new Emp(id,nm,bs); 
					}
					
				} 
				a1.AddEmp(pEmp); 
				break;
			} 
			case 2:
			{
				a1.Display(); 
				break;
			}
			case 3: 
			{ 
				int id; 
				cout<<"\n\t Enter the Id of emp to be searched = "; 
				cin>>id; 
				a1.searchEmp(id); 
				break;
			} 
			 
			case 4: 
			{ 
				char nm[20]; 
				cout<<"\n\t Enter the name of emp to be searched = "; 
				cin>>nm; 
				a1.searchEmp(nm); 
				break;
			} 
		 
			case 5: 
			{ 
				int id; 
				cout<<"\n\t Enter the id to be deleted = "; 
				cin>>id; 
				a1.deleteEmp(id); 
				break; 
			} 
			
			case 6: 
			{ 
				int id; 
				cout<<"\n\t Enter the id to be updated = "; 
				cin>>id; 
				a1.updateEmp(id); 
			} 
			case 10: 
			{
				break;
			}
			default: 
			cout<<"\n\t Invalid choice Entered!!!\n"; 
		} 
	} 
		return 0; 
}

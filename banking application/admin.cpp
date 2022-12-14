#include"admin.h"

Admin::Admin()
{
	this->count =0;
}
//////////////////////////////////////////
void Admin::addAccount(Account &a)
{
	if(checkAccNo(a.get_acc_no()))
	{
		cout<<"\n\t\tAccount Number already Exist";
	}
	else
	{
		ifstream myfile("count.txt");
		int count;
		myfile>>count;
		myfile.close();
		
		count++;
		ofstream myfile1("count.txt");
		myfile1<<count;
		myfile1.close();
		
		ofstream myfile2("AccountData.txt",ios_base::binary|ios_base::app);
		myfile2.write((char *)&a,sizeof(a));
		myfile2.close();
		cout<<"\n\t\tAccount Added Successfully \n";
	}
}
//////////////////////////////////////////
void Admin::deleteByAcc_no(int accno)
{
	Admin ad;
	if(ad.checkAccNo(accno))
	{ 
		int count;
		ifstream myfile("count.txt",ios_base::binary);
		myfile>>count;
		myfile.close();
		
		count--;
		ifstream hi("AccountData.txt",ios_base::binary);
		Account a;
		int i=0;
		Account* p = new Account[count];
		cout<<"\n\t\t==================================================================";
		cout<<"\n\t\t|  Name\t\t\t|\tAccount No\t|\tBalance  |";
		cout<<"\n\t\t==================================================================";

		hi.read((char*)&a,sizeof(a));
		do
		{
			if(a.get_acc_no()!=accno)
			{
				p[i]= a;
				i++;
				a.display();
			}	
			hi.read((char *)&a,sizeof(a));
		}while(!hi.eof());
		hi.close();
		
		ofstream myfile2("count.txt",ios_base::binary);
		myfile2<<count;
		myfile2.close();
			
		ofstream myfile4("AccountData.txt",ios_base::binary);
		for(i=0;i<count;i++)
		myfile4.write((char *)&p[i],sizeof(p[i]));
		myfile4.close();
		
		cout<<"\n\t\tAccount Deleted Successfully";
	}
	else
	{
		cout<<"\n\t\tInvalid Account No";
	}
}
//////////////////////////////////////////
void Admin::deleteByName(char*)
{
	
}
//////////////////////////////////////////
void Admin::updateAcc_no(int aNo)
{
	ifstream myfile1("count.txt");
	int count;
	myfile1>>count;
	myfile1.close();
	
	Account *p = new Account[count];
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Account Added Till Now";
		return;
	}
	else
	{
		bool found = false;
		Account a;
		int i=0;
		myfile.read((char *)&a,sizeof(a));
		do
		{				
			if(a.get_acc_no()==aNo)
			{
				found = true;
				cout<<"\n\t\tDo you wish to change name(y/n)? : ";
				char ans;
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new name : ";
					char name[20];
					cin>>name;
					a.set_name(name);
				}
				cout<<"\n\t\tDo you wish to change balance(y/n) :";
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new balance : ";
					int balance;
					cin>>balance;
					a.set_balance(balance);
				}				
			}
			p[i] = a;
			i++;
			myfile.read((char *)&a,sizeof(a));			
			
		}while(!myfile.eof());
		myfile.close();

		if(!found)
		{
			cout<<"\n\n\t\tRecord not found";
			return;
		}
		else
		{
			ofstream myfile2("AccountData.txt",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
		}
	}
}
//////////////////////////////////////////
void Admin::updateName(char* nm)
{
	ifstream myfile1("count.txt");
	int count;
	myfile1>>count;
	myfile1.close();
	
	Account *p = new Account[count];
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Account added till now";
		return;
	}
	else
	{
		bool found = false;
		Account a;
		int i=0;
		myfile.read((char *)&a,sizeof(a));
		do
		{				
			if(!strcmp(a.get_name(),nm))
			{
				found = true;
				cout<<"\n\t\tDo you wish to change name(y/n)? :";
				char ans;
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new name : ";
					char name[20];
					cin>>name;
					a.set_name(name);
				}
				cout<<"\n\t\tDo you wish to change balance(y/n) :";
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new balance : ";
					int balance;
					cin>>balance;
					a.set_balance(balance);
				}				
			}
			p[i] = a;
			i++;
			myfile.read((char *)&a,sizeof(a));
		}while(!myfile.eof());
		myfile.close();

		if(!found)
		{
			cout<<"\n\tRecord not found";
			return;
		}
		else
		{
			ofstream myfile2("AccountData.txt",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
		}
	}
}
//////////////////////////////////////////
void Admin::searchByAccNo(int acc)
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tPlease Add Account First!";
		return;
	}
	else
	{
	
		bool found = false;
		Account a;
		myfile.read((char *)&a,sizeof(a));
		do
		{	
			if(a.get_acc_no() == acc)
			{
				found = true;
				cout<<"\n\t\t=================================================================";
				cout<<"\n\t\t|  Name\t\t\t|\tAccount No\t|\tBalance\t|";
				cout<<"\n\t\t=================================================================";
				a.display();
				break;
			}
			myfile.read((char *)&a,sizeof(a));			
			
		}while(!myfile.eof());
		myfile.close();
		
		if(!found)
		{
			cout<<"\n\tRecord not found";
		}	
	}
}
////////////////////////////////////////////////////////////////////////
void Admin::searchByName(char* nm)
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tCurrently No Account ";
		return;
	}
	else
	{
		bool found = false;
		Account a;
		myfile.read((char *)&a,sizeof(a));
		do
		{	
			if(!strcmp(a.get_name(),nm))
			{
				found = true;
				cout<<"\n\t\t=================================================================";
				cout<<"\n\t\t|  Name\t\t\t|\tAccount No\t|\tBalance\t|";
				cout<<"\n\t\t=================================================================";
				a.display();
				break;
			}
			myfile.read((char *)&a,sizeof(a));			
			
		}while(!myfile.eof());
		myfile.close();
		
		if(!found)
		{
			cout<<"\n\t\tRecord not found";
		}	
	}
}
///////////////////////////////////////////////////////////////////////
void Admin::displayAllAccount()
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\n\t\tNo Account To Display";
		return;
	}
	else
	{
		cout<<"\n\t\t=================================================================";
		cout<<"\n\t\t|  Name\t\t\t|\tAccount No\t|\tBalance\t|";
		cout<<"\n\t\t=================================================================";
		Account a;
		myfile.read((char *)&a,sizeof(a));
		do
		{	
			a.display();
			myfile.read((char *)&a,sizeof(a));			
			
		}while(!myfile.eof());
		myfile.close();
	}	
}
//////////////////////////////////////////////////////////////
bool Admin::checkAccNo(int an)
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Account available";
		return false;
	}
	else
	{
		Account a;
		bool flag = false;
		myfile.read((char*)&a,sizeof(a));
		do
		{
			if(a.get_acc_no()==an)
			{
				flag = true;
				break;
			}
			myfile.read((char*)&a,sizeof(a));
		}
		while(!myfile.eof());
		myfile.close();
		if(flag)
		{
			return flag;
		}
		return false;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Admin:: displayAllTransaction()
{
	ifstream myfile("transaction.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Transaction";
		return;
	}
	cout<<"\n\t\t=======================================================================================";
	cout<<"\n\t\t|  Name\t\t|    Account No\t|\tType\t|\tAmount\t|\tDate\t      |";	
	cout<<"\n\t\t=======================================================================================";

	Transaction t;
	myfile.read((char*)&t,sizeof(t));
	do
	{
		t.display();
		myfile.read((char*)&t,sizeof(t));
	}while(!myfile.eof());
	myfile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Admin::deleteAllTransaction()
{
	char str;
	cout<<"\n\t\tDo You Want to Delete All Transactions(Y/N) : ";
	cin>>str;
	if(str=='Y'||str=='y')
	{
		ifstream myfile("transaction.txt",ios_base::binary);
		if(myfile)
		{
		remove("transaction.txt");
		cout<<"\n\t\tAll Transactions Deleted Successfully";	
		}
		else
		{
			cout<<"\n\t\tNo Transaction available";
		}
	}
	else
	cout<<"\n\t\tTransaction Not Deleted";	
}

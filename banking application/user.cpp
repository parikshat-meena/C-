#include"User.h"

User::User()
{
	ucount = 0;
}
////////////////////////////////////////////////////
User::User(int aNo,char* uid,char* pass)
{
	ifstream myfile("ucount.txt",ios_base::binary);
	myfile>>ucount;
	myfile.close();
	ucount++;
	
	ofstream myfile2("ucount.txt",ios_base::binary);
	myfile2<<ucount;
	myfile2.close();
	
	this->accNo = aNo;
	strcpy(this->getPassword(),pass);
	strcpy(this->getUserId(),uid);
}
////////////////////////////////////////////////////
void User::setAccNo(int no)
{
	this->accNo = no;
}
//////////////////////////////////////////////////// 
void User::setUserId(char* uid)
{
	strcpy(this->userId,uid);
}
////////////////////////////////////////////////////
void User::setPassword(char* pass)
{
	strcpy(this->password,pass);
}
////////////////////////////////////////////////////
int User::getAccNo()
{
	return this->accNo;
}
char* User::getUserId()
{
	return this->userId;
}
////////////////////////////////////////////////////
char* User::getPassword()
{
	return this->password;
}
////////////////////////////////////////////////////
void User::display()
{
	cout<<"\n\t\t|  "<<this->accNo<<"\t\t|\t"<<this->userId<<"\t\t|\t"<<this->password<<"    |";
	cout<<"\n\t\t------------------------------------------------------------------";

}
////////////////////////////////////////////////////
void User::addUser(User &u)
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Account added";
		return;
	}
	else
	{
		bool found = false;
		Account a;
		myfile.read((char*)&a,sizeof(a));
		do{
			if(a.get_acc_no()==u.accNo)
			{
				found = true;
				ofstream myfile1("user.txt",ios_base::binary|ios_base::app);
				myfile1.write((char*)&u,sizeof(u));
				myfile1.close();
			}
			myfile.read((char*)&a,sizeof(a));
		}while(!myfile.eof());
		myfile.close();
		if(found)
		{
			cout<<"\n\n\t\tRegistration Successful";
		}
	}
}
////////////////////////////////////////////////////
void User::viewDetails(char* id)
{
	ifstream myfile("user.txt",ios::binary);
	if(!myfile)
	{
		return ;
	}
	else
	{
		cout<<"\n\t\t=================================================================";
		cout<<"\n\t\t|  Name\t\t\t|\tAccount No\t|\tBalance\t|";
		cout<<"\n\t\t=================================================================";
		bool found = false;
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				found = true;
				ifstream myfile1("AccountData.txt",ios_base::binary);
				if(!myfile1)
				{
					return;
				}
				else
				{
					Account a;
					myfile1.read((char*)&a,sizeof(a));
					do
					{
						if(a.get_acc_no()==u.accNo)
						{
							a.display();
						}
						myfile1.read((char*)&a,sizeof(a));
					}while(!myfile1.eof());
					myfile1.close();
				}
				
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
	}
}
////////////////////////////////////////////////////
void User::deposit(int bal,char* id)
{	
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		return;
	}
	else
	{
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				ifstream myfile2("count.txt",ios_base::binary);
				int count;
				myfile2>>count;
				myfile2.close();
				
				ifstream myfile1("AccountData.txt",ios_base::binary);
				if(!myfile1)
				{
					cout<<"\n\t\tAccount not added";
					return;
				}
				else
				{
					int day,month,year;
					char str[20],str2[20],str3[20];
					cout<<"\n\t\tEnter Date for this Tansaction(DD-MM-YYYY) : ";
					cin>>str>>str2>>str3;

					day = atoi(str);
					month = atoi(str2);
					year= atoi(str3);
					
					if((day!=0 && day<32)&&(month!=0&&month<13) &&(year!=0&& year>2021))
					{
						
						Account*p= new Account[count];
						Account a;
						int i=0;
						bool check= false;
						myfile1.read((char*)&a,sizeof(a));
						do
						{
							if(a.get_acc_no()==u.getAccNo())
							{	
								a.set_balance(bal+a.get_balance());
								if(u.storeTransaction(a.get_acc_no(),a.get_name(),"Deposit",bal,day,month,year))
								check = true;
							}
							p[i]=a;
							i++;
							myfile1.read((char*)&a,sizeof(a));
						}while(!myfile1.eof());
						myfile1.close();
						if(check)
						{
							ofstream myfile2("AccountData.txt",ios_base::binary);
							for(int i=0;i<count;i++)
							myfile2.write((char*)&p[i],sizeof(p[i]));
							myfile2.close();
							cout<<"\n\t\tAmount Deposited Successfully\n";	
						}	
					}
					else
					{
						cout<<"\n\t\tEnter Valid Date";		
					}
					//////////////////////////////////////////////////////
				}
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
	}
}
////////////////////////////////////////////////////
void User::withdraw(int bal,char* id)
{
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		return;
	}
	else
	{
		
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				ifstream myfile2("count.txt",ios_base::binary);
				int count;
				myfile2>>count;
				myfile2.close();
				
				ifstream myfile1("AccountData.txt",ios_base::binary);
				if(!myfile1)
				{
					return;
				}
				else
				{
					int day,month,year;
					char str[20],str2[20],str3[20];
					cout<<"Enter Date for this Tansaction(DD-MM-YYYY) : ";
					cin>>str>>str2>>str3;
					day = atoi(str);
					month = atoi(str2);
					year= atoi(str3);
					
					if((day!=0 && day<32)&&(month!=0&&month<13) &&(year!=0&& year>2021))
					{
						Account*p= new Account[count];
						Account a;
						int i=0;
						bool check = false;
						myfile1.read((char*)&a,sizeof(a));
						do
						{
							if(a.get_acc_no()==u.getAccNo())
							{	
								if(a.get_balance()<bal)
								{
									cout<<"\n\t\tInsufficient Balance \n";
								}
								else
								{
									a.set_balance(a.get_balance()-bal);
									if(u.storeTransaction(a.get_acc_no(),a.get_name(),"Debited",bal,day,month,year))
									check = true;
								}
							}
							p[i]=a;
							i++;
						myfile1.read((char*)&a,sizeof(a));
					}while(!myfile1.eof());
					myfile1.close();
					
					if(check)
					{
						ofstream myfile2("AccountData.txt",ios_base::binary);
						for(int i=0;i<count;i++)
						myfile2.write((char*)&p[i],sizeof(p[i]));
						myfile2.close();
						cout<<"\n\t\tAmount Withdrawn Successfully\n";
					}
					}
					else
					{
						cout<<"\n\t\tEnter Valid Date";
					}	
					////////////////////////////////
				}
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
	}
}
////////////////////////////////////////////////////
void User::transfer(int bal,int tAccno,char* id)
{
	User checkno;
	bool found = checkno.checkAccountNo(tAccno);
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tComplete your Registeration ";
		return;
	}
	else
	{
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				ifstream co("count.txt",ios_base::binary);
				int count;
				co>>count;														
				co.close();
				
				ifstream myfile2("AccountData.txt",ios_base::binary);
				if(!myfile2)
				{
					cout<<"No Account Found";
					return;
				}
				else
				{
					int day,month,year;
					char str[20],str2[20],str3[20];
					cout<<"Enter Date for this Tansaction(DD-MM-YYYY) : ";
					cin>>str>>str2>>str3;
//					cout<<"-";							
//					cin>>str2;
//					cout<<"-";
//					cin>>str3;
					day = atoi(str);
					month = atoi(str2);
					year= atoi(str3);
					
					if((day!=0 && day<32)&&(month!=0&&month<13) &&(year!=0&& year>2021))
					{
						Account *p = new Account[count];
						int i = 0;
						bool check1 = false;
						bool check2 = false;
						bool error = false;
						Account a;
						myfile2.read((char*)&a,sizeof(a));
						do
						{
							if(found)
							{
								if(a.get_acc_no()==u.getAccNo())
								{
									a.set_balance(a.get_balance() - bal);
									if(u.storeTransaction(a.get_acc_no(),a.get_name(),"T-Send",bal,day,month,year))
									check1= true;
								}
								if(a.get_acc_no() == tAccno)
								{
									a.set_balance(a.get_balance()+bal);
									if(u.storeTransaction(a.get_acc_no(),a.get_name(),"Credit",bal,day,month,year))
									check2 = true;	
								}
							}
							else
							{
								error = true;
							}
							p[i]= a;
							i++;
							myfile2.read((char*)&a,sizeof(a));
						}while(!myfile2.eof());
						myfile2.close();
						if(error)
						{
							cout<<"\n\t\tInvalid Account No !!! Check Receiver's Account Number";
						}
						
						if(check1 && check2)
						{
							ofstream trans("AccountData.txt",ios_base::binary);
							for(i=0;i<count;i++)
							{
								trans.write((char*)&p[i],sizeof(p[i]));
							}
							trans.close();
							cout<<"\n\t\tTransfer completed Successfully";
						}
							
						}
					else
					{
						cout<<"\n\t\tEnter valid date";
					}
					
				}
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
	}
}
////////////////////////////////////////////////////
bool User::checkCredential(char*id,char*pass)
{
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		cout<<"\n\t\tNo Data Found! Please Register";
		return false;
	}
	else
	{
		bool flag = false;
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id) && !strcmp(u.getPassword(),pass))
			{
				flag = true;
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
		if(flag)
		{
			return true;
		}
		return false;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
bool User::checkRepeatation(int accno)
{
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		return false;
	}
	else
	{	bool repeat = false;
		User u1;
		myfile.read((char*)&u1,sizeof(u1));
		do
		{
			if(u1.getAccNo()==accno)
			{
				repeat = true;
			}
			myfile.read((char*)&u1,sizeof(u1));
		}while(!myfile.eof());
		myfile.close();
		if(repeat)
		{
			return true;
		}
		return false;
	}
}
/////////////////////////////////////////////////////////////////
bool User::checkAccountNo(int accno)
{
	ifstream myfile("AccountData.txt",ios_base::binary);
	if(!myfile)
	{
		return false;
	}
	else
	{	bool repeat = false;
		Account u1;
		myfile.read((char*)&u1,sizeof(u1));
		do
		{
			if(u1.get_acc_no()==accno)
			{
				repeat = true;
			}
			myfile.read((char*)&u1,sizeof(u1));
		}while(!myfile.eof());
		myfile.close();
		if(repeat)
		{
			return true;
		}
		return false;
	}
}
/////////////////////////////////////////////////////////////////////////////
void User::deleteCredential(int accno)
{
	User u;
	if(u.checkAccountNo(accno))
	{ 
		int count;
		ifstream myfile("ucount.txt",ios_base::binary);
		myfile>>count;
		myfile.close();
		
		count--;
		ifstream hi("user.txt",ios_base::binary);
		int i=0;
		User*up = new User[count];
		hi.read((char*)&u,sizeof(u));
		do
		{
			if(u.getAccNo()!=accno)
			{
				up[i]= u;
				i++;
				u.display();
			}	
			hi.read((char *)&u,sizeof(u));
		}while(!hi.eof());
		hi.close();
		
		ofstream myfile2("ucount.txt",ios_base::binary);
		myfile2<<ucount;
		myfile2.close();
			
		ofstream myfile4("user.txt",ios_base::binary);
		for(i=0;i<count;i++)
		myfile4.write((char *)&up[i],sizeof(up[i]));
		myfile4.close();
		
		cout<<"\n\t\tUser Credentials Deleted Successfully";
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
bool User::storeTransaction(int accno,char* name,char*type,int bal,int day,int month,int year)
{
	
			Transaction t(accno,name,type,bal,day,month,year);
			ofstream mfile("transaction.txt",ios_base::binary|ios_base::app);					
			mfile.write((char*)&t,sizeof(t));
			mfile.close();
			return true;
}
//////////////////////////////////////////////////////////////////////////////////////
void User::displayTransaction(char*id)
{
	ifstream myfile("user.txt",ios::binary);
	if(!myfile)
	{
		return ;
	}
	else
	{
		cout<<"\n\t\t=======================================================================================";
		cout<<"\n\t\t|  Name\t\t|    Account No\t|\tType\t|\tAmount\t|\tDate\t      |";	
		cout<<"\n\t\t=======================================================================================";
		bool found = false;
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				found = true;
				ifstream myfile1("transaction.txt",ios_base::binary);
				if(!myfile1)
				{
					cout<<"\n\t\tNo Transactions";
					return;
				}
				else
				{
					Transaction t;
					myfile1.read((char*)&t,sizeof(t));
					do
					{
						if(t.getAccNo()==u.accNo)
						{
							t.display();
						}
						myfile1.read((char*)&t,sizeof(t));
					}while(!myfile1.eof());
					myfile1.close();
				}			
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
void User::changePassword(char*id)
{
	int ucount;
	ifstream ct("ucount.txt",ios_base::binary);
	ct>>ucount;
	ct.close();
	ifstream myfile("user.txt",ios_base::binary);
	if(!myfile)
	{
		return;
	}
	else
	{
		User u;
		cout<<"\n\t\tEnter New Password : ";
		char pass[20];
		cin>>pass;
		int i=0;
		bool found = false;
		User*p = new User[ucount];
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				u.setPassword(pass);
				cout<<"\n\t\tPassword Changed Successfully";
				found = true;
			}
			p[i]=u;
			i++;
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.close();
		
		if(found)
		{
			ofstream myfile2("user.txt",ios_base::binary);
			for(int i=0;i<ucount;i++)
			myfile2.write((char*)&p[i],sizeof(p[i]));
			myfile2.close();
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
void User::displayName(char* id)
{
	ifstream myfile2("AccountData.txt",ios_base::binary);
	Account a;
	myfile2.read((char*)&a,sizeof(a));
	do
	{
		ifstream myfile("user.txt",ios_base::binary);
		User u;
		myfile.read((char*)&u,sizeof(u));
		do
		{
			if(!strcmp(u.getUserId(),id))
			{
				if(u.getAccNo()==a.get_acc_no())
				{
					cout<<"\n\tWelcome "<<a.get_name()<<"!!";			
				}
			}
			myfile.read((char*)&u,sizeof(u));
		}while(!myfile.eof());
		myfile.eof();
		myfile2.read((char*)&a,sizeof(a));
	}while(!myfile2.eof());
	myfile2.close();
}

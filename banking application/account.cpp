#include"account.h"
Account::Account()
{
	this->acc_no = 0;
	this->balance =0;
	strcpy(name,"No Account");
}
//////////////////////////////////////////
Account::Account(int no,char* nm,int bal)
{
	this->acc_no = no;
	strcpy(this->name,nm);
	this->balance = bal;
}
//////////////////////////////////////////
void Account::set_acc_no(int no)
{
	this->acc_no = no;	
}
//////////////////////////////////////////
void Account::set_name(char* nm)
{
	strcpy(this->name,nm);
}
//////////////////////////////////////////
void Account::set_balance(int bal)
{
	this->balance = bal;
}
//////////////////////////////////////////
int Account::get_acc_no()
{
	return this->acc_no;
}
//////////////////////////////////////////
char* Account::get_name()
{
	return this->name;
}
//////////////////////////////////////////
int Account::get_balance()
{
	return this->balance;
}
////////////////////////////////////////////////
void Account::display()
{	
	cout<<"\n\t\t|  "<<this->name<<"\t\t|\t"<<this->acc_no<<"\t\t|\t"<<this->balance<<"\t|";
	cout<<"\n\t\t-----------------------------------------------------------------";

//	cout<<"\n\t\tName : \t\t\t"<<this->name;
//	cout<<"\n\t\tAccount Number : \t"<< this->acc_no;
//	cout<<"\n\t\tBalance : \t\t"<<this->balance;
//	cout<<"\n";
}
//////////////////////////////////////////

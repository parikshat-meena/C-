#include"transaction.h"
Transaction::Transaction()
{
	this->accno= 0;
	strcpy(this->name," ");
	strcpy(this->type," ");
	this->amt = 0;
	this->day = 0;
	this->month = 0;
	this->year = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
Transaction::Transaction(int an,char* nm,char*tt,double amt,int d,int m,int y)
{
	this->accno= an;
	strcpy(this->name,nm);
	strcpy(this->type,tt);
	this->amt = amt;
	this->day = d;
	this->month = m;
	this->year = y;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Transaction::setAccNo(int no)
{
	this->accno = no;
}
///////////////////////////////////////////////////////////////////////////////
void Transaction::setName(char* nm)
{
	strcpy(this->name,nm);
}
///////////////////////////////////////////////////////////////////////////////
int Transaction::getAccNo()
{
	return this->accno;
}
//////////////////////////////////////////////////////////////////////////////
char* Transaction::getName()
{
	return this->name;
}
void Transaction::display()
{
	cout<<"\n\t\t|  "<<this->name<<"\t|\t"<<this->accno<<"\t|\t"<<this->type<<"\t|\t"<<this->amt<<"\t|\t"<<this->day<<"-"<<this->month<<"-"<<this->year<<"    |";
	cout<<"\n\t\t---------------------------------------------------------------------------------------";
}

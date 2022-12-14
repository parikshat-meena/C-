#include"account.h"
#pragma once
class Transaction
{
	int accno;
	char name[20];
	char type[20];
	double amt;
	int day;
	int month;
	int year;
	public:
	Transaction();
	Transaction(int,char*,char*,double,int,int,int);
	void setName(char*);
	void setAccNo(int);
	int getAccNo();
	char* getName();
	void display();		
};

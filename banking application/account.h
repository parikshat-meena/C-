#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
using namespace std;

class Account
{
	int acc_no;
	char name[20];
	int balance;
	public:
	Account();
	Account(int,char*,int);
	void set_acc_no(int);
	void set_name(char*);
	void set_balance(int);
	int get_acc_no();
	char* get_name();
	int get_balance();
	void display();
};

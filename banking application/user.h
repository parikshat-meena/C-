#include"account.h"
#include "transaction.h"
class User
{
	int accNo;
	char userId[20];
	char password[20];
	int ucount;
	public:
	User();
	User(int,char*,char*);
	void setAccNo(int);
	void setUserId(char*);
	void setPassword(char*);
	int getAccNo();
	char* getUserId();
	char* getPassword();
	void display();
	void addUser(User &);
	void viewDetails(char*);
	void deposit(int,char*);
	void withdraw(int,char*);
	void transfer(int,int,char*);
	bool checkCredential(char*,char*);
	bool checkRepeatation(int);
	bool checkAccountNo(int);
	void deleteCredential(int);
	bool storeTransaction(int,char*,char*,int,int,int,int);
	void displayTransaction(char*);
	void changePassword(char*);
	void displayName(char*);
};


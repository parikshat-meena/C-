#include"account.h"
#include"transaction.h"

class Admin
{
	int count;
	public:
	Admin();
	void addAccount(Account &);
	void deleteByAcc_no(int);
	void deleteByName(char*);
	void updateName(char*);
	void updateAcc_no(int);
	void searchByAccNo(int);
	void searchByName(char*);
	void displayAllAccount();
	bool checkAccNo(int);
	void displayAllTransaction();
	void deleteAllTransaction();
};

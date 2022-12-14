#include"Emp.h"
class Admin :public Emp 
{ 
protected:
 int Allowance; 
 public: 
  Admin(); 
  Admin(int,char*,float,int); 
  void Display();  
};


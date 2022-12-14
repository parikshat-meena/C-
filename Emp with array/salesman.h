#include"Emp.h" 
 
class Salesman:public Emp 
{ 
 int tgt; 
 int incentive; 
 public: 
  Salesman(); 
  Salesman(int,char*,float,int,int); 
  void Display();  
};
 


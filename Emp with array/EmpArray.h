#include"admin.h" 
#include"salesman.h"

 
class Array  
{ 
 int size,index; 
 Emp **p; 
 public: 
  Array(); 
  Array(int); 
  void Display();  
void AddEmp(Emp*); 
  void searchEmp(int); 
  void searchEmp(char*); 
  void updateEmp(int); 
  void deleteEmp(int); 
   
};

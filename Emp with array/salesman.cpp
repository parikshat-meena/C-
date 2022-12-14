#include"salesman.h" 
///////////////////////////////// 
Salesman::Salesman() 
{ 
 this->tgt=0; 
 this->incentive=0; 
} 
//////////////////////////////////// 
Salesman::Salesman(int id,char* nm,float bs,int tg,int in)  
:Emp(id,nm,bs) 
{ 
 this->tgt=tg; 
 this->incentive=in; 
} 
////////////////////////////////////// 
void Salesman::Display() 
{ 
 Emp::Display(); 
 cout<<"\n\t Target = "<<this->tgt; 
 cout<<"\n\t Incentive = "<<this->incentive; 
} 
////////////////////////////////////

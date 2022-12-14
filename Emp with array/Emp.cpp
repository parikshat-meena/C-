#include"Emp.h" 
//////////////////////////////// 
Emp::Emp() 
{ 
 eid=0; 
 strcpy(ename,"\0"); 
 basic=0; 
} 
/////////////////////////////////// 
Emp::Emp(int id,char* nm,float bs) 
{ 
 eid=id; 
 strcpy(ename,nm); 
 basic=bs; 
} 
/////////////////////////////////// 
void Emp::Display() 
{ 
 cout<<"\n\t Eid = "<<eid; 
 cout<<"\n\t EName = "<<ename; 
 cout<<"\n\t Basic = "<<basic; 
} 
///////////////////////////////// 
int Emp::getEid() 
{ 
 return eid; 
} 
/////////////////////////////// 
char* Emp::getEname() 
{ 
 return ename; 
} 
//////////////////////////////// 
float Emp::getBasic() 
{ 
 return basic; 
} 
//////////////////////////////// 
void Emp::setEid(int eid) 
{ 
 this->eid=eid; 
} 
/////////////////////////////// 
void Emp::setEname(char* nm) 
{ 
 strcpy(ename,nm); 
} 
////////////////////////////////// 
void Emp::setBasic(float bs) 
{ 
 basic=bs; 
} 
////////////////////////////////

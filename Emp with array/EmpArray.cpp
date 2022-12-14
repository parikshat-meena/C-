#include"EmpArray.h" 
 
Array::Array() 
{ 
 size = 0; 
 index = -1; 
 p=NULL; 
} 
/////////////////////////////////// 
Array::Array(int size) 
{ 
 this->size = size; 
 index = -1; 
 p= new Emp*[size]; 
} 
////////////////////////////////// 
void Array::Display() 
{ 
	if(index != -1) 
	{ 
		for(int i=0;i<=index;i++) 
		{ 
		p[i]->Display(); 
		cout<<"\n--------------------------------"; 
		} 
	} 
 	else 
 	{ 
  	cout<<"\n\t No Employee Data to Display..\n"; 
 	} 
} 
//////////////////////////////////////// 
void Array::AddEmp(Emp *e) 
{ 
 if(index == size - 1) 
 { 
  cout<<"\n\t Array is Full.\n"; 
  return; 
 } 
 else 
 { 
  p[++index] = e; 
 } 
} 
/////////////////////////////////////////// 
void Array::searchEmp(int id) 
{ 
 if(index == -1) 
 { 
  cout<<"\n\t No Employee to be searched.\n"; 
  return; 
 } 
 else 
 { 
  for(int i=0;i<=index;i++) 
  { 
   if(id == p[i]->getEid()) 
   { 
    cout<<"\n\t Employee is found at index location ="<<i<<"\n"; 
    p[i]->Display(); 
    return; 
   } 
  } 
  cout<<"\n\t Employee data is not present in the array.\n"; 
 } 
} 
////////////////////////////////////////////////// 
void Array::searchEmp(char* nm) 
{ 
 if (index == -1) 
 { 
  cout<<"\n\t No Employee to be searched.\n"; 
  return; 
 } 
 else 
 { 
  for(int i=0;i<=index;i++) 
  { 
   if(strcmp(nm,p[i]->getEname())==0) 
   { 
    cout<<"\n\t Employee is found at index location ="<<i<<"\n"; 
    p[i]->Display(); 
    return; 
   } 
  } 
  cout<<"\n\t Employee data is not present in the array.\n"; 
 } 
} 
///////////////////////////////////////////// 
void Array::deleteEmp(int id) 
{ 
 int i; 
 if(index==-1) 
 { 
  cout<<"\n\t No employee data present for deletion.\n"; 
  return; 
 } 
 else 
 { 
  bool found = false; 
  for(i=0;i<=index;i++) 
  { 
   if(id == p[i]->getEid()) 
   { 
    found =true; 
    break; 
   } 
  } 
  if(found) 
  { 
   while( i<index) 
   { 
    p[i]=p[i+1]; 
    i++; 
   } 
   index--; 
   cout<<"\n\t Element Deleted Sucessfully..\n"; 
  } 
  else 
  { 
   cout<<"\n\t Employee element not found.."; 
   return; 
  } 
 } 
} 
////////////////////////////////////////////////// 
void Array::updateEmp(int id) 
{ 
 if(index == -1) 
 { 
  cout<<"\n\t No Employee Element to be updated.\n"; 
  return; 
 } 
 else 
 { 
  char ans; 
  for(int i=0;i<=index;i++) 
  { 
   if(id == p[i]->getEid()) 
   { 
    p[i]->Display(); 
    cout<<"\n\t Do you wish to change name (y/n) = "; 
    cin>>ans; 
    if(ans=='y' || ans=='Y') 
    { 
     char name[20]; 
     cout<<"\n\t Enter the new name = "; 
     cin>>name; 
     p[i]->setEname(name); 
    } 
    cout<<"\n\t Do you wish to change salary (y/n) = "; 
    cin>>ans; 
    if(ans == 'y' || ans == 'Y') 
    { 
     float sal; 
     cout<<"\n\t Enter new salary = "; 
     cin>>sal; 
     p[i]->setBasic(sal); 
    } 
    cout<<"\n\t DONE .."; 
    return; 
   } 
  } 
  cout<<"\n\t Element not found..!\n"; 
  return; 
 } 
} 
////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{
	char name[50] = "welcome to data structure session";
	int i,vowels = 0;
	for(i=0;name[i]!= '\0';i++)
	{
		if(name[i]== 'a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u')
		{
			vowels++;
		}
	}
	cout<<"no of vowels  = " <<vowels;
	
	return 0;
}

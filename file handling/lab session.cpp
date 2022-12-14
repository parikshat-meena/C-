#include <iostream>
#include<fstream>
using namespace std;

int main()
{	
	ifstream f("string.txt");
	char ch ;
	int count=0;
	while(!f.eof())
	{
		//fetch 1 character for file and store it in ch
		f.get(ch);
		if(ch == 'a' ||ch == 'e'||ch =='i' ||ch == 'o'||ch == 'u')
		{
			++count ;
		
		}
		cout<<ch;
	}
	cout<<"\nNo of vowels in string = "<<count;

	f.close();
	return 0;
}

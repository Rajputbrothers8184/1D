#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	struct student{
		int id,age;
		char name[30];
		float avg;
	};
	student s;
	cout<<"enter user ID\n";
	cin>>s.id;
	cout<<"enter your age";
	cin>>s.age;
	cout<<"enter your name";
	cin>>s.name[30];
	
}

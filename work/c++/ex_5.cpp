#include<iostream>
#include<string.h>
using namespace std;
class student
{
	private:
		int rollno;
		char name[12];
	public:
		student();
		student(int num,char *str);
		void setdata();
		void display();
};
student::student()
{

	rollno=0;
	strcpy(name,"none");

}
student::student(int num,char *str)
{
	rollno=num;
	strcpy(name,str);
}
void student::setdata()
{
	cout << "enter rollno:";
	cin >> rollno;
	cout << "enter marks:";
	cin >> name;
}
void student::display()
{

	cout << rollno << " " << name << endl;

}
int main()
{

	student s1(1,"sai");
	student s2(2,"mahi");

}

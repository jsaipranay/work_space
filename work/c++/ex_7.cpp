#include<iostream>
#include<string.h> 
using namespace std;
class student
{
	private:
		int rollno;
		char *name;
	public:
		student();
		student(int num,char *str);
		student(const student& ob);//deep copy
		
		void setdata();
		void changename(char *str){strcpy(name,str);}
		void display();
		//void deallocate() {delete [] name;}
		~student(); {delete [] name;}//destructor
};
student::student()
{
	cout << "default consructor" << endl;
	rollno = 0;
	name = new char[5];
	strcpy(name,"none");

}
student::student(int num,char *str)
{
	rollno = num;
	name = new char[strlen(str)+1];
	strcpy(name,str);
}
//student s2=s1;copy consturter for s2,s2.student(s1);
student::student(const student& ob)//deeep copy
{

	rollno = ob.rollno;
	name = new char[strlen(ob.name)+1];
	strcpy(name,ob.name);
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
/*void dosomething()
{

	student s1(22,"vishal");
	
	s1.display();
	s1.deallocate();
	student s2;
*/
}
int main()
{
	/*	student *ptr = NULL;
		ptr = new student;
		return 0;*/
	/*dosomething();
	


	student s1(1,"pradeep");
	student s2=s1;
	s1.display();
	s2.display();
	s2.changename("ajay");
	s1.display();
	s2.display();
	return 0;
*/


student s1(1,"pradeep");
student s2(2,"ajay");
s1=s2;
s1.changename("amit");
s1.display();
s1.display();
}

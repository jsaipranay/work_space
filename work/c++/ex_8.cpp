#include<iostream>
#include<stdio.h>
using namespace std;
class myclass
{
public:
	int a;
	static	int b;//static data member is shared by ojbecj
};
int myclass:: b=1000;

int main()
{

cout << myclass::b << endl;
myclass ob1;
myclass ob2;

ob1.a=10;
ob1.b=20;

ob2.a=30;
ob2.b=40;

cout << ob1.a << " " << ob1.b << endl;
cout << ob2.a << " " << ob2.b << endl;

return 0;


}

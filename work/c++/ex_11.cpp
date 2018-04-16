#include<iostrem>
#include<stdio.h>
using namespace std;
class Myclass{
public:
void dosomething(char *p,int x) const
{

        cout << "fourth fac" << endl;

}
void dosomething(char *p,int x)
{

	return x;

}
/*void dosomething(char *p,int x)
{
i
	cout << p << endl;

}*/
void dosomething(int x,char *p)
{

	cout << "int x " << x << endl;

}

};

int main()//1.no of argu,2.tyoe.3.order
{


	const Myclass ob1;
	Myclass ob2;
	dosomething("Hello",10);
	return 0;



}

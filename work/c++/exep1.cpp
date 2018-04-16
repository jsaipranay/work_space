#include<iostream>
using namespace std;
void dosomething()throw (int)
{
	try
	{

		int i;
		cout<<"enter a num:";
		cin >> i;
		if(i==0){
			throw i;
		}
		else
		{throw "something else";}

	}
	catch (int x)
	{

		cout << "rethrowing from dosomething:"<<endl;
		throw;//rethrow
	}



}
int main()
{

	try
	{
		dosomething();
	}	//suspected code to go here
	/*	int i;
		cout << "enter the num:";
		cin >> i;
		if(i==0){
		throw i;
		cout << "after throw" <<endl;
		}
		if(i<0)
		{
		throw "negative number";

		}
	//	else{throw 10.1;}

	}*/
//	cout << "iam in between try and catch";//error
catch (char* ptr)
{

	cout << ptr <<endl;


}


catch(int i)
{
	//block where you write erroe handleing codeor inform user
	cout << "the number is 0 "<<endl;
	cout << "after catch block"<<endl;



}
/*	catch(char *ptr)
	{

	cout <<ptr<<endl;


	}
 */	return 0; 
}

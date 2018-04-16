#include<iostream>
using namespace std;



int main()
{

	try
	{

		//suspected code to go here
		int i;
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
		
	}
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


#include<iostream>
using namespace std;
//function overriding
class computer
{

public:
	void calculateprice()
	{
		cout<<"25000"<<endl;
	}


};
class  laptop :public computer
{
public:
	void calculateprice()
	{
		cout<<"50000"<<endl;


	}



};
int main()
{
computer c1;
computer c2;
computer *pc=NULL;

c1.calculateprice();

laptop l1;
laptop l2;

l2.calculateprice();

return 0;

}

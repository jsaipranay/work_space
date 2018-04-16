#include<iostream>
#include<stdio.h>

class bankaccount
{
private:
	int accnum;
	double price;
	int duration;

	static double rate;
public:
	bankaccount(int num=0; double pri=0;int dur=0);
	{

		accnum=num;
		price=pri;
		duration=dur;
	}


	void calculatesum()
	{

	double sum=(price *duration *rate/100)+100;
	cout << sum << endl;	
	}

	void changerate(double r);
};
double bankaccount::rate=8.5;   
/*void bankaccount::changerate(double r);
{
	bankaccount::rate=r;

}*/
int main()
{

bankaccount ajay(1001,20000,5);
bankaccount sanjay(1002,100000,4);
ajay.calculatesum();
sanjay.calculatesum();

bankaccount::changerate(9);
ajay.calculatesum();
sanjay.calculatesum();


return 0;


}

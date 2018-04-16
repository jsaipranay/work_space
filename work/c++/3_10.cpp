#include<iostream>
using namespace std;
//function overriding
class computer
{
protected:
int id;

public:
        virtual void calculateprice()
        {
                cout<<"25000"<<endl;
        }


};
class  laptop :public computer
{
int modelno;
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

//c1.calculateprice();

laptop l1;
laptop l2;
laptop *pl=NULL;

pc=&l1;//up casting
//l2.calculateprice();
//pl=&c1;down casting not allowed	
//pc->calculateprice();//pc->laptop::calculateprice();
pc->calculateprice();


return 0;

}

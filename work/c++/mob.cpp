#include<iostream>
using namespace std;
class mobile
{
public:
int price;

};
class musicphone:virtual public mobile
{};
class cameraphone:virtual  public  mobile
{};
class modernphone:public musicphone ,public cameraphone
{};
  

int main()
{
modernphone n70;
n70.price=10000;
cout << n70.price <<endl;
}

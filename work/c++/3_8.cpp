#include<iostream>
using namespace std;
class upcounter
{
public:
void dosomething()
{
cout<< "hello from upcounter" <<endl;

}

};
class downcounter
{
public:
void dosomething()
{
cout <<"hello from downcounter"<< endl;
}
};
class mycounter:public upcounter,public downcounter
{};

int main()
{

mycounter ob;
ob.upcounter::dosomething();
ob.downcounter::dosomething();
return 0;
}

#include<iosream>
using namespace std;
int main()
{

int x=10;
int &y=x;
++y;
cout << x << endl;
cout << &x << " "<<&y <<endl;

}

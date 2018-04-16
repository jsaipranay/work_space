#include<iostream>
using namespace std;
class Mycounter
{
	private:
		int id;
		int numofevents;

	public:
		Mycounter(int i=0,int x=0):id(i),numofevents(x)
	{}
		Mycounteer & docountup()//oid docountup()

		{
			++numofevents;
			return *this;//this pointer
		}
		friend void docountdown(Mycounter& ob);//friend func
	
		void display()
		{
			cout << id << ":" <<numofevents << endl;
		}

	
};
void docountdown(Mycounter & ob)
{
	ob.numofevents--;
}
int main()
{

	Mycounter c1;
	Mucounter c2;
	c2=c1,docountup();
	
	c1.display();//0:1
	c1.display();//0:1
	return 0;

}

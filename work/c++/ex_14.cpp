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
	Mycounter&  operator++()
		{
		cout << "opertor ++ starts" << endl;
		++numofevents;
		return *this;
		}
		friend void operator--(Mycounter& ob);	
		friend void docountdown(Mycounter& ob);//friend func

		void display()
		{
			cout << id << ":" <<numofevents << endl;
		}


};
void opertaor--(Mycounter& ob);
{

ob.numofevents--;

}
int main()
{

	Mycounter c1;
	++c1;//
        --c1;
	c1.display();//0:1
	return 0;

}


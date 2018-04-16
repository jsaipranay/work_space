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
                Mycounter& docountup()//oid docountup()

                {
                        ++numofevents;
                        return *this;//this pointer
                }
		Mycounter operator+(const Mycounter& ob)
		{
			numofevents +ob.numofevents;
			temp.id=id+ob.id;
			

		}
		friend Mycounter operation-(Mycounter& ob1,Mycounter& ob2)

                friend Mycounter& operator--(Mycounter& ob);//friend func

                void display()
                {
                        cout << id << ":" <<numofevents << endl;
                }


Mycounter operation-(Mycounter& ob1,Mycounter& ob2)
{
	Mycounter temp;
	temp.id = ob1.id -ob2.id;
	temp.numofevents;
 
}
int main()
{

        Mycounter c1(0,1);
        Mucounter c2(1,33);
	Mycounter c3;
        c3=c1+c2;//c1.oper+(c2) 
        Mycounter c4;
	c4=c3-c1;
	return 0;

}


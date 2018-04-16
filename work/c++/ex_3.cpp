#include<iostream>
using namespace std;
#define MAX 10
class Mystack
{
	private:
		
		int arr[MAX];
		int index;
	public:
		//void init();
		Mystack();
		void push(int element);
		int pop();
		int top();
};
//void Mystack::init()
Mystack::Mystack()
{
	index=-1;
}
void Mystack::push(int element)
{
	if(index < MAX)
	{

		arr[++index] =element;
	}

}

int Mystack::pop()
{

	if(index >= 0)
	{

		int i=arr[index];
		index--;
		return i;


	}

}
int Mystack::top()
{
	if(index>=0)
	{

		return arr[index];
	}


}
int main()
{

	Mystack s1;
	//s1.init();
	s1.push(10);
	s1.push(20);	
	s1.push(30);	


	cout << s1.top() << endl;
	cout << s1.pop() << endl;

	cout << s1.top() << endl;
	return 0;

}

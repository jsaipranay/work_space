#include<stdio.h>
int Isempty();
void Insert(int data);
int Delete();
void Print();
int rear=-1,front=-1;
int A[10];
int size_A=sizeof(A)/sizeof(A[0]);
int main()
{

	insert(10);
	insert(20);
	insert(30);
	insert(40);
	delete();
	print();

}
int Isempty()
{

        if(rear==-1 && front==-1)
                return 1;
        else
                return 0;

    
} 
void insert(int data)
{

	if(Isempty())
		rear=front=0;
	else if(rear+1==front)
		printf("queue full\n");
	else
		rear=(rear+1)%size_A;
	A[rear]=data;
}

int delete()
{

	if(Isempty())
		printf("quqeu emepty\n");
	else
		front=(front+1)%size_A;
	A[front -1];


}
void print()
{
	int i;
	for(i=front;i<=rear;i++)

		printf("%d\t",A[i]);

}


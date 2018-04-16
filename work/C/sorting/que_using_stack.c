#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;

};
void push(struct node** top_ref,int new_data);
int pop(struct node** top_ref);



struct queue
{
    struct node *stack1;
    struct node *stack2;
};
void enqueue(struct queue *q,int x)
{
push(&q->stack1,x);

}
int dequeue(struct queue *q)
{

	int x;
	if(q->stack1==NULL && q->stack2==NULL)
	{
		printf("list is empy\n");
		exit(0);
	}
	if(q->stack1!=NULL)
	{
		x=pop(&q->stack1);
		push(&q->stack2,x);
	}
	x=pop(&q->stack2);
	return x;
}
void push(struct node** top_ref,int new_data)
{

	struct node *new_node= (struct node *) malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("stack flow\n");
		exit(0);
	}
	new_node->data=new_data;
	new_node->next=(*top_ref);
	(*top_ref)=new_node;
}
int pop(struct node** top_ref)
{

	int res;
	struct node *top;
	if(*top_ref==NULL)
	{
		printf("hiiistack overflow\n");
		exit(0);
	}
	else
	{
		top= *top_ref;
		res=top->data;
		*top_ref=top->next;
		free(top);
		return res;

	}
}

main()
{

    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
     
    
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));


}

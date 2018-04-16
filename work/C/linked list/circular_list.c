#include<stdio.h>
#include<stdlib.h>
struct node
{
int val;
struct node *next;
};
void push(struct node **head_ref,int x);
void print_list(struct node *head);

main()
{

struct node *head =NULL;
push(&head,10);
push(&head,20);
push(&head,30);
push(&head,40);

print_list(head);
}
void push(struct node **head_ref,int x)
{
	struct node *pnew=(struct node *) malloc(sizeof(struct node));
	struct node *temp=*head_ref;
	pnew->val=x;
	pnew->next=*head_ref;
	if(*head_ref !=NULL)
	{
		while(temp->next!= *head_ref)
			temp=temp->next;
		temp->next=pnew;
	}
	else
	pnew->next=pnew;
*head_ref=pnew;

}

void print_list(struct node *head)
{
	struct Node *temp = head;
	if(head!=NULL)
	{
		do
        	{
           		 printf("%d", temp->val);
           		 temp = temp->next;
        	}while (temp != head);

	
}

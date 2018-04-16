#include<stdio.h>
#include<stdlib.h>
#define RTRN main();

struct node
{
	struct node *prv;
	int val;
	struct node *next;
};

struct node *phead;
main()
{
	printf("\n");
	printf("1.Creat/add node\n");
	printf("2.Remove node from tail\n");
	printf("3.Add node to Head\n");
	printf("4.Remove node from Head\n");
	printf("5.Insert node\n");
	printf("6.Delete node\n");
	printf("7.Display\n");
	printf("8.Exit\n\n");
	printf("Select the abuve list:");
	
	int x,list;
	scanf("%d",&list);
	switch(list)
	{
		case 1: printf("Enter the value x:");
				scanf("%d",&x);
				creat_node(x);
				break;
			
		case 2:	remove_node();
				break;
				
		case 3: printf("Enter the value x:");
				scanf("%d",&x);
				add_node_to_head(x);
				break;
				
		case 4: remove_node_from_head();
				break;
				
		case 5:	printf("Enter the value x:");
				scanf("%d",&x);
				insert_node(x);
				break;
				
		case 6: printf("Enter the value x:");
				scanf("%d",&x);
				delete_node(x);
				break;
				
		case 7: display();
				break;
				
		case 8: exit(0);
				break;
		
		default: printf("Invalid Entry\n");
				 RTRN;
	}
	
}

creat_node(int x)
{
	struct node *pnew,*ptrav;
	pnew = malloc(sizeof(struct node));
	pnew->val = x;
	pnew->prv = NULL;
	pnew->next = NULL;
	
	if(phead == NULL)
	{
		phead = pnew;
		RTRN;
	}
	
	ptrav = phead;
	
	while(ptrav->next)
	{
		ptrav = ptrav->next;
	}
	
	ptrav->next = pnew;
	pnew->prv = ptrav;
	RTRN;
}

remove_node()
{
	struct node *ptrav;
	
	if(phead == NULL)
	{
		printf("List is Empty\n");
		RTRN;
	}
	
	ptrav = phead;
	
	while(ptrav->next)
	{
		ptrav = ptrav->next;
	}
	
	if(ptrav == phead)
	{
		phead = NULL;
		free(ptrav);
		RTRN;
	}

	ptrav->prv->next = NULL;
	free(ptrav);
	RTRN;
}

add_node_to_head(int x)
{
	struct node *pnew,*ptemp;
	pnew = malloc(sizeof(struct node));
	pnew->val = x;
	pnew->prv = NULL;
	pnew->next = NULL;
	
	if(phead == NULL)
	{
		phead = pnew;
		RTRN;
	}
	
	ptemp = phead;
	phead = pnew;
	phead->next = ptemp;
	ptemp->prv = pnew;
	RTRN;
}

remove_node_from_head()
{
	struct node *ptemp;
	
	if(phead == NULL)
	{
		printf("List is Empty\n");
		RTRN;
	}
	
	ptemp = phead;
	phead = phead->next;
	phead->prv = NULL;
	free(ptemp);
	RTRN;
}

insert_node(int x)
{
	struct node *pnew,*ptrav;
	pnew = malloc(sizeof(struct node));
	pnew->val = x;
	pnew->next = NULL;
	
	if(phead == NULL)
	{
		phead = pnew;
		RTRN;
	}
	
	ptrav = phead;
	
	while(ptrav->val < x)
	{
		ptrav = ptrav->next;
	}
	
	ptrav->prv->next = pnew;
	pnew->prv = ptrav->prv;
	ptrav->prv = pnew;
	pnew->next = ptrav;
	RTRN;
}

delete_node(int x)
{
	struct node *ptrav;
	
	if(phead == 0)
	{
		printf("List is Empty\n");
		RTRN;
	}
	
	ptrav = phead;
	
	while(ptrav->val == x)
	{
		ptrav = ptrav->next;
		
	}
	
	ptrav->prv->next = ptrav->next;
	free(ptrav);
	RTRN; 
}

display()
{
	struct node *ptrav;
	
	if(phead == NULL)
	{
		printf("List is Empty\n");
		RTRN;
	}
	
	ptrav = phead;
	printf("\n");
	while(ptrav)
	{
		printf("current node address:%p\npreves node address:%p\npresent node value:%d\nnext node address:%p\n\n",ptrav,ptrav->prv,ptrav->val,ptrav->next);
		ptrav = ptrav->next;
	}
	printf("\n");
	RTRN;
}



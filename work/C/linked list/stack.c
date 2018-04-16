struct node
{
	int val;
	struct node*next;

}*top==NULL;
void push(int val);
void pop();
void display();
main()
{
	int val,choice;
	scanf("%d",&choice);
	while(1)
	{
		printf("1.push\n...2.pop\n....3.display\n");
		switch(&choice);
		{
			case 1:printf("push the elements\n");
			       scanf("%d",&val);
			       push(val);
			       break;

			case 2:printf("pop\n");
			       pop();
			       break;
			case 3:printf("display\n");
			       display();
			       break;
			case 4:exit(0);
			default :printf("invlaid\n");
		}

	}


}
void push(int x)
{
	struct node*pnew;
	pnew=(struct node*)malloc(sizeof(struct node));
	pnew->val=x;
	if(top==NULL)
		pnew->next=NULL;
	else
		pnew->next=top;
	top=pnew;	
}
void pop()
{

	if(top==NULL)
		printf("empty\n");
	else
	{
		struct node*temp=top;
		top=temp->next;
		free(temp);
	}
}
void display()
{
	if(top==NULL)
		printf("full\n");
	else
	{
		struct node*temP=top;
		while(temp->next!=NULL)
		{

			printf("%d",temp->x);
			temp=temp->next;

		}
		printf("%d",temp->data);

	}

}

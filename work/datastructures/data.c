struct node *middle(struct node *phead)
{

struct node *fast=phead;
struct node *slow=phead;
while(fast!=NULL && fast->next->next!=NULL)
{
fast=fast->next->next;
slow=slow->next;

}
printf("%d",slow->data);


}
**********************************************
struct node *circular(struct node *phead)
{

struct node *fast=phead;
struct node *slow=phead;
while(fast!=NULL && fast->next->next!=NULL)
{
fast=fast->next->next;
slow=slow->next;
if(fast==slow)
	printf("same");
}

}
***********************************************
struct node *dummy(struct node *phead)
{
struct node *ptr;
struct node *temp=ptr->next;
ptr->next=temp->data;
ptr->next=temp->next;
free(temp);
}
***************************************************
struct node *dummysingle(struct node *phead)
{
struct node *mid;
int count=1;
while(phead!=NULL)
{

if(count%2==1)
{

mid=mid->next;
}
count++;
phead=phead->next;
}


printf("%d",mid->data);

}

*********************************
//#pair
struct node*pairswap(struct node *phead)
{

struct node*temp=phead;
while(temp!=NULL & temp->next->next!=NULL)
{
swap(&temp->data,&temp->next->data)
temp=temp->next->next;

}
swap(int *x,int *y)
{

int temp=*x;
*x=*y;
*y=temp;
}


} 
**********************************************

//delete node in soretd list
struct node *sorted(sturct node *phead)
{
struct node *ptemp=phead;
struct node *dup;
while(temp->data ==temp->next->data)
{
if()
{
dup=temp->data;
temp->nextt=dup->next;
free (dup)
}
else
{
temp=temp->next;

}

}

*************************************
//unsotered
struct node *unsotred(struct node *phead)
{
struct node *temp1=phead;
struct node *temp2;dup;
while(temp1!=NULL &&temp1->next->next!=NULL)
{
temp2=temp1;
while(temp2->next!=NULL)
{

if(temp->data==temp->next->data)
{
dup=temp2->next;
temp->next=dup->next;
free(dup)
}
else
{
temp2=temp2->next;

}
temp1=temp1->next;
}


}
}
*********************************
//reversing

struct node *reverse(struct node *phead)
{
struct node *p=NULL,q=phead,r;
while(q->next!=NULL)
{
r=q->next;
q->next=p
p=q;
q=r;

}
phead=p;

}

********************************************

//circular









}










}







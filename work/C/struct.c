#include<stdio.h>
struct book
{

char name[10];
int nop;
float price;


};

main()
{
	struct book *ptr={"linux",250,220.55};

	printf("%s...%d.....%f",ptr->name,ptr->nop,ptr->price);

}

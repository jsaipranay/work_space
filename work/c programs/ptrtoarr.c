#include<stdio.h> 
void fun ( int (*p)[2]  )
{
printf("%d\n",*(*(p + 1)+1));

}


int main(void)
{

int a [2][2] = {1,2,3,4};

fun (a);
return 0;
}

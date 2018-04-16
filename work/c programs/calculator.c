/****** calculator using  functio pointer *******/ 

#include<stdio.h> 
void add(int a,int b)
{
    printf("add fun\n");
    printf("sum = %d\n",a+b);
    return;
}
void sub(int a,int b)
{
    printf("sub fun\n");
    printf("sub = %d\n",a-b);
    return;
}

int main(void)
{
    int num;
    void (*fun[])(int,int) = { add,sub };

    printf("enter the number 0)add    1)sub\n");
//    fgets((char*)num,100,stdin);

  //  num = atoi((char*)&num);
   scanf("%d",&num);
    if(num>=0 && num<=1)
    {
       (*fun[num])(10,20);
    }

    return 0;
}

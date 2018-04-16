#include<stdio.h>           
int main()         
{
    int num , *ptr1 ,*ptr2 ;  

    ptr1 = &num ;
    ptr2 = ptr1 + 2 ;

    printf("%d",ptr2 - ptr1);

    return(0); 
}  

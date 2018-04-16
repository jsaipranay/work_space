#include<stdio.h> 
int main(void)
{
int i;
    char a[]="helloworld";
//    char str[10] =  "bye";
    char *s = "bye";;
    for(i=0;s[i];i++)
    {
        memset(a+i,s[i],1);
     //   s++;
        
    }
        printf("%s\n",a);
    return 0;
}

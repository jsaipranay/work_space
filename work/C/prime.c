#include<stdio.h>
void printNos(unsigned int n);
main()
{
int n;
n=1;


}
void printNos(unsigned int n)
{
  if(n > 0)
  {
    printNos(n-1);
    printf("%d ",  n);
  } 
}


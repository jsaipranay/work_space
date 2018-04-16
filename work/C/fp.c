#include<stdio.h>
add(float a,int b);

main()
{

float (*fp)(float, int);
float result;
//fp=add;
//result=(*fp)(5.6,5);
result=add(5.6,5);

printf("%f\t",result);
}
add(float a,int b)
{

return a+b;
}

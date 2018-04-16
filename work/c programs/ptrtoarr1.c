#include<stdio.h> 
fun (char  **p )
{
    printf("%d\n", sizeof (p));
printf("%s\n", (*(*(p+1))+1));
//printf("%p\n", (p));
//printf("%p\n", (p+1));

}
int main(void)
{
char a [][10] = {"anand","naresh", "mohan", "veera"};

fun (a);
}

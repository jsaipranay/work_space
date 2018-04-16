#include<stdio.h> 

void reverseWords( char * str )
{
    int i = 0, j = 0;
    reverseString( str, strlen(str) ); 
    printf("%s\n",str);


    while( 1 ) 
    {
        if( str[j] == ' ') 
        {
            reverseString( str+i, j-i );
            i = j+1;
        }
        if( str[j] == '\0')
        {
            break;
        }
        j++;
    }
} 
void reverseString(char* str, int len)
{
    int i, j;
    char temp;
    i=j=temp=0;

    j=len-1;
    for (i=0; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

int main(void)
{
    char a[100] = "i am fine";

    reverseWords(a);
    printf("%s\n",a);
    return 0;
}

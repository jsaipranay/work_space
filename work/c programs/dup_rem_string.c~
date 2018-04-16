#include<stdio.h>
#include<string.h>

void compact(char* str)
{
    int len = strlen(str);
    int a[100],i;
    char temp[len];

    for(i=0;i<len;i++)
    {
        int t = (int)str[i] - 65;
        if(a[t]!=1)
        {
            printf("%c",str[i]);
        }
        a[t] = 1;
    }
}

int main()
{
    compact("BANANAS");
    return 0;
}

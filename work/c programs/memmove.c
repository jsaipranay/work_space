#include<stdio.h> 
int main(void)
{
    char src[] = "hell";
    char dst[] = "btrryee";
    int n = 3,i;
    char *d = dst;
    char *s = src;

    if(dst == src)
    {
        printf("%s\n",dst);
    }
    if(dst < src)
    {
        for(i=0;i<3;i++)
            dst[i] = src[i];
        printf("%s\n",dst);
    }
    else
    {
        while(n--)
        {
            d[i] = s[i];
        }
        printf("%s",d);

    }
    return 0;
}

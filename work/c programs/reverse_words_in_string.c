#include<stdio.h>
void reverse(char *begin, char *end);
void reverseWords(char *s)
{
    char *word_begin = s;
    char *temp = s; /* temp is for word boundry */
    while( *temp )
    {
        temp++;
        if (*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    } 
    reverse(s, temp-1);
}

void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main()
{
    char s[] = "i like this program very much";
    char *temp = s;
    reverseWords(s);
    printf("%s", s);
    return 0;
}

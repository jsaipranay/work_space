# include <stdio.h>
# include <stdlib.h>
# define NO_OF_CHARS 256
# define bool int

char *removeDups(char *str)
{
    bool bin[NO_OF_CHARS] = {0};
    int i = 0, r = 0;
    char temp;    

    while (*(str + i))
    {

        temp = *(str + i);
        if (bin[temp] == 0)
        {
            bin[temp] = 1;

            *(str + r) = *(str + i);
            r++;
        }

        i++;
    }      

    *(str+r) = '\0';   

    return str;
}

int main()
{
    char str[] = "hellhweo";
    printf("%s", removeDups(str));
    getchar();
    return 0;
}



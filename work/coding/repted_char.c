#include<stdio.h>
#include<string.h>

void convert(char *s);

int main() {
    char string[] = "aaabbcccccccccddffffggaaaa";
    convert(string);
    printf("New string = %s\n", string);
    return 0;
}

void convert(char *s) {
    char *p = s;  // points to the character to process in the original string
    char *q = s;  // points to where the result (char + repeat-counter) comes
    int c;
    int counter;
    while (*p) {
        c = *p;
        counter = 0;
        while (*p && *p == c) {
            p++;
            counter++;
        }
        *q++ = c; 
        *q++ = counter+'0'; // simple solution if < 10 chars repeated
    }
    *q = 0;
}


/*void convert(char *s);
main()
{
	char str[]="abbcccddddeeee";
	convert(str);
	printf("%s\n",str);
	return 0;
}
void convert(char *s)
{
	char *p=s;
	char *q=s;
	int c;
	int counter;
	while(*p)
	{
		c = *p;
		counter=0;
		while(*p&&*p ==c)
		{
			p++;
			counter++;

		}
		*q++ = c;
                *q++ = counter+'0';	//	*q++ = counter+'0';
	}
	*q = 0;
}

*/

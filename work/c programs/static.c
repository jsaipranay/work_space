
static int fun();
int (*p[3])(void) = {fun,fun,fun}; 
static int fun()
{
printf("i am static fun\n");
return 10;
}


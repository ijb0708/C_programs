#include<stdio.h>

typedef struct _tag
{
	int acc;
}hello;

void em ()
{
	hello user;
	printf("%d", user.acc);
}

int main()
{
	hello user;
	user.acc=1;
	printf("%d\n", user.acc);
	em();
}

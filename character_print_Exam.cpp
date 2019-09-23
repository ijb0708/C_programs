#include<stdio.h>

int main()
{
	char a;
	
	printf("문자열입력: ");
	scanf("%c", &a, sizeof(a));
	printf("입력받은 문자열 %c \n", a);
}

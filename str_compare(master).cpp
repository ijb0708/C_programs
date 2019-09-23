#include<stdio.h>
#include<string.h>

int main()
{
	char str[5][10];
	char temp[10];
	bool flag;
	
	for(int i=0; i<5; i++)
	{
		scanf("%s", str[i]);
	}
	
	while (true) 
	{
		flag=true;
		
		for(int i=0; i<4; i++)
		{
			if(strncmp(str[i], str[i+1], 10)>0)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[i+1]);
				strcpy(str[i+1], temp);
     			flag=false;
			}
		}
		
		if(flag)
		break;
	}
	
	printf("\n");
	for(int i=0; i<5; i++)
	{
		printf("%s\n", str[i]);
	}
	
	return 0;
}

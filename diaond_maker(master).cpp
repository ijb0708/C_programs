#include<stdio.h>

int main()
{
	int r, c, max=0, p=0;
	int flag=0;
	
	scanf("%d %d", &r, &c);
	
	char arr[r][c];
	
	for(int i=0; i<r; i++)
	scanf("%s", arr[i]);

/*	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			arr[i][j]=1;
		}
	}
*/
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			p=max;
			while(true)
			{
				if(i-p>=0&&i+p<r&&j-p>=0&&j+p<c)
				{
					flag=1;
					for(int k=0; k<=p; k++)
					{	
						if(arr[i+(p-k)][j-k]!=49)
						{
							flag=0;
							break;
						}else if(arr[i+(p-k)][j+k]!=49)
						{
							flag=0;
							break;	
						}else if(arr[i-(p-k)][j-k]!=49)
						{
							flag=0;
							break;
						}else if(arr[i-(p-k)][j+k]!=49)
						{
							flag=0;
							break;
						}
					}
					p++;
					
					if(flag==1&&max<p)
					max=p;
				}
				else
				{
					break;
				}
			}
		}
	}
	printf("%d", max);
	
	return 0;
}



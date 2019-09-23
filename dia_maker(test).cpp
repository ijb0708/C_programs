#include<stdio.h>
#include<math.h>

int main()
{
	int x1, y1, x2, y2;
	int repeat, r1, r2;
	double length;
	
	scanf("%d", &repeat);
	
	int result[repeat];
	
	for(int i=0; i<repeat; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		length= sqrt( pow((double)(x1-x2),2) + pow((double)(y1-y2),2) );
		
		if(length==0)
		{
			if(r1==r2)
				result[i]=-1;
			else
				result[i]=0;	
		}
		else if(r1+r2==length||r1-r2==length||r2-r1==length)
			result[i]=1;
		else if(r1+r2<length||r1-r2>length||r2-r1>length)
			result[i]=0;
		else if(r1+r2>length||r1-r2<length||r2-r1<length)
			result[i]=2;
		
	}
	
	for(int i=0; i<repeat; i++)
		printf("%d\n", result[i]);

	return 0;
}

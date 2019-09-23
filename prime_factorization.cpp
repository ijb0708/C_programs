#include<stdio.h> 
#include<math.h>

int Prime_fac (int in);

int main () {
	
	int input;
	int div;
	
	printf("input:");
	scanf("%d", &input);
	
	
	while (input!=1) {
		div=Prime_fac(input);
		printf("%d ", div);
		input/=div;
	}
	
	return 0;
}

int Prime_fac (int in) {
	
	for (int i=2; i<=in; i++) {
		if(in%i==0) return i;
	}
}

//ver 0.1 

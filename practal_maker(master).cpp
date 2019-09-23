#include<stdio.h>
#include<stdlib.h>

int practal(int x, int y, int len);

bool arr[7000][7000]={0,};

int main() {
	int input;
	scanf("%d", &input);
	
	practal(0 , 0, input);
	for (int i=0; i<input; i++) {
		for (int j=0; j<input; j++) {
			if(arr[i][j]!=true) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	
	return 0;
}

int practal(int x, int y, int len) {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if(!(i==1&&j==1))arr[i+x][j+y]=true;
			if(!(i==1&&j==1)&&len!=1)practal(x+i*len, y+j*len, len/3);
		}
	}
}

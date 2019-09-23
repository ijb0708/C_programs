#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#define UP 53
#define DOWN 50
#define LEFT 49
#define RIGHT 51

#define LENGTH 40
#define HEIGHT 20 

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

void printBlock(int CurX, int CurY, int dir);
void movingBlock(int *CurX, int *CurY, int dir);
void printBoard();
void gotoxy(int CursorX, int CursorY);

int Board[HEIGHT][LENGTH]={0};

int air[2][3]=
{
	{0, 1, 0},
	{1, 1, 1}
};

int main()
{
	int key, dir;
	int x=4, y=4;
	
	while(true)
	{
		
		printBoard();
		key=getch();
		
		switch(key)
		{
			case UP:
				dir=DIR_UP;break;
			case DOWN:
				dir=DIR_DOWN;break;
			case LEFT:
				dir=DIR_LEFT;break;
			case RIGHT: 
				dir=DIR_RIGHT;break;
		}
		movingBlock(&x, &y, dir);
	}
	
	return 0;
}

void printBoard()
{
	gotoxy(0,0);
	for(int i=0; i<LENGTH; i++)
	{
		for(int j=0; j<HEIGHT; j++)
		{
			if(Board[i][j]==1)
			printf("1");
			else
			printf("0"); 
		}
		printf("\n");
	}
}

void movingBlock(int *CurX, int *CurY, int dir)
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(air[i][j]==1)
			Board[i+*CurY][j+*CurX]=0;
		}
	}
	
	switch(dir)
	{
		case DIR_UP:
			CurY--;break;
		case DIR_DOWN:
			CurY++;break;
		case DIR_LEFT:
			CurX--;break;
		case DIR_RIGHT:
			CurX++;break; 
	}
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(air[i][j]==1)
			Board[i+*CurY][j+*CurX]=air[i][j];
		}
	}
}

void printBlock(int CurX, int CurY, int dir)
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(Board[i+CurY][j+CurX]==1)
			{
				gotoxy((CurX+i)*2, CurY+j);
				printf("¤±");
			}
		}
	}
	
	switch(dir)
	{
		case DIR_UP :
			CurY--;break;
		case DIR_DOWN :
			CurY++;break;
		case DIR_LEFT :
			CurX++;break;
		case DIR_RIGHT :
			CurX--;break;
	}
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(Board[i+CurY][j+CurX]==0)
			{
				gotoxy((CurX+i)*2, CurY);
				printf("  ");
			}
		}
	}
}

void gotoxy(int CursorX, int CursorY)
{
	COORD pos={CursorX, CursorY};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

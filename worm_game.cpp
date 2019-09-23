/*******************************************************************************************************

this programs can run on the windows 
�� ���α׷��� �������� �󿡼� �����Ҽ� �ֽ��ϴ�.

Ver 0.1 

********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

//------------------------����Ű-------------------- 
#define UP 53
#define DOWN 50
#define LEFT 49
#define RIGHT 51

//------------------------�ʱ���-------------------- 
#define FLENGTH 30
#define FHEIGHT 15

//------------------------�Լ� ����-----------------
void keyLoad();
void gotoxy(int x, int y);
void hideCursor(bool show);
void make_board(int hei, int len);
void make_food();
void eat_food();
void moving_worm(int dir);
void Crash_worm();
void order_worm();
void print_worm();  
void Settings(); 
int game_over();

//-------------------�������� ����-------------------
typedef struct _tagLocation
{
	int x;
	int y;
}location;

int direction=1;
int worm_tail=1;
int score=0;
bool game=1;

location old;
location food;
location wormBody[500];

//-------------------���� ���α׷� ����---------------- 
int main ()
{
	
	wormBody[0].x=10;
	wormBody[0].y=10;
	
	Settings();
	make_board(FHEIGHT, FLENGTH);
	make_food();
	while(game!=0)
	{
		keyLoad ();
		order_worm();
		moving_worm(direction);
		print_worm();
		Crash_worm();
		eat_food();
		
		gotoxy(food.x,food.y);
		printf("O");
		
		if(direction==0||direction==2)
		Sleep(150);
		else
		Sleep(120);
		
		score++;
		
		gotoxy(4,17);
		printf("score: %d", score);
		
	}
	
		
	return 0;
}

//-------------------���ӿ��� �Լ�----------------  
int game_over()
{
	system("cls");
	gotoxy(FLENGTH/3,FHEIGHT/2);
		
	printf("Game Over ", score);
	
	game=0;
	return 0;
}

//-------------------�浹 ���� ��----------------  
void Crash_worm()
{
	if(wormBody[0].x==0||wormBody[0].x==FLENGTH-2||wormBody[0].y==0||wormBody[0].y==FHEIGHT)
	game_over();
	
	for (int i=1; i<worm_tail; i++)
	{
		if(wormBody[0].x==wormBody[i].x&&wormBody[0].y==wormBody[i].y)
		game_over();	
	}
	
}

//-------------------���� ��� �ϴ� �Լ�---------------- 
void print_worm()
{
	if(wormBody[0].x>0&&wormBody[0].x<=FLENGTH&&wormBody[0].y>=1&&wormBody[0].y<=FHEIGHT)
	{
		gotoxy(wormBody[0].x,wormBody[0].y);
		printf("X");
	}
	
	gotoxy(wormBody[worm_tail].x,wormBody[worm_tail].y);
	printf(" ");
}

//-------------------���� �迭�� �����ϴ� �Լ�----------------
void order_worm()
{
	for (int i=worm_tail; i>=0; i--)
	{
		wormBody[i+1].x=wormBody[i].x;
		wormBody[i+1].y=wormBody[i].y;
	} 
}
 
//-------------------���� �����̴� �Լ�----------------  
void moving_worm(int dir)
{
	switch (dir)
	{
		case 0: wormBody[0].y--;break;
		case 1: wormBody[0].x++;break;
		case 2: wormBody[0].y++;break;
		case 3: wormBody[0].x--;break;
	}
}

//-------------------���� ����� �Լ�----------------  
void make_board(int hei, int len)
{
	printf("%c", 0x1); 
	for (int i=0; i<len-3; i++)
	printf("%c", 0x6);
	printf("%c\n", 0x2);
	
	for (int i=0; i<hei-1; i++)
	{
		printf("%c", 0x5);
		for (int j=0; j<len-3; j++)
		printf(" ");
		printf("%c\n", 0x5);
	}
	
	printf("%c", 0x3);
	for (int i=0; i<len-3; i++)
	printf("%c", 0x6);
	printf("%c", 0x4);
	
}

//-------------------���� ����� �Լ�----------------  
void make_food()
{
	bool confirm;
	
	srand(time(NULL));
	food.x= (rand()%(FLENGTH-4))+2;
	food.y= (rand()%(FHEIGHT-2))+2;
	score++;
} 

//-------------------���ĸԴ� �Լ�----------------  
void eat_food()
{
	if(food.x==wormBody[0].x&&food.y==wormBody[0].y)
	{
		make_food();
		worm_tail++;
		printf("\a");
	}
} 

//-------------------����Ű �Է� �Լ�----------------  
void keyLoad ()
{
	
	while(kbhit())
	{
		int key=getch();
		switch (key)
		{
			case UP:
				if(direction!=2)direction=0;
				break;
			
			case DOWN:
				if(direction!=0)direction=2;
				break;
				
			case LEFT:
				if(direction!=1)direction=3;
				break;
			
			case RIGHT:
				if(direction!=3)direction=1;
				break;
		}
	}
}

//-------------------���� �Լ�----------------  
void Settings ()
{
	hideCursor(0);
	system("mode con cols=35 lines=20");
}

//-------------------Ŀ�� �����̴� �Լ�----------------  
void gotoxy (int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//-------------------Ŀ�� ����� �Լ�----------------  
void hideCursor (bool show)

{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

	



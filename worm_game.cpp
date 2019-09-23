/*******************************************************************************************************

this programs can run on the windows 
이 프로그램은 윈도우즈 상에서 실행할수 있습니다.

Ver 0.1 

********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

//------------------------방향키-------------------- 
#define UP 53
#define DOWN 50
#define LEFT 49
#define RIGHT 51

//------------------------맵길이-------------------- 
#define FLENGTH 30
#define FHEIGHT 15

//------------------------함수 선언-----------------
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

//-------------------전역변수 선언-------------------
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

//-------------------메인 프로그렘 실행---------------- 
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

//-------------------게임오버 함수----------------  
int game_over()
{
	system("cls");
	gotoxy(FLENGTH/3,FHEIGHT/2);
		
	printf("Game Over ", score);
	
	game=0;
	return 0;
}

//-------------------충돌 판정 함----------------  
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

//-------------------웜을 출력 하는 함수---------------- 
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

//-------------------웜의 배열을 정리하는 함수----------------
void order_worm()
{
	for (int i=worm_tail; i>=0; i--)
	{
		wormBody[i+1].x=wormBody[i].x;
		wormBody[i+1].y=wormBody[i].y;
	} 
}
 
//-------------------웜을 움직이는 함수----------------  
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

//-------------------판을 만드는 함수----------------  
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

//-------------------음식 만드는 함수----------------  
void make_food()
{
	bool confirm;
	
	srand(time(NULL));
	food.x= (rand()%(FLENGTH-4))+2;
	food.y= (rand()%(FHEIGHT-2))+2;
	score++;
} 

//-------------------음식먹는 함수----------------  
void eat_food()
{
	if(food.x==wormBody[0].x&&food.y==wormBody[0].y)
	{
		make_food();
		worm_tail++;
		printf("\a");
	}
} 

//-------------------방향키 입력 함수----------------  
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

//-------------------설정 함수----------------  
void Settings ()
{
	hideCursor(0);
	system("mode con cols=35 lines=20");
}

//-------------------커서 움직이는 함수----------------  
void gotoxy (int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//-------------------커서 숨기는 함수----------------  
void hideCursor (bool show)

{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

	



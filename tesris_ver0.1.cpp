/**************************************************

	해당소스는 윈도상에서 구동이가능합니다.
	기본환경 dev++ 콘솔
	
	this sorce can run in windows.
	basic environment is dev++ console
	
	ver 0.1

**************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define KEY_Z 122
#define KEY_X 120
#define SPACEBAR 32

#define MAKEX 0
#define MAKEY 0

#define WIDTH 12
#define HEIGHT 21

//윈도우함수	 
void gotoxy(int CursorX, int CursorY);
void hideCursor();

//처리용 함 수
void init();

void rightBlock();
void leftBlock();
void turnLeft();
void turnRight();

void makeBlock();
void pushBlock();
void downBlock();

bool crashBlock(int loX, int loY, int shp, int ang);
bool checkLine(int line);
void deleteLine(int line);
void sinkLine(int line);

//키함수
void keyLoad(); 

//그래픽함수 
void printBlock();
void removeBlock();
void rePaintBoard();

//게임오버	 
void gameOver();

//보드크기 
char Board[HEIGHT][WIDTH]={0};

//블럭모양 
bool Block[5][4][4][4]={
	//  ㅁ 
	0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0, 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0, 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0, 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,

	//	ㄱ
	0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0, 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0, 0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0, 0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,

	//  ㅣ 
	0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0, 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0, 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0, 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
	
	//	ㄱㄴ 
	0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0, 0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0, 0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0, 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,
	
	//  ㅜ
	0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0, 0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0, 0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0, 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,
};

bool isGame=false;

int curX;
int curY;
int shape=1;
int angle=0;

int main()
{
	init();
	
	makeBlock();
	
	while(true) {
		
		if(crashBlock(curX, curY+1, shape, angle)) {
			pushBlock();			 
			for (int i=0; i<HEIGHT-1; i++) {
				if(checkLine(i)) {
					deleteLine(i);
					sinkLine(i);
					rePaintBoard();
				}
			}
			makeBlock();
			if(isGame) break;
		}
		downBlock();
		keyLoad();
		
		Sleep(300);
		
	}
	
	gameOver();
	
	return 0;
}

bool checkLine(int line) {
	for (int i=1; i<WIDTH; i++) {
		if(Board[line][i]==0) return false;
	}
	
	return true;
}

void deleteLine(int line) {
	for (int i=1; i<WIDTH-1; i++) {
		Board[line][i]=0;
	}	
}

void sinkLine(int line) {
	for (int i=line; i>0; i--) {
		for (int j=1; j<WIDTH-1; j++) {
			Board[i][j]=Board[i-1][j];
		} 
	}
}

void rePaintBoard() {
	for (int i=0; i<HEIGHT-1; i++) {
		for (int j=1; j<WIDTH-1; j++) {
				gotoxy(j*2+MAKEX, i+MAKEY);
			if(Board[i][j]==1) printf("□");
			else printf("  ");
		}
	}
	
}

void keyLoad ()
{
	
	while(kbhit())
	{
		int key=getch();
		switch (key)
		{
			case LEFT:if(!crashBlock(curX-1,curY,shape,angle))leftBlock();break;
			case RIGHT:if(!crashBlock(curX+1,curY,shape,angle))rightBlock();break;
		}
		if(key==KEY_Z) if(!crashBlock(curX,curY,shape,angle-1==-1?3:angle-1))turnLeft();
		if(key==KEY_X) if(!crashBlock(curX,curY,shape,angle+1==4?0:angle+1))turnRight();
	}
}

void turnRight() {
	removeBlock();
	angle++;
	if(angle==4) angle=0;
	printBlock();
}

void turnLeft() {
	removeBlock();
	angle--;
	if(angle==-1) angle=3;
	printBlock();
}

void rightBlock() {
	removeBlock();
	curX++;
	printBlock();
}

void leftBlock() {
	removeBlock();
	curX--;
	printBlock();
}

void downBlock() {
	removeBlock();
	curY++;
	printBlock();
}

void makeBlock() {
	srand(time(NULL));
	shape=rand()%4;
	curX=4;
	curY=0;
	printBlock();
	if(crashBlock(curX, curY, shape, angle)) isGame=true;
}

bool crashBlock(int loX, int loY, int shp, int ang) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if(Block[shp][ang][i][j]==1&&Board[i+loY][j+loX]==1) return true;
		}
	}
	
	return false;
}

void printBlock() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if(Block[shape][angle][i][j]==1) {
				gotoxy((j+curX)*2+MAKEX, i+curY+MAKEY);
				printf("□");
			}
		}
	}
}

void removeBlock() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if(Block[shape][angle][i][j]==1) {
				gotoxy((j+curX)*2+MAKEX, i+curY+MAKEY);
				printf("  ");
			}
		}
	}
}

void pushBlock() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if(Block[shape][angle][i][j]==1) {
				Board[i+curY][j+curX]=1;
			}
		}
	}
}

void init() {
	hideCursor();
	system("mode con cols=25 lines=22");
	
	for (int i=0; i<HEIGHT; i++) {
		for (int j=0; j<WIDTH; j++) {
			if(j==0||j==WIDTH-1||i==HEIGHT-1) Board[i][j]=1;
		}
	}
	for (int i=0; i<HEIGHT; i++) {
		for (int j=0; j<WIDTH; j++) {
			gotoxy(MAKEX+j*2, MAKEY+i);
			if(Board[i][j]==1) { printf("■"); }
			else { printf("  "); }
		}
	}
}

void gameOver() {
	gotoxy(0,10);
	printf("-------gameOver-------");
	gotoxy(0,40);
	while(true);
} 

void gotoxy(int CursorX, int CursorY)
{
	COORD pos={CursorX, CursorY};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void hideCursor()
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

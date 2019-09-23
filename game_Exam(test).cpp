#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void gotoxy(int CurX, int CurY);
void Init();
void Update();
void Render();
void Release();

int frameCount=0;

int main() {
	
	return 0;
}

void Init() {
	
}

void Update() {
	
}

void Render() {
	
} 

void Release() {
	
}

void gotoxy(int CurX, int CurY){
	COORD CursorPosition = {CurX, CurY};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

//www.nowpress.co.kr

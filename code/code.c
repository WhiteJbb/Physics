#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

void menu();

int v0;
int x;
int t;
double cal;
double pox;
double poy;

double v0sinx;
double v0cosx;

double position();
double T();
double H();
double L();

void loading();


void main() {
	printf("---------------------------------------\n\n");
	printf(":: 포물선 운동 문제 계산기 ::\n");
	printf("\n---------------------------------------\n\n");
	printf(" (근사값으로 구하기 때문에 값이 정확하지 않을 수 있습니다.)\n");
	printf(" (중력가속도는 10으로 계산합니다.)\n");
	printf("                                  made by 동건\n");
	printf("\n---------------------------------------\n\n");
	printf("초기 속도를 입력해주세요 : ");
	scanf("%d", &v0);
	printf("\n시간변화량을 입력해주세요 : ");
	scanf("%d", &t);
	printf("\n던진 각도를 입력해주세요 : ");
	scanf("%d", &x);
	cal = ((double)x / 180) * 3.141592;
	loading();
}

void menu() {
	int sel;
	printf("---------------------------------------\n\n");
	printf("1. x, y 위치?\n");
	printf("2. 물체가 최고점에 도달하는 시간은?\n");
	printf("3. 물체가 도달하는 최고점의 높이는?\n");
	printf("4. 물체가 최고점인 경우 수평 이동거리?\n");
	printf("5. 종료\n\n");
	printf("---------------------------------------\n\n");
	printf("선택해주세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1:
		position();
		break;
	case 2:
		T();
		break;
	case 3:
		H();
		break;
	case 4:
		L();
		break;
	case 5:
		printf("---------------------------------------\n\n");
		printf(":: 프로그램을 종료합니다 ::\n");
		printf("\n---------------------------------------\n\n");
		exit(1);
	}
}

void loading() {
	system("cls");
	v0sinx = v0 * sin(cal);
	v0cosx = v0 * cos(cal);

	printf("---------------------------------------\n\n");
	printf(":: v0sinx와 v0cosx를 계산중입니다.... ::\n");
	Sleep(1000);
	printf(":: v0sinx = %2.3f, v0cosx = %2.3f ::\n", v0sinx, v0cosx);
	printf("\n---------------------------------------\n\n");
	Sleep(1000);
	menu();

}

double position() {
	pox = v0cosx * t;
	poy = (v0sinx * t) - (5 * (t * t));
	printf("---------------------------------------\n\n");
	printf(":: 물체의 x위치는 %2.2f 입니다::\n", pox);
	printf(":: 물체의 y위치는 %2.2f 입니다::\n", poy);
	printf("\n---------------------------------------\n\n");
	system("pause");
	system("cls");
	menu();

}

double T() {
	double h_time;
	h_time = v0sinx / 10;
	printf("---------------------------------------\n\n");
	printf(":: 물체가 최고점에 도달하는 시간은 %2.2f초 입니다::\n", h_time);
	printf("\n---------------------------------------\n\n");
	system("pause");
	system("cls");
	menu();
}

double H() {
	double height;
	height = (v0sinx * v0sinx )/ 20;
	printf("---------------------------------------\n\n");
	printf(":: 물체가 도달하는 최고점의 높이는 %2.2fm 입니다::\n", height);
	printf("\n---------------------------------------\n\n");
	system("pause");
	system("cls");
	menu();
}
double L() {
	double length;
	length = (v0 * v0) * sin( 2 * cal ) / 20;
	printf("---------------------------------------\n\n");
	printf(":: 물체가 이동한 수평거리는 %2.2fm 입니다::\n", length);
	printf("\n---------------------------------------\n\n");
	system("pause");
	system("cls");
	menu();
}
/*
khong giu lai dia chi
*/
#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdlib>
using namespace std;
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void xuong(int n,int x,int y,string s) {//len n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x,y+i);
		cout<<s;
		Sleep(100);
	}
}

void len(int n,int x,int y,string s) {//xuong n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x,y-i);
		cout<<s;
		Sleep(100);
	}
}

void phai(int n,int x,int y,string s) {//sang phai n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x+i,y);
		cout<<s;
		Sleep(100);
	}
}

void trai(int n,int x,int y,string s) {//sang trai n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x-i,y);
		cout<<s;
		Sleep(100);
	}
}

void xuong_phai(int n,int x,int y,string s) {//cheo n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x+i,y+i);
		cout<<s;
		Sleep(100);
	}
}

void xuong_trai(int n,int x,int y,string s) {//cheo n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x-i,y+i);
		cout<<s;
		Sleep(100);
	}
}

void len_trai(int n,int x,int y,string s) {//cheo n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x-i,y-i);
		cout<<s;
		Sleep(100);
	}
}


void len_phai(int n,int x,int y,string s) {//cheo n hang
	for(int i=0;i<n;i++){
		//system("cls");
		gotoxy(x+i,y-i);
		cout<<s;
		Sleep(100);
	}
}

main()
{
	string s;
	cin>>s;
	int x=0,y=0;
	system("cls");
	//m
	xuong(5,1,2,s);
	xuong_phai(3,1,2,s);
	len_phai(3,3,4,s);
	len(5,5,6,s);
	//a
	len(3,7,6,s);
	len_phai(3,7,4,s);
	xuong_phai(3,9,2,s);
	xuong(3,11,4,s);
	trai(3,10,4,s);
	//n
	len(5,13,6,s);
	xuong_phai(5,13,2,s);
	len(5,17,6,s);
	//h
	len(5,19,6,s);
	xuong(5,23,2,s);
	phai(5,19,4,s);
	trai(1,9,6,"*");
	Sleep(5000);
}





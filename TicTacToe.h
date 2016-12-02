#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <vector>
#include <utility>

using namespace std;

HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
INPUT_RECORD InRec;
DWORD NumRead;
CONSOLE_CURSOR_INFO info;
COORD margins ;
char Player1;
char Player2;
SMALL_RECT  r[1] ;




void Start_menu();
void multi_start();
void display();
void makebest(char arr[3][3],int &i , int &j);
bool sm1won(char arr[3][3],int a , int b);
void single_start ();
void single_game();
void multi_game();

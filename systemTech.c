#include "systemTech.h"
#include <windows.h>

void setBackgorundColor() { // выбор цвета текста консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void setRussianLanguage(){
    SetConsoleOutputCP(CP_UTF8);
}

void ClearConsole() { // очищение консоли
    system("cls");
}
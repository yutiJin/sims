#include "smsLib.h"

//�޸ı���
void SetTitle(char* title)
{
    SetConsoleTitle(title);
}

//�޸���ɫ
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}





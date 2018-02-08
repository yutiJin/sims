#include "smsLib.h"

//修改标题
void SetTitle(char* title)
{
    SetConsoleTitle(title);
}

//修改颜色
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}





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

//修改光标位置
void SetPosition(int x, int y)
{
    HANDLE winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(winHandle, pos);
}

//清空
void Clear(int x, int y, int rowCount)
{
    int i,j;
    for (i = 0; i < rowCount; i++ )
    {
        SetPosition(x, y + i);
        for (j = 0; j < 78 ;j++ )
        {
            printf(" ");
        }
    }
}




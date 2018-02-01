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

//�޸Ĺ��λ��
void SetPosition(int x, int y)
{
    HANDLE winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(winHandle, pos);
}

//���
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




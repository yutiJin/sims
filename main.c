#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sms.h"
#include "smsLib.h"


int main()
{
    Student * Stu;  //链表
    char key;       //我要输入的数字信息
    int stu_num = 0;    //我要查询的学生学号
    char ch;        //判断文件是否为空

    SetTitle("学生管理系统SMS");
    ShowWelcome();
    ShowMainInfo();

    Stu = (Student *)malloc(sizeof(Student));        //创建一个空间然后用stu这个指针指向
    Stu->next = NULL;
    FILE *fp;
    fp = fopen("data.txt", "wb");
    if (fp == NULL)
    {
        printf("该文件打开失败！\n");
    }
    ch = fgetc(fp);
    if (ch == EOF)
    {
        printf("现在的学生库是空的哦，请先添加！");
        //创建学生库
        CreateStuInfo(Stu);
    }
    else
    {
        while (1)
        {
            printf("\n请做出你艰难的选择，我看心情满足你：");
            fflush(stdin);
            key = getch();
            fflush(stdin);
            switch (key)
            {
            case '1':   //添加学生信息
                AddStuInfo(Stu);
                break;
            case '2':   //删除学生信息(根据学号)
                DeleteStuInfo(Stu, stu_num);
                //DeleteStuInfo(Stu);  //old
                break;
            case '3':   //修改学生信息(根据学号)
                UpdataStuInfo(Stu);
                break;
            case '4':   //查询学生信息(根据学号)
                ShowOneStuInfo(Stu);
                break;
            case '5':   //显示所有学生信息以及统计信息
                ShowStuInfo(Stu);
                break;
            case '6':   //退出
                break;
            default:
                break;
            }
        }
    }

    return 0;
}

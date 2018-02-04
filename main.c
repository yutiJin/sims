#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sms.h"
#include "smsLib.h"


int main()
{
    Student * Stu;  //链表
    char key;       //我要输入的数字信息

    SetTitle("学生管理系统SMS");
    ShowWelcome();
    ShowMainInfo();

    Stu = (Lstu)malloc(sizeof(Student));        //创建一个空间然后用stu这个指针指向
    Stu->next = NULL;

    //创建学生库
    CreateStuInfo(Stu);

    while (1)
    {
        SetPosition(MARGIN_X, INFO_END_Y);
        printf("请做出你艰难的选择，我看心情满足你：");
        fflush(stdin);
        key = getch();
        fflush(stdin);
        switch (key)
        {
        case '1':   //添加学生信息
            AddStuInfo(Stu);
            break;
        case '2':   //删除学生信息(根据学号)
            DeleteStuInfo(Stu);
            break;
        case '3':   //修改学生信息(根据学号)
            UpdataStuInfo(Stu);
            break;
        case '4':   //查询学生信息
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

    return 0;
}

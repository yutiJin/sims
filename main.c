#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sms.h"
#include "smsLib.h"


int main()
{
    Student * Stu;  //����
    char key;       //��Ҫ�����������Ϣ

    SetTitle("ѧ������ϵͳSMS");
    ShowWelcome();
    ShowMainInfo();

    Stu = (Lstu)malloc(sizeof(Student));        //����һ���ռ�Ȼ����stu���ָ��ָ��
    Stu->next = NULL;

    //����ѧ����
    CreateStuInfo(Stu);

    while (1)
    {
        SetPosition(MARGIN_X, INFO_END_Y);
        printf("����������ѵ�ѡ���ҿ����������㣺");
        fflush(stdin);
        key = getch();
        fflush(stdin);
        switch (key)
        {
        case '1':   //���ѧ����Ϣ
            AddStuInfo(Stu);
            break;
        case '2':   //ɾ��ѧ����Ϣ(����ѧ��)
            DeleteStuInfo(Stu);
            break;
        case '3':   //�޸�ѧ����Ϣ(����ѧ��)
            UpdataStuInfo(Stu);
            break;
        case '4':   //��ѯѧ����Ϣ
            ShowOneStuInfo(Stu);
            break;
        case '5':   //��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ
            ShowStuInfo(Stu);
            break;
        case '6':   //�˳�
            break;
        default:
            break;
        }


    }

    return 0;
}

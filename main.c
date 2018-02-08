#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sms.h"
#include "smsLib.h"


int main()
{
    Student * Stu;  //����
    char key;       //��Ҫ�����������Ϣ
    int stu_num = 0;    //��Ҫ��ѯ��ѧ��ѧ��
    char ch;        //�ж��ļ��Ƿ�Ϊ��

    SetTitle("ѧ������ϵͳSMS");
    ShowWelcome();
    ShowMainInfo();

    Stu = (Student *)malloc(sizeof(Student));        //����һ���ռ�Ȼ����stu���ָ��ָ��
    Stu->next = NULL;
    FILE *fp;
    fp = fopen("data.txt", "wb");
    if (fp == NULL)
    {
        printf("���ļ���ʧ�ܣ�\n");
    }
    ch = fgetc(fp);
    if (ch == EOF)
    {
        printf("���ڵ�ѧ�����ǿյ�Ŷ��������ӣ�");
        //����ѧ����
        CreateStuInfo(Stu);
    }
    else
    {
        while (1)
        {
            printf("\n����������ѵ�ѡ���ҿ����������㣺");
            fflush(stdin);
            key = getch();
            fflush(stdin);
            switch (key)
            {
            case '1':   //���ѧ����Ϣ
                AddStuInfo(Stu);
                break;
            case '2':   //ɾ��ѧ����Ϣ(����ѧ��)
                DeleteStuInfo(Stu, stu_num);
                //DeleteStuInfo(Stu);  //old
                break;
            case '3':   //�޸�ѧ����Ϣ(����ѧ��)
                UpdataStuInfo(Stu);
                break;
            case '4':   //��ѯѧ����Ϣ(����ѧ��)
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
    }

    return 0;
}

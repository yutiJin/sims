#include "sms.h"
#include "smsLib.h"


Student students[] = {
    {01, "С��", 'M', 18, {110, 98, 102,310}},
    {02, "�չ�", 'M', 18, {110, 98, 102,310}},
    {03, "����", 'M', 18, {110, 98, 102,310}},
    {04, "С��", 'F', 16, {110, 98, 102,310}}
};

void ShowWelcome()
{
    SetPosition(MARGIN_X, 0);
    printf(SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 32, 1);
    printf("��ѯѧ����Ϣ");
    SetPosition(MARGIN_X + 77, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf(SEP);
}

void ShowInfo()
{
    //��Ϣ���� ��������7��
    int i;
    for (i = 0; i < 7 ;i++ )
    {
        SetPosition(MARGIN_X, INFO_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + 77, INFO_START_Y + i);
        printf("|");
    }
    SetPosition(MARGIN_X, INFO_END_Y - 1);
    printf(SEP);
}

void ShowMainInfo()
{
    SetPosition(MARGIN_X + 10, INFO_START_Y);
    printf("1. ���ѧ����Ϣ");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
    printf("2. ɾ��ѧ����Ϣ(����ѧ��)");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
    printf("3. �޸�ѧ����Ϣ(����ѧ��)");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 3);
    printf("4. ��ѯѧ����Ϣ");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 4);
    printf("5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 5);
    printf("7. �˳�");
    ShowInfo();
}


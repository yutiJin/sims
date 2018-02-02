#include "sms.h"
#include "smsLib.h"
#include <conio.h>


/*Student students[] = {
    {01, "С��", 'M', 18, {110, 98, 102,310}},
    {02, "�չ�", 'M', 18, {110, 98, 102,310}},
    {03, "����", 'M', 18, {110, 98, 102,310}},
    {04, "С��", 'F', 16, {110, 98, 102,310}}
};
*/


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
    //��Ϣ���� ��������8��
    int i;
    for (i = 0; i < 8 ;i++ )
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
    SetPosition(MARGIN_X + 20, INFO_START_Y + 1);
    printf("1. ���ѧ����Ϣ");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 2);
    printf("2. ɾ��ѧ����Ϣ(����ѧ��)");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 3);
    printf("3. �޸�ѧ����Ϣ(����ѧ��)");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 4);
    printf("4. ��ѯѧ����Ϣ");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 5);
    printf("5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 6);
    printf("6. �˳�");
    ShowInfo();
}

/* 0. ����ѧ����Ϣ�� */
void CreateStuInfo(Student * L)
{
    Clear(MARGIN_X, INFO_END_Y + 1, 15);
    char flag = 'y';
    Student *p, *s;       //ָ�� �о���ѧϰ���ݽṹ�е�����ʱ������ָ���
    p = L;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("���ڵ�ѧ�����ǿյ�Ŷ��������ӣ�");
    while (flag == 'Y' || flag == 'y')
    {
        //�����ռ�
        s = (Lstu)malloc(sizeof(Student));
        SetPosition(MARGIN_X, INFO_END_Y + 2);
        printf("������ѧ��ѧ��:");
        scanf("%d", &s->stu_num);
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("������ѧ������:");
        scanf("%s", s->stu_name);
        SetPosition(MARGIN_X, INFO_END_Y + 4);
        printf("������ѧ���Ա�:");
        scanf("%s", s->stu_sex);           //ע���� С������ص� һ���˿�����
        SetPosition(MARGIN_X, INFO_END_Y + 5);
        printf("������ѧ����ѧ�ɼ�:");
        scanf("%d", &s->grades.Maths);
        SetPosition(MARGIN_X, INFO_END_Y + 6);
        printf("������ѧ�����ĳɼ�:");
        scanf("%d", &s->grades.Chinese);
        SetPosition(MARGIN_X, INFO_END_Y + 7);
        printf("������ѧ��Ӣ��ɼ�:");
        scanf("%d", &s->grades.English);

        //β�巨
        s->next = NULL;
        p->next = s;
        p = s;

        getchar();
        SetPosition(MARGIN_X, INFO_END_Y + 8);
        printf("�Ƿ����¼�룿(y/n): ");
        scanf("%c", &flag);
        if (flag == 'Y' || flag == 'y')
        {
            Clear(0, INFO_END_Y + 1, 9);
        }
        else if(flag == 'N' || flag == 'n')
        {
            Clear(0, INFO_END_Y + 1, 9);
            break;
        }
    }
}

/* 1. ���(����)ѧ����Ϣ */
void AddStuInfo(Student* L)
{
    Clear(MARGIN_X, INFO_END_Y + 1, 15);
    Student *p, *s;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("��ѡ����1. ���ѧ����Ϣ,��������Ŷ�������뿪ʼ��Ĺ����ɣ�");
    s = (Lstu)malloc(sizeof(Student));
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("������ѧ��ѧ��:");
    scanf("%d", &s->stu_num);
    SetPosition(MARGIN_X, INFO_END_Y + 3);
    printf("������ѧ������:");
    scanf("%s", s->stu_name);
    SetPosition(MARGIN_X, INFO_END_Y + 4);
    printf("������ѧ���Ա�:");
    scanf("%s", s->stu_sex);           //ע���� С������ص� һ���˿�����
    SetPosition(MARGIN_X, INFO_END_Y + 5);
    printf("������ѧ����ѧ�ɼ�:");
    scanf("%d", &s->grades.Maths);
    SetPosition(MARGIN_X, INFO_END_Y + 6);
    printf("������ѧ�����ĳɼ�:");
    scanf("%d", &s->grades.Chinese);
    SetPosition(MARGIN_X, INFO_END_Y + 7);
    printf("������ѧ��Ӣ��ɼ�:");
    scanf("%d", &s->grades.English);

    //β�巨
    s->next = NULL;
    p->next = s;
}

/* 2. ɾ��ѧ����Ϣ(����ѧ��) */  //��bug
void DeleteStuInfo(Student * L)
{
    Clear(MARGIN_X, INFO_END_Y + 1, 15);
    Student *p, *q;
    p = L;
    int num;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("��ѡ����2. ɾ��ѧ����Ϣ,��������Σ��Ŷ�������������㣡");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("����Ҫɾ����һ��ѧ������������ѧ�ţ��Ұ���㶨����");
    scanf("%d", &num);
    //ָ�붨λ��Ҫɾ�����ǰһ�����ɾ��
    int n = 0;
    int i;
    while ( p->stu_num != num)
    {
        p = p->next;
        n++;
    }
    p = L;
    for (i = 0; i < n ; i++ )
    {
        p = p->next;
    }
    if(p == NULL)
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("û����һ��������أ�");
    }
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }

}

/* 5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ */
void ShowStuInfo(Student * L)
{
    Clear(0, INFO_END_Y, 9);
    Student *p;
    p = L->next;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("�뿴��񰡣���Ͷ���������������Ҫ���ó������㣡\n");
    SetPosition(MARGIN_X + 4, INFO_END_Y + 2);
    puts("���\tѧ��\t����\t�Ա�\t��ѧ\t����\tӢ��\t�ܳɼ�");         //��ͷ
    SetPosition(MARGIN_X + 4, INFO_END_Y + 3);
    puts("====\t====\t====\t====\t====\t====\t====\t======\t");
    int count = 1;
    int total = 0;
    while (p)
    {
        total = p->grades.Maths + p->grades.Chinese + p->grades.English;
        SetPosition(MARGIN_X + 4, INFO_END_Y + 3 + count);
        printf("%2d\t%2d\t%s\t%2s\t%3d\t%3d\t%3d\t%4d\n", count, p->stu_num, p->stu_name, p->stu_sex, p->grades.Maths, p->grades.Chinese, p->grades.English, total);
        p = p->next;
        count++;
    }
}

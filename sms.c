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
    Clear(0, INFO_END_Y + 1, N);
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
    Clear(0, INFO_END_Y + 1, N);
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
    scanf("%s", s->stu_sex);
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

/* 2. ɾ��ѧ����Ϣ(����ѧ��) */  //2018-02-02��bug   2018-02-04�㶨  ˬ
void DeleteStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p, *s;
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
    for (i = 0; i < n - 1 ; i++ )
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
        s = p->next;
        p->next = s->next;
        free(s);
    }

}


/* 3. �޸�ѧ����Ϣ(����ѧ��) */
void UpdataStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p;
    p = L;
    int num;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("��ѡ����3. �޸�ѧ����Ϣ,������������ϸ�˰ɣ�");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("����Ҫ�޸���һ��ѧ������Ϣ������������ѧ�ţ��Ҳźð���Ŷ��");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("���Ҳ�����˵���Ǹ��ˣ�����ϸ����һ������ѧ�š�");
    }
    else
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("���ҵ����ͬѧ�ˣ���������Ҫ�޸ĵ����ݣ�");
        SetPosition(MARGIN_X, INFO_END_Y + 4);
        printf("������ѧ��ѧ��:");
        scanf("%d", &p->stu_num);
        SetPosition(MARGIN_X, INFO_END_Y + 5);
        printf("������ѧ������:");
        scanf("%s", p->stu_name);
        SetPosition(MARGIN_X, INFO_END_Y + 6);
        printf("������ѧ���Ա�:");
        scanf("%s", p->stu_sex);
        SetPosition(MARGIN_X, INFO_END_Y + 7);
        printf("������ѧ����ѧ�ɼ�:");
        scanf("%d", &p->grades.Maths);
        SetPosition(MARGIN_X, INFO_END_Y + 8);
        printf("������ѧ�����ĳɼ�:");
        scanf("%d", &p->grades.Chinese);
        SetPosition(MARGIN_X, INFO_END_Y + 9);
        printf("������ѧ��Ӣ��ɼ�:");
        scanf("%d", &p->grades.English);

    }

}

/* 4. ��ѯѧ����Ϣ(����ѧ��)*/
void ShowOneStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p;
    p = L;
    int num;
    int total = 0;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("��ѡ����4. ��ѯѧ����Ϣ,�뿴�˼ҵ�С����ѽ�����������ҡ�");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("����Ҫ���ĸ�ѧ������Ϣ������������ѧ�ţ��Ҳźð���͵������С����Ŷ��");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("���Ҳ�����˵���Ǹ��ˣ�����ϸ����һ������ѧ�š�");
    }
    else
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("���ҵ����ͬѧ�ˣ��쿴Ŷ�����������Ϣ�ɲ��������أ�");
        SetPosition(MARGIN_X + 4, INFO_END_Y + 4);
        puts("ѧ��\t����\t�Ա�\t��ѧ\t����\tӢ��\t�ܳɼ�");         //��ͷ
        SetPosition(MARGIN_X + 4, INFO_END_Y + 5);
        puts("====\t====\t====\t====\t====\t====\t======\t");
        total = p->grades.Maths + p->grades.Chinese + p->grades.English;
        SetPosition(MARGIN_X + 4, INFO_END_Y + 6);
        printf("%2d\t%s\t%2s\t%3d\t%3d\t%3d\t%4d\n",p->stu_num, p->stu_name, p->stu_sex, p->grades.Maths, p->grades.Chinese, p->grades.English, total);
    }
}


/* 5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ */
void ShowStuInfo(Student * L)
{
    Clear(0, INFO_END_Y, N);
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

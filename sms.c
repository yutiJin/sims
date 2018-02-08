#include "sms.h"
#include "smsLib.h"
#include <conio.h>

void ShowWelcome()
{
    printf(SEP);
    printf("\n * * * * * * * * * ��ѯѧ����Ϣ * * * * * * * * * \n");
    printf(SEP);
}

void ShowMainInfo()
{
    printf("\n\t1. ���ѧ����Ϣ\n");
    printf("\t2. ɾ��ѧ����Ϣ(����ѧ��)\n");
    printf("\t3. �޸�ѧ����Ϣ(����ѧ��)\n");
    printf("\t4. ��ѯѧ����Ϣ(����ѧ��)\n");
    printf("\t5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ\n");
    printf("\t6. �˳��ó���\n");
    printf(SEP);
    printf("\n");
}

/* ��ȡ�û���ѡ�� */
int Question(const char *str)
{
    char answer;
    printf("%s��ѡ��(y or n): ", str);
    while (scanf("%c", &answer) != 1)
    {
        printf("�������%s������ѡ��(y or n): ", str);
        fflush(stdin);
    }
    if (answer == 'y' || answer == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/* ����ָ��ѧ��ѧ������һ���ڵ� */

Student * GetPrevAddr(Student * L, int stu_num)
{
    Student *p;
    p = L;
    while (p->next)
    {
        if (p->next->stu_num == stu_num)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/* 0. ����ѧ����Ϣ��һ���ڵ� */
void CreateStuInfo(Student * L)
{
    int sex;
    int i = 0;
    Student *p, *s;       //ָ�� �о���ѧϰ���ݽṹ�е�����ʱ������ָ���
    p = L;

    while (1)
    {

        //�����ռ�
        s = (Student *)malloc(sizeof(Student));
        if (!s)
        {
            printf("�����ڴ�ռ�ʧ�ܣ�\n");
            return;
        }
        printf("\n������ѧ��ѧ��:");
        while (scanf("%d", &s->stu_num) != 1 || GetPrevAddr(p, s->stu_num))
        {
            printf("\nѧ��������������ѧ���Ѿ����ڣ�����������ѧ���ı�ţ����Σ���");
            fflush(stdin);
        }
        printf("\n������ѧ������:");
        scanf("%s", s->stu_name);
        printf("\n������ѧ���Ա�(1.�� 2.Ů):");
        while (scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
        {
            printf("\n�Ա�ѡ�����������ѡ��ѧ�����Ա�(1.�� 2.Ů)��");
            fflush(stdin);
        }
        if (sex == 1)
        {
            s->sex = MAN;
        }
        else
        {
            s->sex = WOMAN;
        }
        printf("\n������ѧ����ѧ�ɼ�:");
        scanf("%d", &s->grades.Maths);
        printf("\n������ѧ�����ĳɼ�:");
        scanf("%d", &s->grades.Chinese);
        printf("\n������ѧ��Ӣ��ɼ�:");
        scanf("%d", &s->grades.English);
        s->grades.total = s->grades.Maths + s->grades.Chinese + s->grades.English;
        printf("\n�ɵõ���λѧ�����ܳɼ�Ϊ��%d \n", s->grades.total);
        printf("\n");
        if (Question("ȷ��Ҫ����ǰѧ����Ϣ���浽�ļ�����"))
        {
            LinkToFile(s);

            //fwrite(s, sizeof(Student), 1, fp);  //��&studet���ָ����ָ������������fp����ļ���
            //��Ӧ�����������
        }
        else
        {
            return;
        }
        ++i;
        //β�巨
        s->next = NULL;
        p->next = s;
        p = s;
        free(s);
        getchar();
        if (Question("�Ƿ����¼�룿"))
        {
            system("cls");
        }
        else
        {
            system("cls");
            break;
        }
    }
    printf("\n�ɹ���д����%d��ѧ����Ϣ��\n", i);
}


/* 1. ���(����)ѧ����Ϣ */
void AddStuInfo(Student* L)
{
    int sex;
    Student *p, *s;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("\n��ѡ����1. ���ѧ����Ϣ,��������Ŷ�������뿪ʼ��Ĺ����ɣ�\n");

    s = (Student *)malloc(sizeof(Student));
    if (!s)
    {
        printf("�����ڴ�ռ�ʧ�ܣ�\n");
        //exit(0);
        return;
    }
    printf("������ѧ��ѧ��:");
    while (scanf("%d", &s->stu_num) != 1 || GetPrevAddr(p, s->stu_num))
    {
        printf("\nѧ��������������ѧ���Ѿ����ڣ�����������ѧ���ı�ţ����Σ���");
        fflush(stdin);
    }
    printf("\n������ѧ������:");
    scanf("%s", s->stu_name);
    printf("\n������ѧ���Ա�(1.�� 2.Ů):");
    while (scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
    {
        printf("\n�Ա�ѡ�����������ѡ��ѧ�����Ա�(1.�� 2.Ů)��");
        fflush(stdin);
    }
    if (sex == 1)
    {
        s->sex = MAN;
    }
    else
    {
        s->sex = WOMAN;
    }
    printf("\n������ѧ����ѧ�ɼ�:");
    scanf("%d ", &s->grades.Maths);
    printf("\n������ѧ�����ĳɼ�:");
    scanf("%d ", &s->grades.Chinese);
    printf("\n������ѧ��Ӣ��ɼ�:");
    scanf("%d ", &s->grades.English);
    s->grades.total = s->grades.Maths + s->grades.Chinese + s->grades.English;
    printf("\n�ɵõ���λѧ�����ܳɼ�Ϊ��%d \n", s->grades.total);
    printf("\n");
    if (!Question("ȷ��Ҫ����ǰѧ����Ϣ���浽�ļ�����"))
    {
        return;
    }
    else
    {
        LinkToFile(s);
        //fwrite(s, sizeof(Student), 1, fp);  //��&studet���ָ����ָ������������fp����ļ���
    }
    //β�巨
    s->next = NULL;
    p->next = s;
    free(s);
}

/* 2. ɾ��ѧ����Ϣ(����ѧ��) */  //2018-02-02��bug   2018-02-04�㶨  ˬ
/* ��ǰ��һ�ַ���
void DeleteStuInfo(Student * L)
{
    Student *p, *s;
    p = L;
    int num;
    printf("��ѡ����2. ɾ��ѧ����Ϣ,��������Σ��Ŷ�������������㣡\n");
    printf("����Ҫɾ����һ��ѧ������������ѧ�ţ��Ұ���㶨����\n");
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
        printf("û����һ��������أ�\n");
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(s);
    }

}
*/
//�·���
void DeleteStuInfo(Student * L, int stu_num)
{
    Student *p, *ps, *pt;
    p = L;
    if ((ps = GetPrevAddr(p, stu_num)))
    {
        if (!Question("ȷ��Ҫɾ����ѧ����Ϣ��"))
        {
            return;
        }
        pt = ps->next;
        ps->next = pt->next;
        free(pt);
        printf("ɾ����ѧ��Ϊ%d��ѧ����Ϣ\n", stu_num);
    }
    else
    {
        printf("û���ҵ�ѧ��Ϊ%d��ѧ����Ϣ\n", stu_num);
    }
}


/* 3. �޸�ѧ����Ϣ(����ѧ��) */
//�ɷ��� ��ɾ Ϊ�˶Ա�
void UpdataStuInfo(Student * L)
{
    int choose;
    Student *p;
    p = L;
    int num;
    printf("��ѡ����3. �޸�ѧ����Ϣ,������������ϸ�˰ɣ�\n");
    printf("����Ҫ�޸���һ��ѧ������Ϣ������������ѧ�ţ��Ҳźð���Ŷ��");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n���Ҳ�����˵���Ǹ��ˣ�����ϸ����һ������ѧ�š�");
    }
    else
    {
        printf("\n���ҵ����ͬѧ�ˣ���������Ҫ�޸ĵ����ݣ�");
        printf("\n��ǰѧ����ѧ��Ϊ%d:", p->stu_num);
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("������ѧ����ѧ�ţ�");
            scanf("%d", &p->stu_num);
        }
        printf("\n��ǰѧ��������Ϊ%s:", p->stu_name);
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("\n������ѧ�������֣�");
            scanf("%s", p->stu_name);
        }
        printf("\n��ǰѧ�����Ա�Ϊ%s:", p->sex == MAN ? "��" : "Ů");
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("\n������ѧ�����Ա�(1.�� 2.Ů)��");
            while (scanf("%d", &choose) != 1 || choose < 1 || choose > 2)
            {
                printf("\n�Ա�ѡ�����������ѡ��ѧ�����Ա�(1.�� 2.Ů)��");
                fflush(stdin);
            }
            if (choose == 1)
            {
                p->sex = MAN;
            }
            else
            {
                p->sex = WOMAN;
            }
        }
        printf("\n��ǰѧ������ѧ�ɼ�Ϊ%d:", p->grades.Maths);
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("ѧ������ѧ�ɼ���");
            scanf("%d", &p->grades.Maths);
        }
        printf("\n��ǰѧ�������ĳɼ�Ϊ%d:", p->grades.Chinese);
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("ѧ�������ĳɼ���");
            scanf("%d", &p->grades.Chinese);
        }
        printf("\n��ǰѧ����Ӣ��ɼ�Ϊ%d:", p->grades.English);
        if (Question("ȷ��Ҫ�޸���"))
        {
            printf("ѧ����Ӣ��ɼ���");
            scanf("%d", &p->grades.English);
        }
    }

}

/* 4. ��ѯѧ����Ϣ(����ѧ��)*/
void ShowOneStuInfo(Student * L)
{
    Student *p;
    p = L;
    int num;
    printf("\n��ѡ����4. ��ѯѧ����Ϣ,�뿴�˼ҵ�С����ѽ�����������ҡ�\n");
    printf("����Ҫ���ĸ�ѧ������Ϣ������������ѧ�ţ��Ҳźð���͵������С����Ŷ��");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n���Ҳ�����˵���Ǹ��ˣ�����ϸ����һ������ѧ�š�");
    }
    else
    {
        printf("\n���ҵ����ͬѧ�ˣ��쿴Ŷ�����������Ϣ�ɲ��������أ�");
        printf("\n");
        printf(SEP);
        puts("\nѧ��\t����\t�Ա�\t��ѧ\t����\tӢ��\t�ܳɼ�");         //��ͷ
        puts("\n====\t====\t====\t====\t====\t====\t======\t");
        printf("%2d\t", p->stu_num);
        printf("%s\t",  p->stu_name);
        printf("%3s\t", p->sex == MAN ? "��" : "Ů");
        printf("%3d\t", p->grades.Maths);
        printf("%3d\t", p->grades.Chinese);
        printf("%3d\t", p->grades.English);
        printf("%5d\n", p->grades.total);
        printf(SEP);
    }
}

/* �����е����ݱ��浽�ļ����� */
void LinkToFile(Student* L)
{
    FILE *fp;
    fp = fopen("data.txt", "wb");
    Student *p;

    if (fp == NULL)
    {
        printf("�򿪴�д����ļ�ʧ��.\n");
        return;
    }
    for (p = L; p != NULL ; p = p->next )
    {
        fprintf(fp,"%d\t", p->stu_num);
        fprintf(fp,"%s\t",  p->stu_name);
        fprintf(fp,"%s\t", p->sex == MAN ? "��" : "Ů");
        fprintf(fp,"%d\t", p->grades.Maths);
        fprintf(fp,"%d\t", p->grades.Chinese);
        fprintf(fp,"%d\t", p->grades.English);
        fprintf(fp,"%d\n", p->grades.total);
    }
    fclose(fp);
}


/* �ļ�������ʾ������������ */
Student * FiletoLink()
{
    FILE *fp;
    Student *p, *s, *L, temp;
    s = (Student *)malloc(sizeof(Student));  //һ���µĽڵ�
    L = s;       //��ͷ�ڵ����һ���ռ�
    p = s;
    p->next = NULL;

    fp = fopen("data.txt", "rb");
    while (fread(&temp, sizeof(Student), 1, fp) != 0 && p->next != NULL)
    {
        s = (Student *)malloc(sizeof(Student));
        s->stu_num = temp.stu_num;
        strcpy(s->stu_name, temp.stu_name);
        s->sex = temp.sex;
        s->grades.Maths = temp.grades.Maths;
        s->grades.Chinese = temp.grades.Chinese;
        s->grades.English = temp.grades.English;
        s->grades.total = temp.grades.total;

        //β�巨
        s->next = NULL;
        p->next = s;
        p = s;
    }
    fclose(fp);
    return L;
}

/* 5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ */
void ShowStuInfo(Student * L)
{
    int count = 0;
    Student *p;
    p = L;
    printf("\n�뿴��񰡣���Ͷ���������������Ҫ���ó������㣡\n");

    printf(SEP);
    puts("\nѧ��\t����\t�Ա�\t��ѧ\t����\tӢ��\t�ܳɼ�");         //��ͷ
    puts("===\t=====\t====\t====\t====\t====\t=======\t\n");
    while (p)
    {
        printf("%2d\t", p->stu_num);
        printf("%s\t",  p->stu_name);
        printf("%3s\t",  p->sex == MAN ? "��" : "Ů");
        printf("%3d\t", p->grades.Maths);
        printf("%3d\t", p->grades.Chinese);
        printf("%3d\t", p->grades.English);
        printf("%3d\t", p->grades.total);
        p = p->next;
        ++count;
    }
    printf("\n��ǰ����%dλѧ������Ϣ��\n", count);
    printf("\n");
    printf(SEP);
}






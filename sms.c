#include "sms.h"
#include "smsLib.h"
#include <conio.h>

void ShowWelcome()
{
    printf(SEP);
    printf("\n * * * * * * * * * 查询学生信息 * * * * * * * * * \n");
    printf(SEP);
}

void ShowMainInfo()
{
    printf("\n\t1. 添加学生信息\n");
    printf("\t2. 删除学生信息(根据学号)\n");
    printf("\t3. 修改学生信息(根据学号)\n");
    printf("\t4. 查询学生信息(根据学号)\n");
    printf("\t5. 显示所有学生信息以及统计信息\n");
    printf("\t6. 退出该程序\n");
    printf(SEP);
    printf("\n");
}

/* 获取用户的选择 */
int Question(const char *str)
{
    char answer;
    printf("%s请选择(y or n): ", str);
    while (scanf("%c", &answer) != 1)
    {
        printf("输入错误！%s请重新选择(y or n): ", str);
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


/* 返回指定学号学生的上一个节点 */

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

/* 0. 创建学生信息的一个节点 */
void CreateStuInfo(Student * L)
{
    int sex;
    int i = 0;
    Student *p, *s;       //指针 感觉在学习数据结构中的链表时都是用指针的
    p = L;

    while (1)
    {

        //创建空间
        s = (Student *)malloc(sizeof(Student));
        if (!s)
        {
            printf("申请内存空间失败！\n");
            return;
        }
        printf("\n请输入学生学号:");
        while (scanf("%d", &s->stu_num) != 1 || GetPrevAddr(p, s->stu_num))
        {
            printf("\n学生编号输入错误或此学号已经存在，请重新输入学生的编号（整形）：");
            fflush(stdin);
        }
        printf("\n请输入学生名字:");
        scanf("%s", s->stu_name);
        printf("\n请输入学生性别(1.男 2.女):");
        while (scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
        {
            printf("\n性别选择错误，请重新选择学生的性别(1.男 2.女)：");
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
        printf("\n请输入学生数学成绩:");
        scanf("%d", &s->grades.Maths);
        printf("\n请输入学生语文成绩:");
        scanf("%d", &s->grades.Chinese);
        printf("\n请输入学生英语成绩:");
        scanf("%d", &s->grades.English);
        s->grades.total = s->grades.Maths + s->grades.Chinese + s->grades.English;
        printf("\n可得到这位学生的总成绩为：%d \n", s->grades.total);
        printf("\n");
        if (Question("确定要将当前学生信息保存到文件中吗？"))
        {
            LinkToFile(s);

            //fwrite(s, sizeof(Student), 1, fp);  //将&studet这个指针所指向的内容输出到fp这个文件中
            //这应该是有问题的
        }
        else
        {
            return;
        }
        ++i;
        //尾插法
        s->next = NULL;
        p->next = s;
        p = s;
        free(s);
        getchar();
        if (Question("是否继续录入？"))
        {
            system("cls");
        }
        else
        {
            system("cls");
            break;
        }
    }
    printf("\n成功的写入了%d条学生信息。\n", i);
}


/* 1. 添加(插入)学生信息 */
void AddStuInfo(Student* L)
{
    int sex;
    Student *p, *s;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("\n你选择了1. 添加学生信息,辛苦你了哦，现在请开始你的工作吧！\n");

    s = (Student *)malloc(sizeof(Student));
    if (!s)
    {
        printf("申请内存空间失败！\n");
        //exit(0);
        return;
    }
    printf("请输入学生学号:");
    while (scanf("%d", &s->stu_num) != 1 || GetPrevAddr(p, s->stu_num))
    {
        printf("\n学生编号输入错误或该学号已经存在，请重新输入学生的编号（整形）：");
        fflush(stdin);
    }
    printf("\n请输入学生名字:");
    scanf("%s", s->stu_name);
    printf("\n请输入学生性别(1.男 2.女):");
    while (scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
    {
        printf("\n性别选择错误，请重新选择学生的性别(1.男 2.女)：");
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
    printf("\n请输入学生数学成绩:");
    scanf("%d ", &s->grades.Maths);
    printf("\n请输入学生语文成绩:");
    scanf("%d ", &s->grades.Chinese);
    printf("\n请输入学生英语成绩:");
    scanf("%d ", &s->grades.English);
    s->grades.total = s->grades.Maths + s->grades.Chinese + s->grades.English;
    printf("\n可得到这位学生的总成绩为：%d \n", s->grades.total);
    printf("\n");
    if (!Question("确定要将当前学生信息保存到文件中吗？"))
    {
        return;
    }
    else
    {
        LinkToFile(s);
        //fwrite(s, sizeof(Student), 1, fp);  //将&studet这个指针所指向的内容输出到fp这个文件中
    }
    //尾插法
    s->next = NULL;
    p->next = s;
    free(s);
}

/* 2. 删除学生信息(根据学号) */  //2018-02-02有bug   2018-02-04搞定  爽
/* 以前的一种方法
void DeleteStuInfo(Student * L)
{
    Student *p, *s;
    p = L;
    int num;
    printf("你选择了2. 删除学生信息,你这样很危险哦，但是我满足你！\n");
    printf("你想要删除哪一个学生，告诉他的学号，我帮你搞定他：\n");
    scanf("%d", &num);
    //指针定位到要删除项的前一项进行删除
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
        printf("没有这一项！逗我玩呢！\n");
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(s);
    }

}
*/
//新方法
void DeleteStuInfo(Student * L, int stu_num)
{
    Student *p, *ps, *pt;
    p = L;
    if ((ps = GetPrevAddr(p, stu_num)))
    {
        if (!Question("确定要删除该学生信息？"))
        {
            return;
        }
        pt = ps->next;
        ps->next = pt->next;
        free(pt);
        printf("删除了学号为%d的学生信息\n", stu_num);
    }
    else
    {
        printf("没有找到学号为%d的学生信息\n", stu_num);
    }
}


/* 3. 修改学生信息(根据学号) */
//旧方法 不删 为了对比
void UpdataStuInfo(Student * L)
{
    int choose;
    Student *p;
    p = L;
    int num;
    printf("你选择了3. 修改学生信息,哈哈哈，不仔细了吧！\n");
    printf("你想要修改哪一个学生的信息，告诉我他的学号，我才好帮你哦：");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n我找不到你说的那个人，你仔细回忆一下他的学号。");
    }
    else
    {
        printf("\n我找到这个同学了，请输入你要修改的内容：");
        printf("\n当前学生的学号为%d:", p->stu_num);
        if (Question("确定要修改吗？"))
        {
            printf("请输入学生的学号：");
            scanf("%d", &p->stu_num);
        }
        printf("\n当前学生的名字为%s:", p->stu_name);
        if (Question("确定要修改吗？"))
        {
            printf("\n请输入学生的名字：");
            scanf("%s", p->stu_name);
        }
        printf("\n当前学生的性别为%s:", p->sex == MAN ? "男" : "女");
        if (Question("确认要修改吗？"))
        {
            printf("\n请输入学生的性别(1.男 2.女)：");
            while (scanf("%d", &choose) != 1 || choose < 1 || choose > 2)
            {
                printf("\n性别选择错误，请重新选择学生的性别(1.男 2.女)：");
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
        printf("\n当前学生的数学成绩为%d:", p->grades.Maths);
        if (Question("确认要修改吗？"))
        {
            printf("学生的数学成绩：");
            scanf("%d", &p->grades.Maths);
        }
        printf("\n当前学生的语文成绩为%d:", p->grades.Chinese);
        if (Question("确认要修改吗？"))
        {
            printf("学生的语文成绩：");
            scanf("%d", &p->grades.Chinese);
        }
        printf("\n当前学生的英语成绩为%d:", p->grades.English);
        if (Question("确认要修改吗？"))
        {
            printf("学生的英语成绩：");
            scanf("%d", &p->grades.English);
        }
    }

}

/* 4. 查询学生信息(根据学号)*/
void ShowOneStuInfo(Student * L)
{
    Student *p;
    p = L;
    int num;
    printf("\n你选择了4. 查询学生信息,想看人家的小秘密呀，快来告诉我。\n");
    printf("你想要看哪个学生的信息，告诉我他的学号，我才好帮你偷窥他的小秘密哦：");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n我找不到你说的那个人，你仔细回忆一下他的学号。");
    }
    else
    {
        printf("\n我找到这个同学了，快看哦，我找这个信息可不容易了呢！");
        printf("\n");
        printf(SEP);
        puts("\n学号\t名字\t性别\t数学\t语文\t英语\t总成绩");         //表头
        puts("\n====\t====\t====\t====\t====\t====\t======\t");
        printf("%2d\t", p->stu_num);
        printf("%s\t",  p->stu_name);
        printf("%3s\t", p->sex == MAN ? "男" : "女");
        printf("%3d\t", p->grades.Maths);
        printf("%3d\t", p->grades.Chinese);
        printf("%3d\t", p->grades.English);
        printf("%5d\n", p->grades.total);
        printf(SEP);
    }
}

/* 链表中的内容保存到文件当中 */
void LinkToFile(Student* L)
{
    FILE *fp;
    fp = fopen("data.txt", "wb");
    Student *p;

    if (fp == NULL)
    {
        printf("打开待写入的文件失败.\n");
        return;
    }
    for (p = L; p != NULL ; p = p->next )
    {
        fprintf(fp,"%d\t", p->stu_num);
        fprintf(fp,"%s\t",  p->stu_name);
        fprintf(fp,"%s\t", p->sex == MAN ? "男" : "女");
        fprintf(fp,"%d\t", p->grades.Maths);
        fprintf(fp,"%d\t", p->grades.Chinese);
        fprintf(fp,"%d\t", p->grades.English);
        fprintf(fp,"%d\n", p->grades.total);
    }
    fclose(fp);
}


/* 文件内容显示到数据链表中 */
Student * FiletoLink()
{
    FILE *fp;
    Student *p, *s, *L, temp;
    s = (Student *)malloc(sizeof(Student));  //一个新的节点
    L = s;       //给头节点分配一个空间
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

        //尾插法
        s->next = NULL;
        p->next = s;
        p = s;
    }
    fclose(fp);
    return L;
}

/* 5. 显示所有学生信息以及统计信息 */
void ShowStuInfo(Student * L)
{
    int count = 0;
    Student *p;
    p = L;
    printf("\n想看表格啊，这就对啦，做出来就是要多拿出来秀秀！\n");

    printf(SEP);
    puts("\n学号\t名字\t性别\t数学\t语文\t英语\t总成绩");         //表头
    puts("===\t=====\t====\t====\t====\t====\t=======\t\n");
    while (p)
    {
        printf("%2d\t", p->stu_num);
        printf("%s\t",  p->stu_name);
        printf("%3s\t",  p->sex == MAN ? "男" : "女");
        printf("%3d\t", p->grades.Maths);
        printf("%3d\t", p->grades.Chinese);
        printf("%3d\t", p->grades.English);
        printf("%3d\t", p->grades.total);
        p = p->next;
        ++count;
    }
    printf("\n当前共有%d位学生的信息。\n", count);
    printf("\n");
    printf(SEP);
}






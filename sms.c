#include "sms.h"
#include "smsLib.h"
#include <conio.h>


/*Student students[] = {
    {01, "小明", 'M', 18, {110, 98, 102,310}},
    {02, "刚锅", 'M', 18, {110, 98, 102,310}},
    {03, "阿亮", 'M', 18, {110, 98, 102,310}},
    {04, "小鱼", 'F', 16, {110, 98, 102,310}}
};
*/


void ShowWelcome()
{
    SetPosition(MARGIN_X, 0);
    printf(SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 32, 1);
    printf("查询学生信息");
    SetPosition(MARGIN_X + 77, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf(SEP);
}

void ShowInfo()
{
    //信息窗口 假设先是8行
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
    printf("1. 添加学生信息");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 2);
    printf("2. 删除学生信息(根据学号)");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 3);
    printf("3. 修改学生信息(根据学号)");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 4);
    printf("4. 查询学生信息");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 5);
    printf("5. 显示所有学生信息以及统计信息");
    SetPosition(MARGIN_X + 20, INFO_START_Y + 6);
    printf("6. 退出");
    ShowInfo();
}

/* 0. 创建学生信息库 */
void CreateStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    char flag = 'y';
    Student *p, *s;       //指针 感觉在学习数据结构中的链表时都是用指针的
    p = L;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("现在的学生库是空的哦，请先添加！");
    while (flag == 'Y' || flag == 'y')
    {
        //创建空间
        s = (Lstu)malloc(sizeof(Student));
        SetPosition(MARGIN_X, INFO_END_Y + 2);
        printf("请输入学生学号:");
        scanf("%d", &s->stu_num);
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("请输入学生名字:");
        scanf("%s", s->stu_name);
        SetPosition(MARGIN_X, INFO_END_Y + 4);
        printf("请输入学生性别:");
        scanf("%s", s->stu_sex);           //注意了 小鱼儿的重点 一般人看不懂
        SetPosition(MARGIN_X, INFO_END_Y + 5);
        printf("请输入学生数学成绩:");
        scanf("%d", &s->grades.Maths);
        SetPosition(MARGIN_X, INFO_END_Y + 6);
        printf("请输入学生语文成绩:");
        scanf("%d", &s->grades.Chinese);
        SetPosition(MARGIN_X, INFO_END_Y + 7);
        printf("请输入学生英语成绩:");
        scanf("%d", &s->grades.English);

        //尾插法
        s->next = NULL;
        p->next = s;
        p = s;

        getchar();
        SetPosition(MARGIN_X, INFO_END_Y + 8);
        printf("是否继续录入？(y/n): ");
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

/* 1. 添加(插入)学生信息 */
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
    printf("你选择了1. 添加学生信息,辛苦你了哦，现在请开始你的工作吧！");
    s = (Lstu)malloc(sizeof(Student));
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("请输入学生学号:");
    scanf("%d", &s->stu_num);
    SetPosition(MARGIN_X, INFO_END_Y + 3);
    printf("请输入学生名字:");
    scanf("%s", s->stu_name);
    SetPosition(MARGIN_X, INFO_END_Y + 4);
    printf("请输入学生性别:");
    scanf("%s", s->stu_sex);
    SetPosition(MARGIN_X, INFO_END_Y + 5);
    printf("请输入学生数学成绩:");
    scanf("%d", &s->grades.Maths);
    SetPosition(MARGIN_X, INFO_END_Y + 6);
    printf("请输入学生语文成绩:");
    scanf("%d", &s->grades.Chinese);
    SetPosition(MARGIN_X, INFO_END_Y + 7);
    printf("请输入学生英语成绩:");
    scanf("%d", &s->grades.English);

    //尾插法
    s->next = NULL;
    p->next = s;
}

/* 2. 删除学生信息(根据学号) */  //2018-02-02有bug   2018-02-04搞定  爽
void DeleteStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p, *s;
    p = L;
    int num;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("你选择了2. 删除学生信息,你这样很危险哦，但是我满足你！");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("你想要删除哪一个学生，告诉他的学号，我帮你搞定他：");
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
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("没有这一项！逗我玩呢！");
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(s);
    }

}


/* 3. 修改学生信息(根据学号) */
void UpdataStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p;
    p = L;
    int num;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("你选择了3. 修改学生信息,哈哈哈，不仔细了吧！");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("你想要修改哪一个学生的信息，告诉我他的学号，我才好帮你哦：");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("我找不到你说的那个人，你仔细回忆一下他的学号。");
    }
    else
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("我找到这个同学了，请输入你要修改的内容：");
        SetPosition(MARGIN_X, INFO_END_Y + 4);
        printf("请输入学生学号:");
        scanf("%d", &p->stu_num);
        SetPosition(MARGIN_X, INFO_END_Y + 5);
        printf("请输入学生名字:");
        scanf("%s", p->stu_name);
        SetPosition(MARGIN_X, INFO_END_Y + 6);
        printf("请输入学生性别:");
        scanf("%s", p->stu_sex);
        SetPosition(MARGIN_X, INFO_END_Y + 7);
        printf("请输入学生数学成绩:");
        scanf("%d", &p->grades.Maths);
        SetPosition(MARGIN_X, INFO_END_Y + 8);
        printf("请输入学生语文成绩:");
        scanf("%d", &p->grades.Chinese);
        SetPosition(MARGIN_X, INFO_END_Y + 9);
        printf("请输入学生英语成绩:");
        scanf("%d", &p->grades.English);

    }

}

/* 4. 查询学生信息(根据学号)*/
void ShowOneStuInfo(Student * L)
{
    Clear(0, INFO_END_Y + 1, N);
    Student *p;
    p = L;
    int num;
    int total = 0;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("你选择了4. 查询学生信息,想看人家的小秘密呀，快来告诉我。");
    SetPosition(MARGIN_X, INFO_END_Y + 2);
    printf("你想要看哪个学生的信息，告诉我他的学号，我才好帮你偷窥他的小秘密哦：");
    scanf("%d", &num);
    while ( p->stu_num != num)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("我找不到你说的那个人，你仔细回忆一下他的学号。");
    }
    else
    {
        SetPosition(MARGIN_X, INFO_END_Y + 3);
        printf("我找到这个同学了，快看哦，我找这个信息可不容易了呢！");
        SetPosition(MARGIN_X + 4, INFO_END_Y + 4);
        puts("学号\t名字\t性别\t数学\t语文\t英语\t总成绩");         //表头
        SetPosition(MARGIN_X + 4, INFO_END_Y + 5);
        puts("====\t====\t====\t====\t====\t====\t======\t");
        total = p->grades.Maths + p->grades.Chinese + p->grades.English;
        SetPosition(MARGIN_X + 4, INFO_END_Y + 6);
        printf("%2d\t%s\t%2s\t%3d\t%3d\t%3d\t%4d\n",p->stu_num, p->stu_name, p->stu_sex, p->grades.Maths, p->grades.Chinese, p->grades.English, total);
    }
}


/* 5. 显示所有学生信息以及统计信息 */
void ShowStuInfo(Student * L)
{
    Clear(0, INFO_END_Y, N);
    Student *p;
    p = L->next;
    SetPosition(MARGIN_X, INFO_END_Y + 1);
    printf("想看表格啊，这就对啦，做出来就是要多拿出来秀秀！\n");
    SetPosition(MARGIN_X + 4, INFO_END_Y + 2);
    puts("编号\t学号\t名字\t性别\t数学\t语文\t英语\t总成绩");         //表头
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

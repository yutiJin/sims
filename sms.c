#include "sms.h"
#include "smsLib.h"


Student students[] = {
    {01, "小明", 'M', 18, {110, 98, 102,310}},
    {02, "刚锅", 'M', 18, {110, 98, 102,310}},
    {03, "阿亮", 'M', 18, {110, 98, 102,310}},
    {04, "小鱼", 'F', 16, {110, 98, 102,310}}
};

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
    //信息窗口 假设先是7行
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
    printf("1. 添加学生信息");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
    printf("2. 删除学生信息(根据学号)");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
    printf("3. 修改学生信息(根据学号)");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 3);
    printf("4. 查询学生信息");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 4);
    printf("5. 显示所有学生信息以及统计信息");
    SetPosition(MARGIN_X + 10, INFO_START_Y + 5);
    printf("7. 退出");
    ShowInfo();
}


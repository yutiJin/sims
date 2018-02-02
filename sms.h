#ifndef SMS_H_INCLUDED
#define SMS_H_INCLUDED

#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //控制台的输入输出 比如getch()


#define SEP "------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X 20     //向左移20个座位
#define INFO_START_Y 3  //主界面开始信息的Y坐标
#define INFO_END_Y 12   //主界面结束信息的Y坐标



/* 各科成绩信息 */
typedef struct _grade{
	int Maths;		    //数学成绩
	int Chinese;		//语文成绩
	int English;		//英语成绩
	//int total;		    //总成绩
}Grade;

/* 学生的个人信息 */
typedef struct _student{
	int stu_num;        //学生学号
	char stu_name[50]; 	//学生名字
	char stu_sex[5];	//学生性别
	Grade grades;		//学生成绩
	struct _student *next;
}Student, *Lstu;


/* 欢迎界面 */
void ShowWelcome();

/* 主界面竖线表示 */
void ShowInfo();

/* 主界面信息 */
void ShowMainInfo();

/* 0. 创建学生信息库 */
void CreateStuInfo(Student * L);

/* 1. 添加学生信息 */
void AddStuInfo(Student * L);

/* 2. 删除学生信息(根据学号) */
void DeleteStuInfo(Student * L);

/* 5. 显示所有学生信息以及统计信息 */
void ShowStuInfo(Student * L);

#endif // SMS_H_INCLUDED

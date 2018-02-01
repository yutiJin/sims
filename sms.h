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
#define INFO_END_Y 11   //主界面结束信息的Y坐标



/* 各科成绩信息 */
typedef struct _grade{
	double Maths;		//数学成绩
	double Chinese;		//语文成绩
	double English;		//英语成绩
	double total;		//总成绩
}Grade;

/* 学生的个人信息 */
typedef struct _student{
	int stu_num;        //学生学号
	char stu_name[50]; 	//学生名字
	char stu_sex;		//学生性别
	int age;			//学生年龄
	Grade grades;		//学生成绩
}Student;


/* 欢迎界面 */
void ShowWelcome();

/* 主界面竖线表示 */
void ShowInfo();

/* 主界面信息 */
void ShowMainInfo();


#endif // SMS_H_INCLUDED

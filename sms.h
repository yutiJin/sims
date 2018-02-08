#ifndef SMS_H_INCLUDED
#define SMS_H_INCLUDED

#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //控制台的输入输出 比如getch()


#define SEP "--------------------------------------------------"
#define COL 78
#define MARGIN_X 20     //向左移20个座位
#define INFO_START_Y 3  //主界面开始信息的Y坐标
#define INFO_END_Y 12   //主界面结束信息的Y坐标
#define N 18            //要删除的信息行


/* 各科成绩信息 */
typedef struct _grade{
	int Maths;		    //数学成绩
	int Chinese;		//语文成绩
	int English;		//英语成绩
	int total;		//总成绩
}Grade;

typedef enum _sex{
    MAN, WOMAN
}Sex;                   //枚举

/* 学生的个人信息 */
typedef struct _student{
	int stu_num;        //学生学号
	char stu_name[50]; 	//学生名字
	Sex sex;	        //学生性别
	Grade grades;		//学生成绩
	struct _student *next;
}Student;


/* 欢迎界面 */
void ShowWelcome();

/* 主界面信息 */
void ShowMainInfo();

/* 获取用户的选择 */
int Question(const char *str);

/* 返回指定学号学生的上一个节点 */
Student * GetPrevAddr(Student * L, int stu_num);

/* 0. 创建学生信息库  （采用文件的形式） */
void CreateStuInfo(Student * L);

/* 1. 添加学生信息 */
void AddStuInfo(Student * L);

/* 2. 删除学生信息(根据学号) */
void DeleteStuInfo(Student * L, int stu_num);   //new
//void DeleteStuInfo(Student * L); //old

/* 3. 修改学生信息(根据学号) */
void UpdataStuInfo(Student * L);

/* 4. 查询学生信息(根据学号)*/
void ShowOneStuInfo(Student * L);

/* 链表中的内容保存到文件当中 */
void LinkToFile(Student * L);

/* 文件内容显示到数据链表中 */
Student * FiletoLink();

/* 5. 显示所有学生信息以及统计信息 */
void ShowStuInfo(Student * L);





#endif // SMS_H_INCLUDED

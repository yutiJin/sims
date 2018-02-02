#ifndef SMS_H_INCLUDED
#define SMS_H_INCLUDED

#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //����̨��������� ����getch()


#define SEP "------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X 20     //������20����λ
#define INFO_START_Y 3  //�����濪ʼ��Ϣ��Y����
#define INFO_END_Y 12   //�����������Ϣ��Y����



/* ���Ƴɼ���Ϣ */
typedef struct _grade{
	int Maths;		    //��ѧ�ɼ�
	int Chinese;		//���ĳɼ�
	int English;		//Ӣ��ɼ�
	//int total;		    //�ܳɼ�
}Grade;

/* ѧ���ĸ�����Ϣ */
typedef struct _student{
	int stu_num;        //ѧ��ѧ��
	char stu_name[50]; 	//ѧ������
	char stu_sex[5];	//ѧ���Ա�
	Grade grades;		//ѧ���ɼ�
	struct _student *next;
}Student, *Lstu;


/* ��ӭ���� */
void ShowWelcome();

/* ���������߱�ʾ */
void ShowInfo();

/* ��������Ϣ */
void ShowMainInfo();

/* 0. ����ѧ����Ϣ�� */
void CreateStuInfo(Student * L);

/* 1. ���ѧ����Ϣ */
void AddStuInfo(Student * L);

/* 2. ɾ��ѧ����Ϣ(����ѧ��) */
void DeleteStuInfo(Student * L);

/* 5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ */
void ShowStuInfo(Student * L);

#endif // SMS_H_INCLUDED

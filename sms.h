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
#define INFO_END_Y 11   //�����������Ϣ��Y����



/* ���Ƴɼ���Ϣ */
typedef struct _grade{
	double Maths;		//��ѧ�ɼ�
	double Chinese;		//���ĳɼ�
	double English;		//Ӣ��ɼ�
	double total;		//�ܳɼ�
}Grade;

/* ѧ���ĸ�����Ϣ */
typedef struct _student{
	int stu_num;        //ѧ��ѧ��
	char stu_name[50]; 	//ѧ������
	char stu_sex;		//ѧ���Ա�
	int age;			//ѧ������
	Grade grades;		//ѧ���ɼ�
}Student;


/* ��ӭ���� */
void ShowWelcome();

/* ���������߱�ʾ */
void ShowInfo();

/* ��������Ϣ */
void ShowMainInfo();


#endif // SMS_H_INCLUDED

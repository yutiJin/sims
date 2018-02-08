#ifndef SMS_H_INCLUDED
#define SMS_H_INCLUDED

#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //����̨��������� ����getch()


#define SEP "--------------------------------------------------"
#define COL 78
#define MARGIN_X 20     //������20����λ
#define INFO_START_Y 3  //�����濪ʼ��Ϣ��Y����
#define INFO_END_Y 12   //�����������Ϣ��Y����
#define N 18            //Ҫɾ������Ϣ��


/* ���Ƴɼ���Ϣ */
typedef struct _grade{
	int Maths;		    //��ѧ�ɼ�
	int Chinese;		//���ĳɼ�
	int English;		//Ӣ��ɼ�
	int total;		//�ܳɼ�
}Grade;

typedef enum _sex{
    MAN, WOMAN
}Sex;                   //ö��

/* ѧ���ĸ�����Ϣ */
typedef struct _student{
	int stu_num;        //ѧ��ѧ��
	char stu_name[50]; 	//ѧ������
	Sex sex;	        //ѧ���Ա�
	Grade grades;		//ѧ���ɼ�
	struct _student *next;
}Student;


/* ��ӭ���� */
void ShowWelcome();

/* ��������Ϣ */
void ShowMainInfo();

/* ��ȡ�û���ѡ�� */
int Question(const char *str);

/* ����ָ��ѧ��ѧ������һ���ڵ� */
Student * GetPrevAddr(Student * L, int stu_num);

/* 0. ����ѧ����Ϣ��  �������ļ�����ʽ�� */
void CreateStuInfo(Student * L);

/* 1. ���ѧ����Ϣ */
void AddStuInfo(Student * L);

/* 2. ɾ��ѧ����Ϣ(����ѧ��) */
void DeleteStuInfo(Student * L, int stu_num);   //new
//void DeleteStuInfo(Student * L); //old

/* 3. �޸�ѧ����Ϣ(����ѧ��) */
void UpdataStuInfo(Student * L);

/* 4. ��ѯѧ����Ϣ(����ѧ��)*/
void ShowOneStuInfo(Student * L);

/* �����е����ݱ��浽�ļ����� */
void LinkToFile(Student * L);

/* �ļ�������ʾ������������ */
Student * FiletoLink();

/* 5. ��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ */
void ShowStuInfo(Student * L);





#endif // SMS_H_INCLUDED

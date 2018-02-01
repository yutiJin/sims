#ifndef SMSLIB_H_INCLUDED
#define SMSLIB_H_INCLUDED

#include "sms.h"

/* 控制台窗口的信息 */
void SetTitle(char *title);

/* 文字的前景色和背景色 */
void SetColor(int foreColor, int backColor);
/* 设置文字的前景色和背景色 */
/*
 * 0-黑色, 1-蓝色, 2-绿色, 3-浅绿色, 4-红色, 5-紫色, 6-黄色, 7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色, 11-淡浅绿色, 12-淡红色, 13-淡紫色, 14-淡黄色, 15-亮白色
 */


/* 设置光标的位置 -- 定位在哪一行 哪一列  居中用*/
void SetPosition(int x, int y);

/* 从x，y坐标开始，清空rowCount行*/
void Clear(int x, int y, int rowCount);

#endif // SMSLIB_H_INCLUDED



/**
 * File: interface.h
 * Description: 界面逻辑及用户交互
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.18
 */
#ifndef _INTERFACE_H
#define _INTERFACE_H
#include <time.h>
#include "search/bfs.h"

/* Function: draw_menu
 * Description: 绘制菜单
 * Parma: 无
 * Return: 无
 */
void draw_menu();

/* Function: handle_event
 * Description: 响应键盘事件
 * Parma: 
 *   start-开始状态节点指针
 *   target-目标状态节点指针
 * Return: 返回1继续循环，0则退出循环
 */
int handle_event(STATE *start,STATE *target);

#endif
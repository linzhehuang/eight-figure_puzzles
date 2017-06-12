/**
 * File: bfs.h
 * Description: bfs.c的头文件
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.12
 */
#ifndef _BFS_H
#define _BFS_H
#include "../type/state.h"
#include "../type/book.h"

/* Function: bfs
 * Description: bfs解决路径
 * Parma: 
 *   start-初始状态节点指针
 *   target-目标状态节点指针
 * Return: 成功返回最后一个节点指针，否则返回NULL
 */
STATE *bfs(STATE *start,STATE *target);

#endif
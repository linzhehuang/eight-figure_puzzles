/**
 * File: state.h
 * Description: 状态节点的创建、置入数据、
 * 根据旧状态及方向获取新状态节点、通过用户
 * 输入获取状态信息、判断问题是否可解
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#ifndef _STATE_H
#define _STATE_H
#include <stdio.h>
#include <malloc.h>

typedef struct STATE {
  struct STATE *parent;  // 父状态节点
  int data[9];           // 状态数据
  int pos;               // 0的位置
} STATE;  // 状态节点

/* Function: create_new_state
 * Description: 创建状态节点
 * Parma: 无
 * Return: 状态节点指针
 */
STATE *create_new_state();

/* Function: get_new_state
 * Description: 根据旧状态及方向获取新状态节点
 * Parma: 
 *   old_state-旧状态节点指针
 *   direction-移动方向，0-3：上右下左
 * Return: 能移动则返回新状态节点指针，否则为NULL
 */
STATE *get_new_state(STATE *old_state,int direction);

/* Function: set_state_data
 * Description: 置入状态数据
 * Parma: 
 *   state-状态节点指针
 *   data-长度为9的数组
 * Return: 无
 */
void set_state_data(STATE *state,int data[9]);

/* Function: is_same_state
 * Description: 是否为相同状态
 * Parma: 
 *   src-状态节点指针
 *   dst-状态节点指针
 * Return: 相同返回1，否则为0
 */
int is_same_state(STATE *src,STATE *dst);

/* Function: is_same_state
 * Description: 判断问题是否可解
 * Parma: 
 *   start-开始状态节点指针
 *   target-目标状态节点指针
 * Return: 可解返回1，否则为0
 */
int solvable(STATE *start,STATE *target);

/* Function: input_state_data
 * Description: 输入状态数据
 * Parma: 
 *   state-状态节点指针
 * Return: 无
 */
void input_state_data(STATE *state);

#endif
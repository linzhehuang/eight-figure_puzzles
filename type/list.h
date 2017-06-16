/**
 * File: list.h
 * Description: list.c头文件
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.16
 */
#ifndef _LIST_H
#define _LIST_H
#include "state.h"

typedef struct LIST {
  STATE **data;
  int length;  // 当前长度
} LIST;

// 创建列表
LIST *create_list(int max_length);
// 销毁列表
void destroy_list(LIST *list);
// 更新列表
void update_list(LIST *old_list,LIST *new_list);
// 插入状态节点地址到列表中
void insert_to_list(LIST *list,STATE *state);
// 根据下标获取状态节点地址
STATE *get_state_from_list(LIST *list,int index);
// 判断是否为空列表
int is_empty_list(LIST *list);

#endif
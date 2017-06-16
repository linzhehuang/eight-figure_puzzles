/**
 * File: list.c
 * Description: 状态节点地址列表
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.16
 */
#include "list.h"

// 复位列表
static void reset_list(LIST *list) {
  free(list->data);
  list->data = NULL;
  list->length = 0;
}

// 创建列表
LIST *create_list(int max_length) {
  LIST *list = (LIST*)malloc(sizeof(LIST));
  list->data = (STATE**)calloc(sizeof(STATE*),max_length);
  list->length = 0;
  return list;
}
// 销毁列表
void destroy_list(LIST *list) {
  free(list);
  list = NULL;
}
// 更新列表
void update_list(LIST *old_list,LIST *new_list) {
  reset_list(old_list);
  old_list->data = new_list->data;
  old_list->length = new_list->length;
  destroy_list(new_list);
}
// 插入状态节点地址到列表中
void insert_to_list(LIST *list,STATE *state) {
  list->data[list->length] = state;
  list->length++;
}
// 根据下标获取状态节点地址
STATE *get_state_from_list(LIST *list,int index) {
  return list->data[index];
}
// 判断是否为空列表
int is_empty_list(LIST *list) {
  return (list->length == 0);
}
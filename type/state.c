/**
 * File: state.c
 * Description: 状态节点的创建、置入数据、
 * 根据旧状态及方向获取新状态节点
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#include "state.h"

// 创建状态节点
STATE *create_new_state() {
  STATE *state = (STATE*)malloc(sizeof(STATE));
  for(int i = 0;i < 9;i++) state->data[i] = 0;
  state->pos = 0;
  state->parent = NULL;
  return state;
}
// 置入状态数据
void set_state_data(STATE *state,int data[9]) {
  for(int i = 0;i < 9;i++) {
	if(data[i] == 0) state->pos = i;
	state->data[i] = data[i];
  }
}
// 根据旧状态及方向获取新状态节点
STATE *get_new_state(STATE *old_state,int direction) {
  // 移动偏移值，0-3：上右下左
  int offset[4] = {-3,1,3,-1};
  // 判断该方向是否可移动
  int old_pos = old_state->pos;
  int new_pos = old_pos + offset[direction];
  if(new_pos < 0 || new_pos > 8)
	return NULL;
  if((old_pos%3 == 0) && (direction == 3))
	return NULL;
  if((old_pos%3 == 2) && (direction == 1))
	return NULL;
  // 创建新状态节点
  STATE *new_state = create_new_state();
  for(int i = 0;i < 9;i++) new_state->data[i] = old_state->data[i];
  new_state->data[old_pos] = old_state->data[new_pos];
  new_state->data[new_pos] = 0;
  new_state->pos = new_pos;
  new_state->parent = old_state;
  return new_state;
}
// 是否为相同状态
int is_same_state(STATE *src,STATE *dst) {
  if(src->pos != dst->pos) return 0;
  for(int i = 0;i < 9;i++) {
	if(src->data[i] != dst->data[i]) return 0;
  }
  return 1;
}
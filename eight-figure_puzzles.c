/**
 * File: eight-figure_puzzles.c
 * Description: 八数码问题实现
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.9
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  struct NODE *last;  // 上个状态节点
  int data[9];
  int pos;  // 0位置
} NODE; // 存放状态的节点
typedef struct CLOSE {
  int *data;
  int length;
} CLOSE;  // close表，存放已访问节点


// 插入数据到close表中
void insert_to_close(CLOSE *close,int num) {
  if(close->length == 0) { 
    close->length++;
	close->data = (int*)malloc(sizeof(int));
  }
  else {
	close->length++;
	close->data = (int*)realloc(close->data,sizeof(int) * close->length);
  }
  close->data[close->length-1] = num;
}

// 是否为相同状态
int is_same_state(NODE src,NODE dst) {
  if(src.pos != dst.pos) return 0;
  for(int i = 0;i < 9;i++) {
	if(src.data[i] != dst.data[i]) return 0;
  }
  return 1;
}
// 是否为已存在状态
int is_exist_state(CLOSE close,int num) {
  if(!close.data) return 0;
  for(int i = 0;i < close.length;i++) {
	if(close.data[i] == num) return 1;
	else continue;
  }
  return 0;
}

// 数组转数字
int arr_to_num(int arr[9]) {
  int num = 0;
  for(int i = 0;i < 9;i++) num = num*10 + arr[i];
  return num;
}

// 添加当前节点的子节点到列表中，且返回数量
int add_child_to_list(NODE *cur_node,NODE *list[4],CLOSE *close) {
  // 0移动到的位置 0-3:上右下左
  int offset[9][4] = {
	{0,1,3,0},{1,2,4,0},{2,2,5,1},
	{0,4,6,3},{1,5,7,3},{2,5,8,4},
	{3,7,6,6},{4,8,7,6},{5,8,8,7}
  };
  int count = 0;  // 节点个数
  int new_pos = 0;  // 0元素新位置
  for(int i = 0;i < 4;i++) {
	// 计算新位置
	new_pos = offset[cur_node->pos][i];
	// 新位置不可移动
	if(new_pos == cur_node->pos) continue;
	else {
	  // 创建新节点
	  NODE *new_node = (NODE*)malloc(sizeof(NODE));
	  for(int j = 0;j < 9;j++) new_node->data[j] = cur_node->data[j];
	  new_node->data[cur_node->pos] = cur_node->data[new_pos];
	  new_node->data[new_pos] = 0;
	  new_node->pos = new_pos;
	  // 若不存在该状态则添加该节点到列表和close表中
	  if( !is_exist_state(*close,arr_to_num(new_node->data)) ) {
		new_node->last = cur_node;
	    list[count] = new_node;
		insert_to_close(close,arr_to_num(new_node->data));
		count++;
	  }
	  else {
		free(new_node);
		continue;
	  }
	}
  }
  return count;
}
int create_state(NODE *node) {
  for(int i = 0;i < 9;i++) node->data[i] = i;
  node->pos = 0;
  node->last = NULL;
}
int show(NODE node) {
  for(int i = 0;i < 3;i++) {
	for(int j = 0;j < 3;j++) {
	  printf("%d ",node.data[i*3+j]);
	}
    printf("\n");
  }
  printf("-----\n");
}
int get_path(NODE *node) {
  NODE *p = node;
  int i = 0;
  while(p) {
	i++;
	p = p->last;
  }
  printf("%d",i);
}
NODE *bfs(NODE *start,NODE target) {
  NODE *current = start;
  NODE **parent_list = NULL;
  CLOSE close = {NULL,0};
  // 插入初始节点
  int parent_amount = 1;
  parent_list = (NODE**)malloc(sizeof(NODE*));
  parent_list[0] = current;
  
  while(1) {
	// 创建临时列表，设置其长度为父层节点的4倍（最大可能长度）
	NODE **tmp_list = (NODE**)malloc(sizeof(NODE*) * 
	(parent_amount*4) );
	int tmp_amount = 0;
	for(int i = 0;i < parent_amount;i++) {
	  NODE *list[4] = {NULL};
	  current = parent_list[i];
	  if(is_same_state(*current,target)) {
		// 返回最后一个节点
		return current;
	  }
	  int tmp = add_child_to_list(current,list,&close);
	  for(int j = 0;j < tmp;j++) {
		tmp_list[tmp_amount] = list[j];
		tmp_amount += 1;
	  }
	}
	free(parent_list);
	// 更新父层节点列表及个数
	parent_list = tmp_list;
	parent_amount = tmp_amount;
  }
}
int main() {
  NODE start = {NULL,{2,3,7,1,8,6,5,0,4},7} ,
  target = {NULL,{1,2,3,4,5,6,7,8,0},8};
  
  get_path(bfs(&start,target));
  return 0;
}
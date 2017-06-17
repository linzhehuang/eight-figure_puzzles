// Using for unit testing
#include "search/bfs.h"

// 输入状态数据
void input_state_data(STATE *state) {
  int data[9] = {0};
  for(int i = 0;i < 9;i++)
	scanf("%d",&data[i]);
  set_state_data(state,data);
}
// 获取步骤数
int get_step(STATE *state) {
  int count = 0;
  while(state && ++count) state=state->parent;
  return count-1;
}
// 回溯寻找路径并输出结果
int backtracking(STATE *state) {
  int step = get_step(state);
  STATE **stack = (STATE**)calloc(sizeof(STATE*),step+1);
  printf("%d\n",step);
  int i = step;
  while(state) {
	stack[i] = state;
	state = state->parent;
	i--;
  }
  for(i = 0;i <= step;i++){
	for(int j = 0;j < 3;j++){
	  for(int k = 0;k < 3;k++){
	    printf("%d ",stack[i]->data[j*3+k]);
      }
	  printf("\n");
    }
	printf("----------\n");
  }
}

int main(void) {
  STATE *start = create_new_state(),
  *target = create_new_state() , *end;
  int start_data[9] = {2,3,7,1,8,6,5,0,4} ,
  target_data[9] = {1,2,3,4,5,6,7,8,0};
  set_state_data(start,start_data);
  set_state_data(target,target_data);
  end = bfs(start,target);
  printf("%p",end);
}
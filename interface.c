/**
 * File: interface.c
 * Description: 界面逻辑及用户交互
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.18
 */
// 
#include "interface.h"

// 延迟函数
static void delay(int second){
  time_t end = time(NULL)+second;
  while(time(NULL) != end);
}
// 清空屏幕
static void clear_screen() {
  if(system("cls"))
    system("clear");
}
// 获取步骤数
static int get_step(STATE *end) {
  int count = 0;
  while(end && ++count)
    end = end->parent;
  return count-1;
}
// 绘制九宫格
static void draw_ninegrid(int data[0]) {
  printf("+---+---+---+\n");
  for(int i = 0;i < 3;i++) {
    printf("|");
    for(int j = 0;j < 3;j++) {
      if(data[i*3+j])
        printf(" %d |",data[i*3+j]);
      else
        printf("   |");
    }
    printf("\n+---+---+---+\n");
  }
}
// 回溯寻找路径
static void backtracking(STATE *end) {
  int step = get_step(end);
  // 用栈存放路径
  LIST *stack = create_list(step);
  while(end) {
    insert_to_list(stack,end);
    end = end->parent;
  }
  for(int i = step;i >= 0;i--) {
    delay(2);
    clear_screen();
    printf("Current step:%d\n",step-i);
    draw_ninegrid(get_state_from_list(stack,i)->data);
  }
  printf("Total step:%d\n",step);
}
// 绘制菜单
void draw_menu() {
  char *items[] = {
    "1.Modify start state",
    "2.Modify target state",
    "3.Display all states",
    "4.Breadth frist search",
    "5.Quit"
  };
  clear_screen();
  for(int i = 0;i < 5;i++) {
    printf("%s\n",items[i]);
  }
  printf(">>");
}

// 响应事件
int handle_event(STATE *start,STATE *target) {
  int choice = 0;
  scanf("%d",&choice);
  clear_screen();
  switch(choice) {
    case 1:
      draw_ninegrid(start->data);
      printf("Sample:\n>>");
      for(int i = 0;i < 9;i++)
        printf("%d ",start->data[i]);
      printf("\n>>");
      input_state_data(start);
      break;
    case 2:
      draw_ninegrid(target->data);
      printf("Sample:\n>>");
      for(int i = 0;i < 9;i++)
        printf("%d ",target->data[i]);
      printf("\n>>");
      input_state_data(target);
      break;
    case 3:
      printf("START\n");
      draw_ninegrid(start->data);
      printf("TARGET\n");
      draw_ninegrid(target->data);
      break;
    case 4:
      // 判断是否可解，减少不必要的查找
      if(solvable(start,target)) {
        printf("Searching ...");
        STATE *end = bfs(start,target);
        printf(" Done\n");
        backtracking(end);
      }
      else printf("Unsolvable!\n");
      break;
    case 5:
      return 0;
      break;
    default:
      return 1;
      break;
  }
  // 暂停
  printf(">>Prese any key back to menu\n");
  getchar();
  getchar();
  return 1;
}
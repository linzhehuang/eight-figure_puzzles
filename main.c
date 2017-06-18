/**
 * File: main.c
 * Description: 程序入口
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.18
 */
#include "interface.h"

int main(void) {
  STATE *start = create_new_state(),
  *target = create_new_state();
  // 设置默认状态数据
  int start_data[9] = {0,8,7,6,5,4,3,2,1} ,
  target_data[9] = {1,2,3,4,5,6,7,8,0};
  set_state_data(start,start_data);
  set_state_data(target,target_data);
  
  do{
    draw_menu();
  } while(handle_event(start,target));
}
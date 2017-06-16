/**
 * File: bfs.c
 * Description: bfs解决八数码问题
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.12
 */
#include "bfs.h"

STATE *bfs(STATE *start,STATE *target) {
  // 创建存放状态节点地址列表及book表
  BOOK *book = create_book();
  LIST *list = create_list(1);
  // 插入开始状态节点
  insert_to_list(list,start);
  insert_to_book(book,calc_hash(start->data));
  
  while(!is_empty_list(list)) {
    // 创建临时列表
  	  LIST *tmp_list = create_list(list->length*4);
  	  
  	  // 遍历列表
  	  for(int i = 0;i < list->length;i++) {
  	    // 更新当前状态节点
  	    STATE *current = get_state_from_list(list,i);
  	    // 判断是否为目标状态节点
    		 if(is_same_state(current,target)) {
    		   destroy_list(tmp_list);
    		   destroy_list(list);
    		   destroy_book(book);
    		   return current;
    		 }
    		 
    		 // 扩展当前状态节点的节点
	      for(int j = 0;j < 4;j++) {
	        // 创建新状态节点，若值为NULL则跳过
	        STATE *new_state = get_new_state(current,j);
		       if(!new_state) continue;
		       // 若该状态在book表中则跳过
		       if( is_exist(book,calc_hash(new_state->data)) ) {
		         free(new_state);
		         continue;
		       }
		       
		       // 将新状态节点加入book表中
		       insert_to_book(book,calc_hash(new_state->data));
		       // 将新状态节点加入临时列表中
		       insert_to_list(tmp_list,new_state);
		     }  // 扩展结束
		     
		   }  // 列表遍历结束
		   
		   // 更新状态节点列表
		   update_list(list,tmp_list);
		 }
		 
  // 查找失败
  destroy_list(list);
  destroy_book(book);
  return NULL;
}
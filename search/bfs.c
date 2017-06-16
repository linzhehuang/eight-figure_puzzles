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
  // 创建book表，存放已访问节点
  BOOK *book = create_book();
  // 创建父层列表及初始化父层节点数
  STATE **parent_list = (STATE**)malloc(sizeof(STATE*));
  int parent_amount = 0;
  // 插入开始状态节点
  parent_list[0] = start;
  parent_amount++;
  insert_to_book(book,calc_hash(start->data));
  while(parent_amount) {
	  // 创建临时列表，设置其长度为父层节点的4倍（最大可能长度）
  	STATE **tmp_list = (STATE**)malloc(sizeof(STATE*) * 
  	(parent_amount*4));
  	int tmp_amount = 0;
  	
  	for(int i = 0;i < parent_amount;i++) {
  	  STATE *current = parent_list[i];
  	  // 判断是否为目标状态节点
    		if(is_same_state(current,target)) {
          free(parent_list);
          free(tmp_list);
          destroy_book(book);
		      return current;
		  }
	    // 扩展当前状态节点的周围节点
	    for(int j = 0;j < 4;j++) {
		  // 创建新状态节点，若值为NULL则跳过
		    STATE *new_state = get_new_state(current,j);
		    if(!new_state) continue;
		    // 若该状态在book表中则跳过
		    if( is_exist(book,calc_hash(new_state->data)) ) {
  		    free(new_state);
  		    continue;
  	  	}
	    	// 将该状态节点加入book表中
	    	insert_to_book(book,calc_hash(new_state->data));
	    	// 将该状态节点加入临时列表中
	    	tmp_list[tmp_amount] = new_state;
    		tmp_amount++;
	    }
	  }
	  // 更新父层节点列表及个数
	  free(parent_list);
	  parent_list = tmp_list;
	  parent_amount = tmp_amount;
  }
  // 销毁book表
  destroy_book(book);
  return NULL;
}
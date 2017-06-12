/**
 * File: book.c
 * Description: book表用于存放已访问节点的值，
 * book表第一个元素为长度，实现创建book表，插
 * 如数据值，及查找book表是否存在某值
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#include "book.h"

// 创建book表
BOOK *create_book() {
  BOOK *book = (BOOK*)malloc(sizeof(BOOK));
  book[0] = 0;
  return book;
}
// 向book表中插入数值
BOOK *insert_to_book(BOOK *book,int data) {
  book[0] += 1;
  book = (BOOK*)realloc(book,sizeof(BOOK) * (book[0]+1));
  book[book[0]] = data;
  return book;
}
// 查找book表中是否存在某值
int is_exist(BOOK *book,int key) {
  for(int i = 1;i < book[0];i++) {
	if(book[i] == key) return 1;
	else continue;
  }
  return 0;
}
// 将数组转换成数字
int arr_to_num(int arr[9]) {
  int num = 0;
  for(int i = 0;i < 9;i++) num = num*10 + arr[i];
  return num;
}
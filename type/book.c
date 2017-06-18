/**
 * File: book.c
 * Description: book表用于标记已存在的状态，
 * 实现创建book表、销毁book表、插入状态、查
 * 找某状态是否存在、计算数组hash值
 * 如数据值，及查找book表是否存在某值
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#include "book.h"

// 创建book表
BOOK *create_book() {
  BOOK *book = (BOOK*)calloc(sizeof(BOOK),362880);
  if(!book) exit(1);
  return book;
}
// 销毁book表
void destroy_book(BOOK *book) {
  free(book);
}
// 根据hash值在book表中标记
void insert_to_book(BOOK *book,int hash) {
  int index = (hash/8) - 1;
  int offset = hash % 8;
  offset = (offset)?offset-1:0;
  book[index] |= 1 << offset;
}
// 查找book表中是否存在某值
int is_exist(BOOK *book,int hash) {
  int index = (hash/8) - 1;
  int offset = hash % 8;
  offset = (offset)?offset-1:0;
  BOOK tmp = book[index] >> offset;
  return (tmp&1);
}
// 计算数组hash值
int calc_hash(int data[9]) {
  int sys[9] = {0,1,2,6,24,120,720,5040,40320};
  int hash = 0;
  for(int i = 1;i < 9;i++) {
    int count = 0;  // 逆序对个数
    for(int j = 0;j < i;j++) {
      if(data[j] < data[i])
        count++;
    }
    hash += sys[i]*count;
  }
  return hash;
}
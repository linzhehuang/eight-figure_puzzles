/**
 * File: book.c
 * Description: book.c头文件
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#ifndef _BOOK_H
#define _BOOK_H

#include <stdio.h>
#include <malloc.h>
typedef int BOOK;  // book表，首位存放长度

// 创建book表
BOOK *create_book();
// 向book表中插入数值
BOOK *insert_to_book(BOOK *book,int data);
// 查找book表中是否存在某值
int is_exist(BOOK *book,int key);
// 将数组转换成数字
int arr_to_num(int arr[9]);

#endif
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
#include <stdlib.h>
// book表
typedef unsigned char BOOK;

// 创建book表
BOOK *create_book();
// 销毁book表
void destroy_book(BOOK *book);
// 向book表中插入数值
void insert_to_book(BOOK *book,int hash);
// 查找book表中是否存在某值
int is_exist(BOOK *book,int hash);
// 计算hash值
int calc_hash(int data[9]);

#endif
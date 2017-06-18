/**
 * File: book.c
 * Description: book表用于标记已存在的状态，
 * 实现创建book表、销毁book表、插入状态、查
 * 找某状态是否存在、计算数组hash值
 * Author: linzhehuang
 * Blog: http://www.cnblogs.com/linzhehuang/
 * Version: 0.0.1
 * Date: 2017.6.11
 */
#ifndef _BOOK_H
#define _BOOK_H
#include <stdio.h>
#include <stdlib.h>

// book表类型
typedef unsigned char BOOK;

/* Function: create_book
 * Description: 创建book表
 * Parma: 无
 * Return: book表指针
 */
BOOK *create_book();

/* Function: destory_book
 * Description: 销毁book表
 * Parma: 
 *   book-book表指针
 * Return: 无
 */
void destroy_book(BOOK *book);

/* Function: insert_to_book
 * Description: 插入状态到book表
 * Parma: 
 *   book-book表指针
 *   hash-数组hash值
 * Return: 无
 */
void insert_to_book(BOOK *book,int hash);

/* Function: is_exist
 * Description: 查找book表中是否存在某状态
 * Parma: 
 *   book-book表指针
 *   hash-数组hash值
 * Return: 存在返回1，否则为0
 */
int is_exist(BOOK *book,int hash);

/* Function: calc_hash
 * Description: 计算数组hash值
 * Parma: 
 *   data-状态节点数据
 * Return: 数组hash值
 */
// 
int calc_hash(int data[9]);

#endif
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//栈的顺序存储
#define MAX 1024

struct SStack
{
    //栈中数组
    void * data[MAX];

    //栈大小
    int m_size;
};

typedef void *SeqStack;

//初始化栈
SeqStack init_SeqStack();

//入栈
void Push_SeqStack(SeqStack stack,void *data);

//出栈
void Pop_SeqStack(SeqStack stack);

//返回栈顶
void *top_SeqStack(SeqStack stack);

//反回栈大小
int size_SeqStack(SeqStack stack);

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack);

//销毁
void destroy_SeqStack(SeqStack stack);

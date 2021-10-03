#include<stdio.h>

#include<iostream>
using namespace std; 

template <typename T>
struct Node//节点 
{
    T data;//数据域 
    
	Node<T> *next;//指针域 
};

template <typename T>
class LinkQueue//链队列 
{
private:
	
	Node<T> *front,*rear;//队头和队尾指针 
	
public:
	
	LinkQueue();//构造函数 
	
	~LinkQueue();//析构函数 
	 
	void Push(T x);//将项x插入前端
	
	void Inject(T x);//将项x插入队尾 
	
	T Pop();//删除前端项并将其返回 
	
	T Eject();//删除队尾项并将其返回 
	
	T GetQueue();//取队头元素 
	 
}; 

template <typename T>
LinkQueue<T>::LinkQueue()//构造函数 
{
	Node<T> *s=NULL;
	
	s=new Node<T>;
	s->next=NULL;
	
	front=s;
	rear=s;
}

template <typename T>
LinkQueue<T>::~LinkQueue()//析构函数
{
	Node<T> *q=NULL;
	
	while(front!=NULL)
	{
		q=front;
		
		front=front->next;
		
		delete q;
	}
}

template <typename T>
void LinkQueue<T>::Push(T x)//将项x插入前端
{
	Node<T> *s;
	
	s=new Node<T>;
	s->data=x;
	
	s->next=front->next;
	
	front->next->prior=s;	
	
}

template <typename T>
void LinkQueue<T>::Inject(T x)//将项x插入队尾
{
	Node<T> *p=NULL;
	
	p=new Node<T>;
	
	p->data=x;
	p->next=NULL;
	
	rear->next=p;
	
	rear=p;
}

template <typename T>
T LinkQueue<T>::Pop()//删除前端项并将其返回
{
	Node<T> *p;
	
	T x;
	
	p=front->next;
	
	x=front->data;
	
	front=p;
	
	return x;
}

template <typename T>
T LinkQueue<T>::Eject()//删除队尾项并将其返回
{
	Node<T> *p;
	
	int x;
	
	x=rear->data;
	
	p=rear;
	
	
	//delete p;
	
	return x;
}


template <typename T>
T LinkQueue<T>::GetQueue()//取队头元素
{	
	return front->data;
}



int main()
{
	
	LinkQueue<char> obj;
	
	

	obj.Inject('h');
	obj.Inject('e');
	obj.Inject('l');
	obj.Inject('o');
	
	for(int i=0;i<4;i++)
	{
		obj.Pop();//出队 
	    printf("%c \n",obj.GetQueue());

	}
	
	
	return 0;
}


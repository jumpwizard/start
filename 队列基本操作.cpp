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
	
	void CreateQueue(T a[],int n);//将数据导入队列 
	
	void EnQueue(T x);//进队 
	
	T DeQueue();//出队 
	
	T GetQueue();//取队头元素 
	
	bool Empty();//判断是否为空 
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
void LinkQueue<T>::EnQueue(T x)//进队
{
	Node<T> *p=NULL;
	
	p=new Node<T>;
	
	p->data=x;
	p->next=NULL;
	
	rear->next=p;
	
	rear=p;
}

template <typename T>
T LinkQueue<T>::DeQueue()//出队
{
	Node<T> *p;
	
	T x;
	
	p=front->next;
	
	x=front->data;
	
	front=p;
	
	return x;
}

template <typename T>
T LinkQueue<T>::GetQueue()//取队头元素
{	
	return front->data;
}

template <typename T>
bool LinkQueue<T>::Empty()//判断是否为空
{
	if(front==rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void LinkQueue<T>::CreateQueue(T a[],int n)//将数据导入队列 
{
	Node<T> *p;
	
	for(int i=0;i<n;i++)
	{
	    p=new Node<T>;
	
	    p->data=a[i];
	    p->next=NULL;
	
	    rear->next=p;
	
	    rear=p;
	}
}

int main()
{
	char a[]={'H','e','l','l','o'};
	
	LinkQueue<char> obj;
	
	
	if(obj.Empty()==true)//判断是否为空 
	{
		printf(" 空队列 \n");
	}
	else
	{
		printf(" 非空队列 \n");
	}
	
	obj.CreateQueue(a,5);//导入数据 
	
	for(int i=0;i<3;i++)
	{
		obj.DeQueue();//出队 
	    printf("%c \n",obj.GetQueue());

	}
	
	
	return 0;
}

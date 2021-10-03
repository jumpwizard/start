#include<stdio.h>

#include<iostream>
using namespace std; 

template <typename T>
struct Node//�ڵ� 
{
    T data;//������ 
    
	Node<T> *next;//ָ���� 
};

template <typename T>
class LinkQueue//������ 
{
private:
	
	Node<T> *front,*rear;//��ͷ�Ͷ�βָ�� 
	
public:
	
	LinkQueue();//���캯�� 
	
	~LinkQueue();//�������� 
	
	void CreateQueue(T a[],int n);//�����ݵ������ 
	
	void EnQueue(T x);//���� 
	
	T DeQueue();//���� 
	
	T GetQueue();//ȡ��ͷԪ�� 
	
	bool Empty();//�ж��Ƿ�Ϊ�� 
}; 

template <typename T>
LinkQueue<T>::LinkQueue()//���캯�� 
{
	Node<T> *s=NULL;
	
	s=new Node<T>;
	s->next=NULL;
	
	front=s;
	rear=s;
}

template <typename T>
LinkQueue<T>::~LinkQueue()//��������
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
void LinkQueue<T>::EnQueue(T x)//����
{
	Node<T> *p=NULL;
	
	p=new Node<T>;
	
	p->data=x;
	p->next=NULL;
	
	rear->next=p;
	
	rear=p;
}

template <typename T>
T LinkQueue<T>::DeQueue()//����
{
	Node<T> *p;
	
	T x;
	
	p=front->next;
	
	x=front->data;
	
	front=p;
	
	return x;
}

template <typename T>
T LinkQueue<T>::GetQueue()//ȡ��ͷԪ��
{	
	return front->data;
}

template <typename T>
bool LinkQueue<T>::Empty()//�ж��Ƿ�Ϊ��
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
void LinkQueue<T>::CreateQueue(T a[],int n)//�����ݵ������ 
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
	
	
	if(obj.Empty()==true)//�ж��Ƿ�Ϊ�� 
	{
		printf(" �ն��� \n");
	}
	else
	{
		printf(" �ǿն��� \n");
	}
	
	obj.CreateQueue(a,5);//�������� 
	
	for(int i=0;i<3;i++)
	{
		obj.DeQueue();//���� 
	    printf("%c \n",obj.GetQueue());

	}
	
	
	return 0;
}

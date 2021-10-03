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
	 
	void Push(T x);//����x����ǰ��
	
	void Inject(T x);//����x�����β 
	
	T Pop();//ɾ��ǰ������䷵�� 
	
	T Eject();//ɾ����β����䷵�� 
	
	T GetQueue();//ȡ��ͷԪ�� 
	 
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
void LinkQueue<T>::Push(T x)//����x����ǰ��
{
	Node<T> *s;
	
	s=new Node<T>;
	s->data=x;
	
	s->next=front->next;
	
	front->next->prior=s;	
	
}

template <typename T>
void LinkQueue<T>::Inject(T x)//����x�����β
{
	Node<T> *p=NULL;
	
	p=new Node<T>;
	
	p->data=x;
	p->next=NULL;
	
	rear->next=p;
	
	rear=p;
}

template <typename T>
T LinkQueue<T>::Pop()//ɾ��ǰ������䷵��
{
	Node<T> *p;
	
	T x;
	
	p=front->next;
	
	x=front->data;
	
	front=p;
	
	return x;
}

template <typename T>
T LinkQueue<T>::Eject()//ɾ����β����䷵��
{
	Node<T> *p;
	
	int x;
	
	x=rear->data;
	
	p=rear;
	
	
	//delete p;
	
	return x;
}


template <typename T>
T LinkQueue<T>::GetQueue()//ȡ��ͷԪ��
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
		obj.Pop();//���� 
	    printf("%c \n",obj.GetQueue());

	}
	
	
	return 0;
}


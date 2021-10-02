#include<stdio.h>

template <typename T>
struct Node //�ڵ� 
{
	T data;//������ 
	
	Node<T> *next;//ָ���� 
} ;

template <typename T>
class LinkStack//����ջ 
{
private:
	
	Node<T> *top;//ջ��ָ�룬ͷָ�� 
	
public:
	
	LinkStack();//���캯�� 
	
	~LinkStack();//��������
	
	void CreateStack(T a[],int n);//���������ջ 
	
	void Push(T x);//��ջ 
	
	T Pop();//��ջ 
	
	T GetTop();//�鿴ȡջ��Ԫ�� 
	
	void ClearStack();//���ջ 
	
	bool Empty();//�ж��Ƿ�Ϊ��ջ 
};

template <typename T>
LinkStack<T>::LinkStack()//���캯�� 
{
	top=NULL;
}

template <typename T>
LinkStack<T>::~LinkStack()//��������
{
	Node<T> *p;
	
	while(top!=NULL)
	{
		p=top;
		
		top=top->next;
		
		delete p;
	}
}

template <typename T>
void LinkStack<T>::CreateStack(T a[],int n)//���������ջ 
{
	Node<T> *p;
	
	for(int i=0;i<n;i++)
	{
		p= new Node<T>;
	
	    p->data = a[i];
	
	    p->next = top;
	
	    top=p;
	}
}

template <typename T>
void LinkStack<T>::Push(T x)//��ջ
{
	Node<T> *p;
	
	p= new Node<T>;
	
	p->data = x;
	
	p->next = top;
	
	top=p;
}

template <typename T>
T LinkStack<T>::Pop()//��ջ 
{
	Node<T> *p;
	T x;
	
	x=top->data;
	p=top;
	
	top=top->next;
	
	delete p;
	
	return x;
}

template <typename T>
T LinkStack<T>::GetTop()//�鿴ȡջ��Ԫ��
{
	if(Empty()==true)
	{
		printf("��ջ"); 
		
		return NULL;
	}
	else
	{
		T x;
	
	    x=top->data;
	
	    return x;
	}
}

template <typename T>
void LinkStack<T>::ClearStack()//���ջ 
{
	Node<T> *p;
	
	while(top!=NULL)
	{
		p=top;
		
		top=top->next;
		
		delete p;
	}
} 

template <typename T>
bool LinkStack<T>::Empty()//�ж��Ƿ�Ϊ��ջ
{
	if(top==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a[]={5,7,6,4,2};
	
	LinkStack<int> obj;
	
	obj.CreateStack(a,5);//����������ջ 
	
	printf("%d \n",obj.GetTop());//�鿴ջ�� 
	
	obj.ClearStack();//���ջ 
	printf("%d \n",obj.GetTop());
	
	obj.Push(15);//��ջ15 
	printf("%d \n",obj.GetTop());
	
	obj.Pop();//��ջ 
	printf("%d \n",obj.GetTop());
	
	return 0;
}


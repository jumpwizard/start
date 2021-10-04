#include<stdio.h>

template <typename T>
struct Node //节点 
{
	T data;//数据域 
	
	Node<T> *next;//指针域 
} ;

template <typename T>
class LinkStack//链表栈 
{
private:
	
	Node<T> *top;//栈顶指针，头指针 
	
public:
	
	LinkStack();//构造函数 
	
	~LinkStack();//析构函数
	
	void CreateStack(T a[],int n);//导入数组进栈 
	
	void Push(T x);//进栈 
	
	T Pop();//出栈 
	
	T GetTop();//查看取栈顶元素 
	
	void ClearStack();//清空栈 
	
	bool Empty();//判断是否为空栈 
};

template <typename T>
LinkStack<T>::LinkStack()//构造函数 
{
	top=NULL;
}

template <typename T>
LinkStack<T>::~LinkStack()//析构函数
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
void LinkStack<T>::CreateStack(T a[],int n)//导入数组进栈 
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
void LinkStack<T>::Push(T x)//进栈
{
	Node<T> *p;
	
	p= new Node<T>;
	
	p->data = x;
	
	p->next = top;
	
	top=p;
}

template <typename T>
T LinkStack<T>::Pop()//出栈 
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
T LinkStack<T>::GetTop()//查看取栈顶元素
{
	if(Empty()==true)
	{
		printf("空栈"); 
		
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
void LinkStack<T>::ClearStack()//清空栈 
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
bool LinkStack<T>::Empty()//判断是否为空栈
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
	
	obj.CreateStack(a,5);//导入数组入栈 
	
	printf("%d \n",obj.GetTop());//查看栈顶 
	
	obj.ClearStack();//清空栈 
	printf("%d \n",obj.GetTop());
	
	obj.Push(15);//进栈15 
	printf("%d \n",obj.GetTop());
	
	obj.Pop();//出栈 
	printf("%d \n",obj.GetTop());
	
	return 0;
}

#include<iostream>

using namespace std;

/*Josephus问题是下面的游戏:N个人从1到N编号，围坐成一个圆圈。从1号开始传递一个热土豆。经过M次传递后拿着热土豆的人被清除离座，围
坐的圆圈缩紧，由坐在被清除的人后面的人拿起热土豆继续进行游戏。最后剩下的人取胜。因此，如果M=0和N=5，则依次清除后，5号获胜。如果M=1和N=5，
那么被清除的人的顺序是2，4，1，5。a，编写一个程序解决M和N在一般值下的Josephus问题，应使你的程序尽可能提高高效，要确保能够清除单元。*/



template <typename T>
struct Node  //节点 
{
	T data;   //数据域 
	
	Node<T> *prior;//前指针 
	
	Node<T> *next;  //后指针 
};

template <typename T>
class CLinkListClass//建立循环链表 
{
	
private:
	Node<T> *head;
	
public:
	
	CLinkListClass(); //构造函数，创建一个空链表 
	
	~CLinkListClass(); //析构函数，释放链表的所有节点 
	
	void CreateListR( int n); //用尾插法建立双链表
		
	int ListLenght();//求双链表中数据结点的个数 
	
	void Start(int m);//开始传递热土豆 
	
	
	
};

template <typename T>
CLinkListClass<T>::CLinkListClass()//构造函数 ，创建一个空链表
{
	head = new Node<T>;
	
	head -> next = NULL;
}

template <typename T>
CLinkListClass<T>::~CLinkListClass()//析构函数，释放链表的所有节点
{
	Node<T> *pre,*p;
	
	pre=head;
	
	p=pre -> next;
	
	while(p!=NULL)
	{
		delete pre;
		
		pre=p;
		
		p=pre -> next;
	}
	
	delete pre;
}

template <typename T>
void CLinkListClass<T>::CreateListR( int n)//用尾插法建立双链表
{
	Node<T> *r,*s;
	T a[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	
	r=head;
	
	for(int i=0;i<n;i++)
	{
		s=new Node<T>;
		
		s->data=a[i];
		
		r->next=s;
		
		s->prior=r; 
		
		r=s;
	}
	r->next=head;
	head->prior=r;
}

template <typename T>
int CLinkListClass<T>::ListLenght()//求双链表中数据结点的个数 
{
	int i=0;
	
	Node<T> *p;
	
	p=head;//->next;
	
	while(p->next!=head)
	{
		i++;
		
		p=p->next;
	}
	return i;
}

template <typename T>
void CLinkListClass<T>::Start(int m)//
{
	Node<T> *p;
	int i;
	
	p=head->next;
	
	cout<<"一共"<<ListLenght()<<"个人开始传递土豆，"<< "m="<<m<<"，从第一个人开始"<<endl;
	
	while(ListLenght()!=1)
	{
		i=0;
		while(i!=m)
		{
			i++;
			
			p=p->next;
			
			if(p==head)
			{
				p=p->next;
			}
		}
		
		p->prior->next=p->next;
		
		p->next->prior=p->prior;
		
		cout<<"第"<<p->data<<"人淘汰！"<<endl; 
		
		delete p;
	}
	
	cout<<"游戏结束，获胜者是第"<<p->data<<"人"<<endl; 
}


int main()
{
	CLinkListClass<int> obj;//创建对象 
	
	obj.CreateListR(10);//设置总人数 
	
	obj.Start(2);//设置间隔 
	
	
	return 0;
}

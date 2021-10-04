#include<iostream>

using namespace std;



template <typename T>
struct Node  //节点 
{
	T data;   //数据域 
	
	Node<T> *prior;  //前指针 
	
	Node<T> *next;  //后指针 
};

template <typename T>
class LinkListClass
{
	Node<T> *head;
	
public:
	
	LinkListClass(); //构造函数，创建一个空链表 
	
	~LinkListClass(); //析构函数，释放链表的所有节点 
	
	void CreateListR(T a[], int n); //用尾插法建立双链表
	
	void DispListC();//以字符形式输出所有结点值 
	
	void DispListD();//以整数形式输出所有结点值
	
	int ListLenght();//求双链表中数据结点的个数 
	
	T GetElem(int i);;//求双链表中某个数据元素值 
	
	int LocateElem(T a);//按元素值查找位置 
	
	void ListInsert(T a,int n);//插入数据元素 
	
	void ListDelete(int n);//删除数据元素 
	
	void Sort();//将单链表递增排序 
};

template <typename T>
LinkListClass<T>::LinkListClass()//构造函数 ，创建一个空链表
{
	head = new Node<T>;
	
	head -> next = NULL;
}

template <typename T>
LinkListClass<T>::~LinkListClass()//析构函数，释放链表的所有节点
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
void LinkListClass<T>::DispListC()//以字符形式输出所有结点值
{
	Node<T> *p;
	
	
	for(p=head->next; p!=NULL; p=p->next)
	{
		printf("%c",p ->data );
	}
} 

template <typename T>
void LinkListClass<T>::DispListD()//以整数形式输出所有结点值
{
	Node<T> *p;
	
	
	for(p=head->next; p!=NULL; p=p->next)
	{
		printf("%d",p ->data );
	}
} 
template <typename T>
void LinkListClass<T>::CreateListR(T a[], int n)//用尾插法建立双链表
{
	Node<T> *r,*s;
	
	r=head;
	
	for(int i=0;i<n;i++)
	{
		s=new Node<T>;
		
		s->data=a[i];
		
		r->next=s;
		
		s->prior=r;
		
		r=s;
	}
	r->next=NULL;
}

template <typename T>
int LinkListClass<T>::ListLenght()//求双链表中数据结点的个数 
{
	int i=0;
	
	Node<T> *p;
	
	p=head;//->next;
	
	while(p->next!=NULL)
	{
		i++;
		
		p=p->next;
	}
	return i;
}

template <typename T>
T LinkListClass<T>::GetElem(int i)//求双链表中某个数据元素值 
{
	Node<T> *p;
	int j=0;
	
	p=head;
	
	while(i!=j)
	{
		j++;
		
		p=p->next;
	}
	
	return p->data;
}

template <typename T>
int LinkListClass<T>::LocateElem(T a)//按元素值查找位置
{
	Node<T> *p;
	
	int i=0;
	
	for(p=head;p!=NULL;p=p->next,i++)
	{
		if(p->data==a)
		{
			return i;
		}
	}
}

template <typename T>
void LinkListClass<T>::ListInsert(T a,int n)//插入数据元素
{
	Node<T> *p,*s,*nex;
	int i=0;
	
	nex=head;
	
	while(i!=n)
	{
		i++;
		nex=nex->next;
	}
	
	s= new Node<T>;
	
	s->data=a;
	
	p=nex->prior;
	p->next=s;
	s->next=nex;
	nex->prior=s;
	s->prior=p;
	
}

template <typename T>
void LinkListClass<T>::ListDelete(int n)//删除数据元素
{
	Node<T> *p,*nex;
	int i=0;
	
	nex=head;
	
	while(i!=n)
	{
		i++;
		
		nex=nex->next;
	}
	
	p=nex->prior;
	nex=nex->next;
	p->next=nex;
	nex->prior=p;
	
	p=p->next;
	delete p;
	
}

template <typename T>
void LinkListClass<T>::Sort()//将单链表递增排序
{
	int i,j;
	
	Node<T> *p,*n;
	T temp;
	
	for(p=head->next; p!=NULL; p=p->next)
	{
		for(n=p->next;n!=NULL;n=n->next)
		{
			if(n->data<p->data)
			{
				temp=p->data;
				
				p->data=n->data;
				
				n->data=temp;
			}
		}
	}
	
}

int main()
{
	char a[]={'H','e','l','l','o','W','o','r','l','d'};
	int b[]={7,6,9,8,5};
	
	LinkListClass<char>  obj;//分别创建两个对象，并将两个数组创建成链表 
	LinkListClass<int> obj2;
	
	obj.CreateListR(a, 10);
	
	obj.DispListC();//输出全部结点值 
	
	printf("\n %d",obj.ListLenght());//输出长度 
	
	printf("\n %c",obj.GetElem(6));//获取第六个节点的数据域 
	
	printf("\n %d \n",obj.LocateElem('r'));//获取数据域为r的节点的位置 
	
	obj.ListInsert(',',6);//在第六个节点处插入， 
	obj.DispListC();//输出改变后的全部结点值 
	
	printf("\n");
	obj.ListDelete(6);//删除第六个节点 
	obj.DispListC();//输出改变后的全部结点值
	
	printf("\n");
	obj2.CreateListR(b,5);
	obj2.Sort();//将链表按节点数据域的大小升序排序 
	obj2.DispListD();//输出全部结点值 
	
	return 0;
}

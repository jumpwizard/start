#include<iostream>

using namespace std;



template <typename T>
struct Node  //�ڵ� 
{
	T data;   //������ 
	
	Node<T> *prior;  //ǰָ�� 
	
	Node<T> *next;  //��ָ�� 
};

template <typename T>
class LinkListClass
{
	Node<T> *head;
	
public:
	
	LinkListClass(); //���캯��������һ�������� 
	
	~LinkListClass(); //�����������ͷ���������нڵ� 
	
	void CreateListR(T a[], int n); //��β�巨����˫����
	
	void DispListC();//���ַ���ʽ������н��ֵ 
	
	void DispListD();//��������ʽ������н��ֵ
	
	int ListLenght();//��˫���������ݽ��ĸ��� 
	
	T GetElem(int i);;//��˫������ĳ������Ԫ��ֵ 
	
	int LocateElem(T a);//��Ԫ��ֵ����λ�� 
	
	void ListInsert(T a,int n);//��������Ԫ�� 
	
	void ListDelete(int n);//ɾ������Ԫ�� 
	
	void Sort();//��������������� 
};

template <typename T>
LinkListClass<T>::LinkListClass()//���캯�� ������һ��������
{
	head = new Node<T>;
	
	head -> next = NULL;
}

template <typename T>
LinkListClass<T>::~LinkListClass()//�����������ͷ���������нڵ�
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
void LinkListClass<T>::DispListC()//���ַ���ʽ������н��ֵ
{
	Node<T> *p;
	
	
	for(p=head->next; p!=NULL; p=p->next)
	{
		printf("%c",p ->data );
	}
} 

template <typename T>
void LinkListClass<T>::DispListD()//��������ʽ������н��ֵ
{
	Node<T> *p;
	
	
	for(p=head->next; p!=NULL; p=p->next)
	{
		printf("%d",p ->data );
	}
} 
template <typename T>
void LinkListClass<T>::CreateListR(T a[], int n)//��β�巨����˫����
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
int LinkListClass<T>::ListLenght()//��˫���������ݽ��ĸ��� 
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
T LinkListClass<T>::GetElem(int i)//��˫������ĳ������Ԫ��ֵ 
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
int LinkListClass<T>::LocateElem(T a)//��Ԫ��ֵ����λ��
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
void LinkListClass<T>::ListInsert(T a,int n)//��������Ԫ��
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
void LinkListClass<T>::ListDelete(int n)//ɾ������Ԫ��
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
void LinkListClass<T>::Sort()//���������������
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
	
	LinkListClass<char>  obj;//�ֱ𴴽��������󣬲����������鴴�������� 
	LinkListClass<int> obj2;
	
	obj.CreateListR(a, 10);
	
	obj.DispListC();//���ȫ�����ֵ 
	
	printf("\n %d",obj.ListLenght());//������� 
	
	printf("\n %c",obj.GetElem(6));//��ȡ�������ڵ�������� 
	
	printf("\n %d \n",obj.LocateElem('r'));//��ȡ������Ϊr�Ľڵ��λ�� 
	
	obj.ListInsert(',',6);//�ڵ������ڵ㴦���룬 
	obj.DispListC();//����ı���ȫ�����ֵ 
	
	printf("\n");
	obj.ListDelete(6);//ɾ���������ڵ� 
	obj.DispListC();//����ı���ȫ�����ֵ
	
	printf("\n");
	obj2.CreateListR(b,5);
	obj2.Sort();//�������ڵ�������Ĵ�С�������� 
	obj2.DispListD();//���ȫ�����ֵ 
	
	return 0;
}

#include<iostream>

using namespace std;

/*Josephus�������������Ϸ:N���˴�1��N��ţ�Χ����һ��ԲȦ����1�ſ�ʼ����һ��������������M�δ��ݺ��������������˱����������Χ
����ԲȦ�����������ڱ�������˺��������������������������Ϸ�����ʣ�µ���ȡʤ����ˣ����M=0��N=5�������������5�Ż�ʤ�����M=1��N=5��
��ô��������˵�˳����2��4��1��5��a����дһ��������M��N��һ��ֵ�µ�Josephus���⣬Ӧʹ��ĳ��򾡿�����߸�Ч��Ҫȷ���ܹ������Ԫ��*/



template <typename T>
struct Node  //�ڵ� 
{
	T data;   //������ 
	
	Node<T> *prior;//ǰָ�� 
	
	Node<T> *next;  //��ָ�� 
};

template <typename T>
class CLinkListClass//����ѭ������ 
{
	
private:
	Node<T> *head;
	
public:
	
	CLinkListClass(); //���캯��������һ�������� 
	
	~CLinkListClass(); //�����������ͷ���������нڵ� 
	
	void CreateListR( int n); //��β�巨����˫����
		
	int ListLenght();//��˫���������ݽ��ĸ��� 
	
	void Start(int m);//��ʼ���������� 
	
	
	
};

template <typename T>
CLinkListClass<T>::CLinkListClass()//���캯�� ������һ��������
{
	head = new Node<T>;
	
	head -> next = NULL;
}

template <typename T>
CLinkListClass<T>::~CLinkListClass()//�����������ͷ���������нڵ�
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
void CLinkListClass<T>::CreateListR( int n)//��β�巨����˫����
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
int CLinkListClass<T>::ListLenght()//��˫���������ݽ��ĸ��� 
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
	
	cout<<"һ��"<<ListLenght()<<"���˿�ʼ����������"<< "m="<<m<<"���ӵ�һ���˿�ʼ"<<endl;
	
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
		
		cout<<"��"<<p->data<<"����̭��"<<endl; 
		
		delete p;
	}
	
	cout<<"��Ϸ��������ʤ���ǵ�"<<p->data<<"��"<<endl; 
}


int main()
{
	CLinkListClass<int> obj;//�������� 
	
	obj.CreateListR(10);//���������� 
	
	obj.Start(2);//���ü�� 
	
	
	return 0;
}

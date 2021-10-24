#include<stdio.h>
#define N 100

int Heap[N];//����һ�������飬�����������N
int Heap_size = 0;//���е�ǰԪ�ص�����

//���
void put(int d)//Heap[0]�ǶѶ�
{
    int now, father, temp;//now�ǵ�ǰָ���Ԫ�أ�father���丸�ڵ�
    Heap[Heap_size] = d;//����Ԫ�����
    Heap_size++;
    now = Heap_size-1;//nowָ����Ԫ��
    while (now >= 1){
        father = now >> 1;//fatherָ���丸�ڵ�
        if (Heap[father] > Heap[now]){//�����ϴ���Ѿ�ֱ�ӽ���ѭ��
            break;
        }
        else{
            temp = Heap[now];//�������ϴ���ѣ��ͽ������ӽڵ��ֵ
            Heap[now] = Heap[father];
            Heap[father] = temp;
            now = father;//����nowָ�򸸽ڵ������һ���ж�
        }
    }
}

//����
int get()
{
    int now = 0, son, res = Heap[0], temp;//now�ǵ�ǰָ���Ԫ�أ�son�����ӽڵ�
    Heap[0] = Heap[Heap_size-1];
    Heap_size--;
    //����������С����
    while ((now * 2 + 1) < Heap_size){//������������ʱ
        son = now * 2 + 1;
        if ((now * 2 + 2) < Heap_size && Heap[now * 2 + 1] < Heap[now * 2 + 2]){//����������������������Сʱ
            son++;
        }

        temp = Heap[now];//�������ϴ���ѣ��ͽ������ӽڵ��ֵ
        Heap[now] = Heap[son];
        Heap[son] = temp;
        now = son;
    }
    return res;
}

int main()
{
    int i, n;
    printf("������ѵĳ���");
    scanf("%d", &n);
    printf("������ѵ�Ԫ��");
    for (i = 0; i < n; i++){
        scanf("%d", &Heap[i]);
        put(Heap[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d",get());
    }
    return 0;
}
#include"SmallHeap.h"
//���
void putHeap(int d)//Heap[0]�ǶѶ�
{
    int now, father, temp;//now�ǵ�ǰָ���Ԫ�أ�father���丸�ڵ�
    Heap[Heap_size] = d;//����Ԫ�����
    Heap_size++;
    now = Heap_size-1;//nowָ����Ԫ��
    while (now >= 1){
        father = now >> 1;//fatherָ���丸�ڵ�
        if (Heap[father] < Heap[now]){//������С���Ѿ�ֱ�ӽ���ѭ��
            break;
        }
        else{
            temp = Heap[now];//��������С���ѣ��ͽ������ӽڵ��ֵ
            Heap[now] = Heap[father];
            Heap[father] = temp;
            now = father;//����nowָ�򸸽ڵ������һ���ж�
        }
    }
}

//����
int getHeap()
{
    int now = 0, son, res = Heap[0], temp;//now�ǵ�ǰָ���Ԫ�أ�son�����ӽڵ�
    Heap[0] = Heap[Heap_size-1];
    Heap_size--;
    //���������С����
    while ((now * 2 + 1) < Heap_size){//������������ʱ
        son = now * 2 + 1;
        if ((now * 2 + 2) < Heap_size && Heap[now * 2 + 1] > Heap[now * 2 + 2]){//����������������������Сʱ
            son++;
        }

        temp = Heap[now];//��������С���ѣ��ͽ������ӽڵ��ֵ
        Heap[now] = Heap[son];
        Heap[son] = temp;
        now = son;
    }
    return res;
}

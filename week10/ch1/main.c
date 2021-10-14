#include<stdio.h>
#define N 100

int Heap[N];//建立一个堆数组，其最大容量是N
int Heap_size = 0;//堆中当前元素的数量

//入堆
void put(int d)//Heap[0]是堆顶
{
    int now, father, temp;//now是当前指向的元素，father是其父节点
    Heap[Heap_size] = d;//将新元素入堆
    Heap_size++;
    now = Heap_size-1;//now指向新元素
    while (now >= 1){
        father = now >> 1;//father指向其fuqjiedian
        if (Heap[father] < Heap[now]){//若符合小根堆就直接结束循环
            break;
        }
        else{
            temp = Heap[now];//若不符合小根堆，就交换父子节点的值
            Heap[now] = Heap[father];
            Heap[father] = temp;
            now = father;//并将now指向父节点进行下一次判断
        }
    }
}

//出堆
int get()
{
    int now = 0, son, res = Heap[0], temp;//now是当前指向的元素，son是其子节点
    Heap[0] = Heap[Heap_size-1];
    Heap_size--;
    //重新整理成小根堆
    while ((now * 2 + 1) < Heap_size){//当存在左子树时
        son = now * 2 + 1;
        if ((now * 2 + 2) < Heap_size && Heap[now * 2 + 1] > Heap[now * 2 + 2]){//当存在右子树且右子树较小时
            son++;
        }

        temp = Heap[now];//若不符合小根堆，就交换父子节点的值
        Heap[now] = Heap[son];
        Heap[son] = temp;
        now = son;
    }
    return res;
}

int main()
{
    int i, n;
    printf("请输入堆的长度");
    scanf("%d", &n);
    printf("请输入堆的元素");
    for (i = 0; i < n; i++){
        scanf("%d", &Heap[i]);
        put(Heap[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d",get());
    }
    return 0;
}

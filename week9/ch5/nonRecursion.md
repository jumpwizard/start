#  非递归遍历二叉树

在节点中新增了节点标志，并用栈来存储节点帮助遍历.  
首先将每个节点都设置一个标志，默认标志为假，根据节点的的状态进行如下流程。  
1、将根节点压入栈中  
2、进入循环:只要柱中元素个数大于0，进行循环操f作。  
2.1弹出栈]顶元素  
2.2如果这个栈顶元素标志为真，输出这个元素并且执行下一次循环  
2.3如果栈顶元素标志为假，将节点的标志设为真  
2.4将该节点的右子树、左子树、根压入到栈中  
2.5执行下一次循环


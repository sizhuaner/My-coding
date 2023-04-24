#include <iostream>
#include <string>
using namespace std;

//构建二叉树二叉链表存储结构
typedef struct BiTNode
{
    char data;                                // 数据
    struct BiTNode* lchild, * rchild; //根结点 、左孩子指针 、右孩子指针
    bool visit;                                 //判断此结点是否遍历过
} BiTNode, * BiTree;                       //二叉树的名称 、指向二叉树的指针

//递归创建二叉链表
void CrreatBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#') T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;//先序创建
        CrreatBiTree(T->lchild);
        //T->data=ch;//中序创建
        CrreatBiTree(T->rchild);
        //T->data=ch;//后序创建
    }

}

//构建存放二叉树的栈的结构体 以及 初始化栈、入栈、出栈
typedef struct
{
    BiTree* base;
    BiTree* top;

}SqStack;

// 初始化栈
void InitStack(SqStack& s)
{
    s.base = new BiTree[100];
    s.top = s.base;

}

//入栈

void  Push(SqStack& s, BiTree e)
{
    *s.top++ = e;

}

//出栈

void Pop(SqStack& s, BiTree& e)
{
    e = *(--s.top);
}

//非递归先序遍历二叉链表

//思想：

//指针从树根开始遍历

//如果数据为不为，则输出，然后这个结点进栈，接着指针指向此结点的左孩子

//如果空，则出栈，接着指针指向它父结点的右孩子

//依次循环 当指针当前指向的结点为空并且 这个存放结点的栈为空的时候结束while循环


void Preorde_Traversal_0(BiTree& T)
{
    cout << "非递归先序遍历:   ";
    SqStack s;
    InitStack(s);                        //先有一个存放结点的栈
    BiTree q = new BiTNode;     //new一个新的结点，BiTree类型的q指针指向这个结点
    BiTree p = T;                         // BiTree类型的p指针指向 二叉树
    while (p || !(s.base == s.top))
    {
        if (p)
        {
            cout << p->data << " ";
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s, q);
            p = q->rchild;
        }
    }
}

//非递归中序遍历二叉链表

//思想：

//指针从树根开始遍历

//如果数据不为空，然后这个结点进栈，接着指针指向此结点的左孩子

//如果空 则出栈 且输出该栈顶结点（即指针当前指向结点的父结点），接着指针指向该父结点的右孩子
//依次循环 当指针当前指向的结点为空并且 这个存放结点的栈为空的时候结束while循环


void Inorder_Traversal_0(BiTree& T)
{
    cout << "非递归中序遍历:   ";
    SqStack s;
    InitStack(s);
    BiTree q = new BiTNode;
    BiTree p = T;
    while (p || !(s.base == s.top))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s, q);
            cout << q->data << " ";
            p = q->rchild;
        }
    }

}


//非递归后序遍历二叉链表

//思想：

//指针从树根开始遍历，永远只有遍历过才能输出（即结点的visit值为0）

//如果数据不为空，则设置这个结点为未被访问的结点（即visit值为1），进栈，接着指针指向此结点的左孩子

//如果空 则出栈 并且判断该栈顶结点（即指针当前指向结点的父结点）是否访问过

        //如果未被访问过，则设置为已被访问过，入栈，接着指针指向 栈顶结点（即指针当前指向结点的父结点）的右孩子

        //如果已被访问过，则输出指针所指当前结点的数据，并且置空该结点，使循环进入数据为空的情况
//依次循环 当指针当前指向的结点为空并且 这个存放结点的栈为空的时候结束while循环

void Postorder_Traversal(BiTree& T)
{
    cout << "非递归后序遍历:   ";
    SqStack s;
    InitStack(s);
    BiTree q = new BiTNode;
    BiTree p = T;
    while (p || !(s.base == s.top))
    {
        if (p)
        {
            q = p;
            q->visit = 1;
            Push(s, q);
            p = p->lchild;
        }
        else
        {
            Pop(s, q);
            if (q->visit == 1)
            {
                q->visit = 0;
                Push(s, q);
                p = q->rchild;
            }
            else
            {
                cout << q->data << " ";
                p = NULL;
            }
        }
    }
}

//主函数 测试部分
int main()
{
    BiTree A;

    CrreatBiTree(A);

    //Preorde_Traversal(A); cout << endl;   //这个是递归先序遍历，代码里面没写，忽略就行

    Inorder_Traversal_0(A); cout << endl;

    Preorde_Traversal_0(A); cout << endl;

    Postorder_Traversal(A); cout << endl;



    return 0;
}

#include <iostream>
#include <string>
using namespace std;

//������������������洢�ṹ
typedef struct BiTNode
{
    char data;                                // ����
    struct BiTNode* lchild, * rchild; //����� ������ָ�� ���Һ���ָ��
    bool visit;                                 //�жϴ˽���Ƿ������
} BiTNode, * BiTree;                       //������������ ��ָ���������ָ��

//�ݹ鴴����������
void CrreatBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#') T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;//���򴴽�
        CrreatBiTree(T->lchild);
        //T->data=ch;//���򴴽�
        CrreatBiTree(T->rchild);
        //T->data=ch;//���򴴽�
    }

}

//������Ŷ�������ջ�Ľṹ�� �Լ� ��ʼ��ջ����ջ����ջ
typedef struct
{
    BiTree* base;
    BiTree* top;

}SqStack;

// ��ʼ��ջ
void InitStack(SqStack& s)
{
    s.base = new BiTree[100];
    s.top = s.base;

}

//��ջ

void  Push(SqStack& s, BiTree e)
{
    *s.top++ = e;

}

//��ջ

void Pop(SqStack& s, BiTree& e)
{
    e = *(--s.top);
}

//�ǵݹ����������������

//˼�룺

//ָ���������ʼ����

//�������Ϊ��Ϊ���������Ȼ���������ջ������ָ��ָ��˽�������

//����գ����ջ������ָ��ָ�����������Һ���

//����ѭ�� ��ָ�뵱ǰָ��Ľ��Ϊ�ղ��� �����Ž���ջΪ�յ�ʱ�����whileѭ��


void Preorde_Traversal_0(BiTree& T)
{
    cout << "�ǵݹ��������:   ";
    SqStack s;
    InitStack(s);                        //����һ����Ž���ջ
    BiTree q = new BiTNode;     //newһ���µĽ�㣬BiTree���͵�qָ��ָ��������
    BiTree p = T;                         // BiTree���͵�pָ��ָ�� ������
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

//�ǵݹ����������������

//˼�룺

//ָ���������ʼ����

//������ݲ�Ϊ�գ�Ȼ���������ջ������ָ��ָ��˽�������

//����� ���ջ �������ջ����㣨��ָ�뵱ǰָ����ĸ���㣩������ָ��ָ��ø������Һ���
//����ѭ�� ��ָ�뵱ǰָ��Ľ��Ϊ�ղ��� �����Ž���ջΪ�յ�ʱ�����whileѭ��


void Inorder_Traversal_0(BiTree& T)
{
    cout << "�ǵݹ��������:   ";
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


//�ǵݹ���������������

//˼�룺

//ָ���������ʼ��������Զֻ�б��������������������visitֵΪ0��

//������ݲ�Ϊ�գ�������������Ϊδ�����ʵĽ�㣨��visitֵΪ1������ջ������ָ��ָ��˽�������

//����� ���ջ �����жϸ�ջ����㣨��ָ�뵱ǰָ����ĸ���㣩�Ƿ���ʹ�

        //���δ�����ʹ���������Ϊ�ѱ����ʹ�����ջ������ָ��ָ�� ջ����㣨��ָ�뵱ǰָ����ĸ���㣩���Һ���

        //����ѱ����ʹ��������ָ����ָ��ǰ�������ݣ������ÿոý�㣬ʹѭ����������Ϊ�յ����
//����ѭ�� ��ָ�뵱ǰָ��Ľ��Ϊ�ղ��� �����Ž���ջΪ�յ�ʱ�����whileѭ��

void Postorder_Traversal(BiTree& T)
{
    cout << "�ǵݹ�������:   ";
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

//������ ���Բ���
int main()
{
    BiTree A;

    CrreatBiTree(A);

    //Preorde_Traversal(A); cout << endl;   //����ǵݹ������������������ûд�����Ծ���

    Inorder_Traversal_0(A); cout << endl;

    Preorde_Traversal_0(A); cout << endl;

    Postorder_Traversal(A); cout << endl;



    return 0;
}

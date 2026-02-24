#ifndef BASIC_STRUCT
#define BASIC_STRUCT

#include <stdlib.h>

// 数组增删改
// 数组在定义时候就已经确定大小了，在插入和删除时候，要申请一个新的数组，把元素挪进去

// 整型链表
struct ListNode
{
    /* data */
    int val;
    struct ListNode *next;
};

// 构造函数
ListNode *newListNode(int val)
{
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 增加元素，头插法和尾插法，任意节点处插入
// 传入节点位置插入一个节点
void insertNode(ListNode *node, ListNode *newListNode)
{
    // 下一个节点给到新插入的节点，再把插入的节点给到前一个节点
    newListNode->next = node->next;
    node->next = newListNode;
}

// 删除元素
// 删除某个节点后面的第一个节点

void removeNode(ListNode *node)
{
    // 保存要删掉节点地址
    // node->delNode->nextNode
    ListNode *delNode = node->next;
    node->next = delNode->next;
    free(delNode);
}

// 修改元素值

// 查找元素
int findNode(ListNode *head, int target)
{
    int index = 0;
    while (head)
    {
        if (head->val == target)
            return index;
        head = head->next;
        index++;

        /* code */
    }
    return -1;
}

// 双向链表
struct DoubleNode
{

    int val;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};

// 双向链表构造函数
DoubleNode *newDoubleNode(int val)
{
    struct DoubleNode *Dnode = (DoubleNode *)malloc(sizeof(DoubleNode));
    Dnode->val = val;
    Dnode->next = NULL;
    Dnode->prev = NULL;
    return Dnode;
}

// 链表栈
struct ListStack
{
    ListNode *top;
    int size;
};

// 构造函数
ListStack *newStack(int val)
{
    ListStack *s = (ListStack *)malloc(sizeof(ListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

// 析构函数
// 站内的所有元素内存删掉，最后删掉栈
ListStack *delStack(ListStack *s)
{
    while (s->top)
    {
        ListNode *tmp = s->top->next;
        free(s->top);
        s->top = tmp;
    }
    free(s);
}

// 入栈
ListStack *pushStack(ListStack *s, int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = data;
    node->next = s->top;
    s->top = node;
    s->size++;
    return s;
}

// 出栈,弹出第一个元素,
int popStack(ListStack *s)
{
    ListNode *node = s->top->next;
    int data = s->top->val;
    free(s->top);
    s->top = node;
    return data;
}

#endif
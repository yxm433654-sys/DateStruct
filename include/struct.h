#ifndef BASIC_STRUCT
#define BASIC_STRUCT

#include <stdlib.h>
#include <stdbool.h>

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
struct ListNode *newListNode(int val)
{
    struct ListNode *node;
    node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 增加元素，头插法和尾插法，任意节点处插入
// 传入节点位置插入一个节点
void insertNode(struct ListNode *node, struct ListNode *newListNode)
{
    // 下一个节点给到新插入的节点，再把插入的节点给到前一个节点
    newListNode->next = node->next;
    node->next = newListNode;
}

// 删除元素
// 删除某个节点后面的第一个节点

void removeNode(struct ListNode *node)
{
    // 保存要删掉节点地址
    // node->delNode->nextNode
    struct ListNode *delNode = node->next;
    node->next = delNode->next;
    free(delNode);
}

// 修改元素值

// 查找元素
int findNode(struct ListNode *head, int target)
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

// 链表栈
struct ListStack
{
    struct ListNode *top;
    int size;
};

// 构造函数
struct ListStack *newStack(int val)
{
    struct ListStack *s = (struct ListStack *)malloc(sizeof(struct ListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

// 析构函数
// 站内的所有元素内存删掉，最后删掉栈
struct ListStack *delStack(struct ListStack *s)
{
    while (s->top)
    {
        struct ListNode *tmp = s->top->next;
        free(s->top);
        s->top = tmp;
    }
    free(s);
}

// 入栈
struct ListStack *pushStack(struct ListStack *s, int data)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = data;
    node->next = s->top;
    s->top = node;
    s->size++;
    return s;
}

// 出栈,弹出第一个元素,
int popStack(struct ListStack *s)
{
    struct ListNode *node = s->top->next;
    int data = s->top->val;
    free(s->top);
    s->top = node;
    return data;
}

// 链表队列
struct Queue
{
    struct ListNode *front, *rear;
    int queueSize;
};
// 构造函数
struct Queue *newQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->queueSize = 0;
    return q;
}

// 析构函数
void delQueue(struct Queue *q)
{
    while (q->front)
    {
        struct ListNode *node = q->front->next;
        q->front = node;
        free(node);
    }
    free(q);
}
// 入队
void pushQueue(struct Queue *q, int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (q->front)
    {
        q->front = node;
        q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
    q->queueSize++;
}
// 出队
int popQueue(struct Queue *q)
{
    int num = q->front->val;
    struct ListNode *node = q->front;
    q->front = q->front->next;
    free(node);
    q->queueSize--;
    return num;
}

// 循环数组队列
// 怎么实现的，队头指向0位置，队尾指向下一个位置，取模运算让两个指针循环在数组空间
struct arryQueue
{
    int *arry;
    int front;
    // int rear;     队尾，队的长度+1
    int size;
    int capacity; // 容量和size，容量指的是队列总大小，size是实际存了多少
};

// 构造函数
struct arryQueue *create_queue(int capacity)
{
    // 一块循环队列的内存
    struct arryQueue *q = (struct arryQueue *)malloc(sizeof(struct arryQueue));
    // 这块内存要给到实现循环队列的数组，计算数组的空间大小
    // 定义头指针
    q->capacity = capacity;
    q->arry = (int *)malloc(sizeof(int) * q->capacity);
    q->front = 0;
    q->size = 0;
    return q;
}
// 析构函数
void delArryQueue(struct arryQueue *q)
{
    // malloc 两块内存
    free(q->arry);
    free(q);
}

// 队列长度
int sizeArryQueue(struct arryQueue *q)
{
    return q->capacity;
}
// 队列是否为空
bool isEmpty(struct arryQueue *q)
{
    return q->capacity == q->size;
}
// 入队
struct arryQueue *pushArryQueue(struct arryQueue *q, int val)
{
    // 不扩容数组，要判断是不是队满
    if (q->size == q->capacity)
    {
        return 1;
    }
    int rear = (q->front + q->size) % (q->capacity);
    q->arry[rear] = val;
    q->size++;
    return q;

    /*会不会出现队尾指针超越队头指针
        0 1 2 3    capacity = 4, size = 2,没有出队，队头指向0，队尾指向2;
        入队两个元素，达到队满，队尾指向最后一个元素
        出队两个元素，队头指向2，队尾不变，size=2
        入队两个元素，队头不变，指向2，队尾指向1

        结论:因为有标志位设置，队满的时候两个不会超越
    */
}
// 出队
int popArryQueue(struct arryQueue *q)
{
    int num = q->arry[q->front];
    q->front = (q->front + 1) % (q->capacity);
    q->size--;
    return num;
}

// 返回队首
int peek(struct arryQueue *q)
{
    return q->arry[q->front];
}

// 双向链表
struct DoubleNode
{

    int val;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};
// 双向链表构造函数
struct DoubleNode *newDoubleNode(int val)
{
    struct DoubleNode *Dnode = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
    Dnode->val = val;
    Dnode->next = NULL;
    Dnode->prev = NULL;
    return Dnode;
}
// 双向链表队列
struct doublyQueue
{
    int size;
    struct DoubleNode *prev, *next;
};

// 构造函数

struct doublyQueue *create_doubly_Queue()
{
    struct doublyQueue *q = (struct doublyQueue *)mallloc(sizeof(struct doublyQueue));
    q->prev = NULL;
    q->next = NULL;
    q->size = 0;
    return q;
}
// 析构函数
void del_doubly_queue(struct doublyQueue *q)
{
    while (q->prev)
    {
        struct DoubleNode *node = q->prev;
        q->prev = q->prev->next;
        free(node);
    }
    free(q);
}

// 队列长度
int size_doubly_queue(struct doublyQueue *q)
{
    return q->size;
}
// 队列是否为空
bool isEmpty_doubly_queue(struct doublyQueue *q)
{
    return q->size;
}

// 入队
struct doublyQueue *push_dequeue(int val, struct doublyQueue *q)
{
    struct DoubleNode *node = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
    node->next = q->prev;
    q->prev = node;
    q->size++;
    return q;
}
// 出队
int pop_dequeue(struct doublyQueue *q)
{
    int val = q->prev->val;
    struct DoubleNode *node = q->prev;
    q->prev = q->prev->next;
    free(node);
    q->size--;
    return val;
}
// 返回队首
int peek_dequeue(struct doublyQueue *q)
{
    return q->prev->val;
}

// 双向数组队列
// 计算数组队列索引
int index_arr_queue(struct arryQueue *q, int num)
{
    return (num + q->capacity) % q->capacity;
}
// 队头入队
struct arryQueue *push_arr_queue_first(struct arryQueue *q, int val)
{
    if (q->capacity == q->size)
    {
        /* code */
        return 1;
    }
    q->front = index_arr_queue(q, q->front + q->capacity - 1);
    q->arry[q->front] = val;
    q->size++;
    return q;
}

// 队尾出队
int pop_arr_queue_last(struct arryQueue *q)
{
    if (q->size == 0)
    {
        /* code */
        return 1;
    }
    int num = q->arry[(q->front + q->size) % (q->capacity)];
    q->front = index_arr_queue(q, (q->front + q->size) % (q->capacity) - 1);
    q->size--;
    return num;
}

// 返回队首
int peek_arr_queue_first(struct arryQueue *q)
{
    if (q->size == 0)
    {
        /* code */
        return -1;
    }
    return q->arry[q->front];
}

// 返回队尾
int peek_arr_queue_last(struct arryQueue *q)
{
    if (q->size == 0)
    {
        /* code */
        return -1;
    }
    return q->arry[(q->front + q->size) % (q->capacity)];
}

// 二叉树

#endif
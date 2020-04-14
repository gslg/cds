#include <stdio.h>
#include <stdlib.h>

//链表节点
struct Node
{
    int data;
    struct Node *next;
};

//在链表尾部插入
void InsertLast(int data);

//在链表头部插入
void InsertFirst(int data);

//在指定index处插入，index从0开始
void InsertAtIndex(int data, int index);

//删除指定index处的节点
void Delete(int index);

//打印
void Print();

//头节点
struct Node *head;

void InsertLast(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;

    struct Node *temp2 = head;
    if (temp2 == NULL)
    { //空链表
        head = temp;
        return;
    }

    while (temp2->next != NULL) //找到尾节点
    {
        temp2 = temp2->next;
    }

    temp2->next = temp;
}

void InsertFirst(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;

    if (head == NULL)
    { //空链表
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void InsertAtIndex(int data, int index)
{
    if (index == 0)
    {
        InsertFirst(data);
        return;
    }

    if (head == NULL)
    { //index !=0 且 head为NULL
        perror("空链表...");
        return;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;

    struct Node *offset = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (offset == NULL)
        {
            perror("超出链表个数...");
            return;
        }

        offset = offset->next;
    }

    temp->next = offset->next;
    offset->next = temp;
}

void Delete(int index)
{
    struct Node *offset = head;
    if (offset == NULL)
        return;

    if (index == 0)
    {
        head = offset->next;
        free(offset);
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (offset == NULL)
        {
            perror("超出链表个数...");
            return;
        }

        offset = offset->next;
    }

    struct Node *del = offset->next;

    offset->next = del->next;

    free(del);
}

void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    head = NULL;

    InsertLast(1);
    InsertLast(2);
    InsertLast(3);
    InsertLast(4);

    Print(); //1234

    InsertFirst(5);
    InsertFirst(6);
    InsertFirst(7);

    Print(); // 7 6 5 1 2 3 4

    InsertAtIndex(8, 1); //7 8 6 5 1 2 3 4
    Print();

    InsertAtIndex(9, 0); //9 7 8 6 5 1 2 3 4
    Print();

    InsertAtIndex(10, 5); //9 7 8 6 5 10 1 2 3 4
    Print();

    Delete(0); //7 8 6 5 10 1 2 3 4
    Print();

    Delete(3); //7 8 6 10 1 2 3 4
    Print();

    return 0;
}

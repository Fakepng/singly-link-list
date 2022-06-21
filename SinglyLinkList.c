#include <stdio.h>
#include "Node.h"
#define true 1
#define false 0
typedef int boolean;
struct Node *newNode;
struct Node *head;
struct Node *curr;
struct Node *prev;

void add(int newItem)
{
    if (head == NULL)
    {
        newNode = createNode(newItem, NULL);
    }
    else
    {
        newNode = createNode(newItem, head);
    }
    head = newNode;
};

boolean searchItem(int item)
{
    curr = head;
    prev = NULL;
    boolean status = false;
    while (curr != NULL)
    {
        if (getItem(curr) == item)
        {
            status = true;
            break;
        }
        else
        {
            prev = curr;
            curr = getNext(curr);
        }
    }

    return status;
};

void deleteNode(int item)
{
    if (searchItem(item))
    {
        if (prev == NULL)
        {
            head = getNext(curr);
        }
        else
        {
            setNext(prev, getNext(curr));
        }
    }
    else
    {
        printf("Item not found\n");
    }
};

void insert(int iteminsert, int newItem)
{
    newNode = createNode(newItem, NULL);
    if (searchItem(iteminsert))
    {
        if (prev == NULL)
        {
            setNext(newNode, curr);
            head = newNode;
        }
        else
        {
            setNext(newNode, curr);
            setNext(prev, newNode);
        }
    }
    else
    {
        if (head == NULL)
        {
            setNext(newNode, curr);
            head = newNode;
        }
        else if (curr == NULL)
        {
            setNext(prev, newNode);
        }
    }
};

void showdata()
{
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", getItem(curr));
        curr = getNext(curr);
    }
    printf("\n");
};

void main()
{
    add(9);
    printf("add 9: ");
    showdata();
    add(10);
    printf("add 10: ");
    showdata();
    add(11);
    printf("add 11: ");
    showdata();
    add(12);
    printf("add 12: ");
    showdata();
    deleteNode(10);
    printf("delete 10: ");
    showdata();
    deleteNode(12);
    printf("delete 12: ");
    showdata();
    insert(11, 15);
    printf("insert 15 before 11: ");
    showdata();
    insert(11, 17);
    printf("insert 17 before 11: ");
    showdata();
    insert(18, 19);
    printf("insert 19 at last Link List: ");
    showdata();
    scanf("%d");
};
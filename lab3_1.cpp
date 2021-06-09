#include <iostream>
#include "RectangleA.h"
using namespace std;
struct Node {
    RectangleA rect= RectangleA(Point(0, 0), Point(0, 0));
    Node* next;
    Node* prev;
};
typedef Node* PNode;
PNode Head = NULL;
PNode Tail = NULL;
 
struct list
{
    PNode CreateNode(RectangleA re)
    {
        PNode NewNode = new Node;
        NewNode->rect = re;
        NewNode->next = NULL;
        NewNode->prev = NULL;
        return NewNode;
    }
    void AddFirst(PNode* Head, PNode NewNode)
    {
        NewNode->next = *Head;
        NewNode->prev = NULL;
        *Head = NewNode;
        if (NewNode->next == NULL) Tail = NewNode;
        else
        NewNode->next->prev = NewNode;
        
        
    }
 
    void AddAfter(PNode p, PNode NewNode)
    {
        NewNode->next = p->next;
        NewNode->prev = p;
        p->next = NewNode;
        if (NewNode->next == NULL) Tail=NewNode;
        else
        {
            PNode q = NewNode->next;
            q->prev = NewNode;
        }
        
    }
    void AddBefore(PNode p, PNode NewNode)
    {
        PNode q = Head;
        q=Search(p);
        if (Head == q) {
            AddFirst(&Head, NewNode);
            return;
        }
        AddAfter(q->prev, NewNode);
        
    }
    void AddLast(PNode* Head, PNode NewNode)
    {
        PNode q = *Head;
        if (*Head == NULL) {
            AddFirst(Head, NewNode);
            return;
        }
        while (q->next) q = q->next;
        AddAfter(q, NewNode);
        
        
        
    }
    void DeleteNode(PNode p)
    {
        PNode q = Head;
        if (Head == p) {
            Head = p->next;
            p->next->prev = NULL;
        }
        else {
            if (Tail == p)
            {
                Tail = p->prev;
                p->prev->next = NULL;
            }
            else
            {
                Search(p);
                p->next->prev = p->prev;
                p->prev->next = p->next;
            }
            
 
        }
        delete p;
    }
    PNode Search(PNode p)
    {
        PNode ptr = Head;
        while (ptr!=NULL)
        {
            if (ptr == p) break;
            ptr = ptr->next;
            
        }
        return ptr;
    }
 
};
int main()
{
    setlocale(LC_ALL, "rus");
    list dspisok;
    RectangleA a = RectangleA(Point(0, 0), Point(4, 4));
    RectangleA b = RectangleA(Point(10, 32), Point(12, 4));
    RectangleA c = RectangleA(Point(30, 72), Point(4, 43));
    RectangleA d = RectangleA(Point(40, 16), Point(54, 4));
    RectangleA arr[]={ a,b,c,d };
    PNode ar[4];
    for (int i = 0; i < 4; i++)
    {
        ar[i] = dspisok.CreateNode(arr[i]);
    }
    dspisok.AddFirst(&Head, ar[0]);
    dspisok.AddAfter(ar[0], ar[1]);
    dspisok.AddAfter(ar[1], ar[3]);
    dspisok.AddLast(&Head, ar[2]);
    PNode p=Head;
    while (p!=NULL)
    {   
        p->rect.info();
        p = p->next;
    }
    dspisok.DeleteNode(ar[1]);
    p= Tail;
    while (p != NULL)
    {
        p->rect.info();
        p = p->prev;
    }
 system("pause");   
}

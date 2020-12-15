#include "list.h"
#define createNode createList
void createList(plist *this, ElementType element)
{
    this[0] = (list *)malloc(sizeof(list));
    this[0]->element = element;
    this[0]->next = NULL;
}
//this必须由create创建
void push(plist *this, ElementType element)
{
    pnode curr, temp = this[0];
    createNode(&curr, element);
    while (temp->next != NULL && (temp = temp->next))
        continue;
    temp->next = curr;
}

ElementType pop(plist *this)
{
    pnode pre = this[0], curr = this[0];
    ElementType retn;
    while ((curr = pre->next) && (curr->next))
    {
        pre = curr;
    }
    if (curr != NULL){
        pre->next = NULL;
    }
    retn = curr == NULL ? pre->element : curr->element;
    free(curr);
    return retn;
    
}
//diff必须小于等于node个数
void insertNode(plist *this, ElementType element, size_t diff)
{
    pnode curr, temp = this[0];
    createNode(&curr, element);
    int i = 0;
    while (temp->next != NULL && i < diff && (temp = temp->next))
        ++i;
    pnode t = temp->next;
    temp->next = curr;
    curr->next = t;
 
}

ElementType removeNode(plist* this, size_t diff){
    return 0;
}

//使用后THIS将为null
void removeList(plist *this)
{
    list *p;
    while (this[0] != NULL)
    {
        p = this[0]->next;
        free(this[0]);
        this[0] = p;
    }
}
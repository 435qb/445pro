#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef long ElementType;

typedef
struct LIST{
    ElementType element;
    struct LIST* next;
} list, node;
typedef list  *plist, *pnode;

void createList(plist*, ElementType);
void push(plist*, ElementType);
ElementType pop(plist*);
void insertNode(plist*, ElementType, size_t);
ElementType removeNode(plist*, size_t);
void removeList(plist*);
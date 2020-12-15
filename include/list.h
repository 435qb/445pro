#ifndef _LIST_H
#define _LIST_H

#define INIT(name)                                 \
    typedef struct name##LIST                      \
    {                                              \
        name element;                              \
        struct name##LIST *next;                   \
    } name##List;                                  \
    void name##Create(name##List *, const name *); \
    void name##Push(name##List *, const name *);   \
    name *name##Search(name##List *, int id);      \
    void name##Delete(name##List *, int id); \
    void name##Free(name##List *);

#define INITFUNC(name)\
void name##Create(name##List *wl, const name *w)\
{\
    wl = (name##List *)malloc(sizeof(name##List));\
    wl->element = *w;\
    wl->next = NULL;\
}\
void name##Push(name##List *wl, const name *w)\
{\
    name##List *curr, *temp = wl;\
    name##Create(&curr, w);\
    while (temp->next != NULL && (temp = temp->next))\
        continue;\
    temp->next = curr;\
}\
name * name##Search(name##List *wl, int id)\
{\
    name##List *curr = wl;\
    while (curr != NULL)\
    {\
        if (curr->element._id == id)\
        {\
            return &(curr->element);\
        }\
        curr = curr->next;\
    }\
    return NULL;\
}\
\
void name##Delete(name##List *wl, int id)\
{\
    name##List *curr = wl, *pre = wl;\
    while (curr != NULL)\
    {\
\
        if (curr->element._id == id)\
        {\
            if (pre != curr)\
            {\
                name##List *temp = curr->next;\
                pre->next = temp;\
            }\
            free(curr);\
            return;\
        }\
        curr = curr->next;\
    }\
}\
void name##Free(name##List *wl){\
    name##List* next;\
    while (wl != NULL)\
    {\
        next = wl->next;\
        free(wl);\
        wl = next;\
    }\
}
#endif
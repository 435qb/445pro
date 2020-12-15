#include <stdio.h>
#include "list.h"
int main(){
    plist l;
    createList(&l, 1);
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    insertNode(&l, 0, 0);
    insertNode(&l, 5, 5);
    printf("%ld ", pop(&l));
    printf("%ld ", pop(&l));
    printf("%ld ", pop(&l));
    printf("%ld\n", pop(&l));    

    return 0;
}
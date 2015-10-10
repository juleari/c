#include <stdio.h> 
#include <stdlib.h>
 
struct Elem { 
        /* <<Тег>>, описывающий тип значения 
           в <<голове>> списка */ 
    enum { 
            INTEGER, 
            FLOAT, 
            LIST 
    } tag; 

    /* Само значение в <<голове>> списка */ 
    union { 
            int i; 
            float f; 
            struct Elem *list; 
    } value; 

    /* Указатель на <<хвост>> списка */ 
    struct Elem *tail; 
};
 

struct Elem *searchlist(struct Elem *elem, int k){

    struct Elem* ptr1;

    if ( elem == NULL ) return NULL;

    switch ( elem->tag )
    {
        case INTEGER : 
            if (elem->value.i == k)
                return elem;
            break;

        case LIST :
            ptr1 = searchlist( elem->value.list, k );
            
            if ( ptr1 == NULL ) return searchlist(elem->tail, k);
            return ptr1;

        default : break;
    }
    
    return searchlist(elem->tail, k);
}
 
int main() 
{
    struct Elem e12;
    e12.tag = INTEGER;
    e12.value.i = 70;
    e12.tail = NULL;

    struct Elem e11;
    e11.tag = LIST;
    e11.value.list = NULL;
    e11.tail = &e12;

    struct Elem e10;
    e10.tag = INTEGER;
    e10.value.i = 60;
    e10.tail = &e11;

    struct Elem e9;
    e9.tag = FLOAT;
    e9.value.f = 10.5e-5;
    e9.tail = &e10;

    struct Elem e8;
    e8.tag = INTEGER;
    e8.value.i = 50;
    e8.tail = &e9;

    struct Elem e7;
    e7.tag = FLOAT;
    e7.value.f = 10.5e-5;
    e7.tail = &e8;

    struct Elem e6;
    e6.tag = INTEGER;
    e6.value.i = 100;
    e6.tail = &e7;

    struct Elem e5;
    e5.tag = INTEGER;
    e5.value.i = 60;
    e5.tail = &e6;

    struct Elem e4;
    e4.tag = INTEGER;
    e4.value.i = 40;
    e4.tail = &e5;

    struct Elem e3;
    e3.tag = INTEGER;
    e3.value.i = 80;
    e3.tail = &e4;

    struct Elem e2;
    e2.tag = INTEGER;
    e2.value.i = 50;
    e2.tail = &e3;

    struct Elem e1;
    e1.tag = INTEGER;
    e1.value.i = 20;
    e1.tail = &e2;

    struct Elem e0;
    e0.tag = FLOAT;
    e0.value.f = 2.5;
    e0.tail = &e1;

    struct Elem *x = searchlist(&e0, 70);
    if (x == &e12) {
        printf("CORRECT\n");
    } else {
        /* Если функция searchlist работает правильно,
        сюда никогда не будет передано управление! */
        printf("WRONG\n");
    }

    return 0;
}
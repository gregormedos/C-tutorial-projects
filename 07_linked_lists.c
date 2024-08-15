#include <stdio.h>
#include <stdlib.h>


/*----------------------------------------------
STRUCTURES
----------------------------------------------*/
typedef struct _Node
{
    double data;
    struct _Node *Next;
} Node;


/*----------------------------------------------
FUNCTIONS
----------------------------------------------*/
void list_append(Node **List_ref, double data_arg)
{
    while (*List_ref != NULL) {
        List_ref = &((*List_ref)->Next);
    }
    *List_ref = (Node *)malloc(sizeof(Node)); //allocating
    printf("allocating\n");
    (*List_ref)->data = data_arg;
    (*List_ref)->Next = NULL;
}

void list_push(Node **List_ref, double data_arg)
{
    Node *List_copy = *List_ref;

    *List_ref = NULL;
    *List_ref = (Node *)malloc(sizeof(Node)); //allocating
    printf("allocating\n");
    (*List_ref)->data = data_arg;
    (*List_ref)->Next = List_copy;

    List_copy = NULL;
}

void list_delete(Node **List_ref)
{
    Node *Next_copy = NULL;

    while (*List_ref != NULL) {
        Next_copy = (*List_ref)->Next;
        free(*List_ref); //deallocating
        printf("deallocating\n");
        *List_ref = Next_copy;
    }
}

void list_print(const Node *List_copy)
{
    while (List_copy != NULL) {
        printf("%16.7lf\n", List_copy->data);
        List_copy = List_copy->Next;
    }
}

int list_size(const Node *List_copy)
{
    int size = 0;

    while (List_copy != NULL) {
        size++;
        List_copy = List_copy->Next;
    }

    return size;
}

void list_append_at(Node **List_ref, int index_arg, double data_arg)
{
    int size = list_size(*List_ref);
    Node *Next_copy = NULL;

    if (index_arg < size) {
        for (int i=0; i<index_arg; i++) {
            List_ref = &((*List_ref)->Next);
        }
        Next_copy = (*List_ref)->Next;
        (*List_ref)->Next = NULL;
        (*List_ref)->Next = (Node *)malloc(sizeof(Node)); //allocating
        printf("allocating\n");
        List_ref = &((*List_ref)->Next);
        (*List_ref)->data = data_arg;
        (*List_ref)->Next = Next_copy;
    }
}

double list_value_at(const Node *List_copy, int index_arg)
{
    if (index_arg < list_size(List_copy)) {
        for (int i=0; i<index_arg; i++) {
            List_copy = List_copy->Next;
        }

        return List_copy->data;
    }

    return 0.0;
}

void list_delete_at(Node **List_ref, int index_arg)
{
    int size = list_size(*List_ref);
    Node *Next_copy = NULL;

    if (index_arg < size) {
        for (int i=0; i<index_arg; i++) {
            List_ref = &((*List_ref)->Next);
        }
        Next_copy = (*List_ref)->Next;
        free(*List_ref); //deallocating
        printf("deallocating\n");
        *List_ref = Next_copy;
    }
}


/*----------------------------------------------
MAIN PROGRAM
----------------------------------------------*/
int main()
{
    Node* List = NULL;
    double a1[4] = {1.0, 2.0, 3.0, 4.0};
    double a2[4] = {-1.0, -2.0, -3.0, -4.0};


    printf("----------------------------------------\n");
    printf("empty List\n");
    printf("----------------------------------------\n");
    list_print(List);
    printf("size of List = %16d\n", list_size(List));


    printf("----------------------------------------\n");
    printf("dynamicly allocated List\n");
    printf("----------------------------------------\n");
    for (int i=0; i<4; i++) {
        list_append(&List, a1[i]);
        list_push(&List, a2[i]);
    }
    list_append_at(&List, 3, 0.0);
    list_print(List);
    printf("size of List = %16d\n", list_size(List));
    printf("first element of List = %16.7lf\n", list_value_at(List, 0));
    printf("last element of List = %16.7lf\n", list_value_at(List, list_size(List)-1));


    list_delete_at(&List, 4);
    list_print(List);
    printf("size of List = %16d\n", list_size(List));
    printf("first element of List = %16.7lf\n", list_value_at(List, 0));
    printf("last element of List = %16.7lf\n", list_value_at(List, list_size(List)-1));


    list_append_at(&List, 0, -5.0);
    list_append_at(&List, list_size(List)-1, 5.0);
    list_print(List);
    printf("size of List = %16d\n", list_size(List));
    printf("first element of List = %16.7lf\n", list_value_at(List, 0));
    printf("last element of List = %16.7lf\n", list_value_at(List, list_size(List)-1));


    list_delete_at(&List, 0);
    list_delete_at(&List, list_size(List)-1);
    list_print(List);
    printf("size of List = %16d\n", list_size(List));
    printf("first element of List = %16.7lf\n", list_value_at(List, 0));
    printf("last element of List = %16.7lf\n", list_value_at(List, list_size(List)-1));


    printf("----------------------------------------\n");
    printf("deleted List\n");
    printf("----------------------------------------\n");
    list_delete(&List);
    list_print(List);
    printf("size of List = %16d\n", list_size(List));


    printf("----------------------------------------\n");
    printf("endprogram\n");
    printf("----------------------------------------\n");
    return 0;
}
#include <string.h>
#include <stdio.h>
#include "list.h"

void create_node(Node **node, char name_file_txt[], char name_file_bmp[]);
//TODO test: il fix dovrebbe andare, però non ne sono certo
void insert(Node **first_element, char name_file_txt[], char name_file_bmp[]) {
    Node *tmp = *first_element;
    if (tmp != NULL) {
        while (tmp->next != NULL)
            tmp = tmp->next;
    }
    create_node(&tmp, name_file_txt, name_file_bmp);
    if(*first_element == NULL)
        *first_element = tmp;
}

void create_node(Node **node, char name_file_txt[], char name_file_bmp[]){
    *node = (Node *) malloc(sizeof(Node));
    strcpy((*node)->name_file_txt, name_file_txt);
    strcpy((*node)->name_file_bmp, name_file_bmp);
}

char *getNameFileTxt(Node *first_element) {
    if (first_element != NULL)
        return first_element->name_file_txt;

    return NULL;
}

char *getNameFileBmp(Node *first_element) {
    if (first_element != NULL)
        return first_element->name_file_bmp;
    return NULL;
}

Node *removeElement(Node *first_element) {
    if (first_element != NULL) {
        first_element = first_element->next;
        return first_element;
    }
    return NULL;
}

Node *getNext(Node *element) {
    return element->next;
}

Node *getLastElement(Node *first_element) {
    Node *tmp = first_element;
    while (tmp->next != NULL)
        tmp = tmp->next;

    return tmp;
}

void printList(Node *element) {
    if (element == NULL)
        return;
    if(strcmp(getNameFileTxt(element), "") != 0)
        printf("\nTXT:\t%s", getNameFileTxt(element));

    printf("\nBMP:\t%s", getNameFileBmp(element));
    printf("\n--------------------------------");
    if (getNext(element) != NULL)
        printList(getNext(element));
}

//ESEMPIO USO LISTA
//    Node* list = NULL;
//    list = insert(list, "1", "2");
//    list = insert(list, "3", "4");
//    list = insert(list, "5", "6");
//    list = insert(list, "7", "8");
//
//    while(list != NULL)
//    {
//        printf("\nStampo: %s", getNameFileTxt(list));
//        printf("\nStampo: %s", getNameFileBmp(list));
//        printf("\n-----------------------------------------------------------------");
//        list = removeElement(list);
//    }




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct node{
    char data[MAX];
    struct node *next;
};
typedef struct node Node;
typedef struct node* NodePointer;
void insertIntoLinkedList(char [], NodePointer *);
void displayLinkedList(NodePointer);
void deleteFromLinkedList(char [], NodePointer *);
int nodeExists(NodePointer current, char* myData);
int countNodes(NodePointer current);
void deleteLinkedList(NodePointer *head3);
void P1_2020_1();
void solveP1(char* s);
int bruteSearch(char *txt, char *pat);
void substring(char [], char[], int, int);


int main() {
    P1_2020_1();
    return 0;
}

void P1_2020_1(){
    char s[201];
    int N, i;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%s", s);
        solveP1(s);
    }
}

void solveP1(char* s){
    //Esta função é dedicada à sua implementação
    printf("%d\n", 5);
}


int bruteSearch(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i;
    for (i=0; i<=N; i++){
        int j;
        for (j=0; j<M; j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if (j==M){
            return i;
        }
    }
    return -1;
}

// C substring function definition
void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    int pos=c+l;
    while (c < pos) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}


void insertIntoLinkedList(char word2[], NodePointer *head2){
    NodePointer newNode = NULL;
    NodePointer previous = NULL;
    NodePointer current = *head2;

    newNode = malloc(sizeof(Node));
    if(NULL != newNode){
        strcpy(newNode->data, word2);
        while(NULL != current && strcmp(word2, current->data)>0){
            previous = current;
            current = current->next;
        }
        if(NULL == previous){
            newNode->next = current;
            *head2 = newNode;
        }
        else{
            previous->next = newNode;
            newNode->next = current;
        }
    }
}


void displayLinkedList(NodePointer current){
    if(NULL == current){
        return;
    }
    while(NULL != current){
        printf("%s, ", current->data);
        current = current->next;
    }
    printf("\n");
}


void deleteFromLinkedList(char word3[], NodePointer *head3){
    NodePointer tempNode = NULL;
    NodePointer previous = NULL;
    NodePointer current = *head3;

    if(NULL == current){
        printf("Cannot delete from empty list!\n");
        return;
    }

    if(0 == strcmp(word3, current->data)){
        tempNode = current;
        *head3 = current->next;
        printf("deleting \"%s\" . . .\n", tempNode->data);
        free(tempNode);
    }
    else{
        while(NULL != current && 0 != strcmp(word3, current->data)){
            previous = current;
            current = current->next;
        }
        if(NULL != current){
            tempNode = current;
            previous->next = current->next;
            printf("deleting \"%s\" . . .\n", tempNode->data);
            free(tempNode);
        }
    }
    free(head3);
}


int nodeExists(NodePointer current, char* myData){
    if(NULL == current){
        return 0;
    }
    while(NULL != current){
        if (0==strcmp(current->data, myData)){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int countNodes(NodePointer current){
    int count=0;
    if(NULL == current){
        return 0;
    }
    while(NULL != current){
        count++;
        current = current->next;
    }
    return count;
}

void deleteLinkedList(NodePointer *head3){
    NodePointer tempNode = NULL;
    NodePointer current = *head3;

    if(NULL == current){
        return;
    }
    while(NULL != current){
        tempNode = current;
        current = current->next;
        free(tempNode);
    }
}

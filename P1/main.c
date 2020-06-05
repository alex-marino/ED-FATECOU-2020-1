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
int bruteSearchAlt(char *txt, char *pat);
int** computeDfa(char *pat);
int kmpSearch(char *txt, char *pat, int **dfa);
void substring(char [], char[], int, int);


int main() {
    P1_2020_1();
    return 0;
}

void P1_2020_1(){
		// Fun��o preparada para receber os dados dos casos de teste 
    char s[201];
    while(scanf("%s", s) == 1){
        if (s[0]!=42){ //compara��o com asterisco
            solveP1(s);
        } else{
            break;
        }
    }
}

void solveP1(char* s){
    NodePointer head = NULL;
    /*
     * Esta fun��o deve conter sua implementa��o 
     * esta fun��o (atualmente) apenas imprime o resultado
     */
    printf("%d\n", countNodes(head));
    deleteLinkedList(&head);

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

int bruteSearchAlt(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    for(i=0, j=0; i<N && j<M; i++){
        if (txt[i]==pat[j]){
            j++;
        } else {
            i-=j;
            j=0;
        }
    }
    if (j==M){
        return i-M;
    } else {
        return N;
    }
    return 0;
}




int** computeDfa(char *pat) {
    int M = strlen(pat), i;
    int R = 256;
    int** dfa = (int**) malloc(255*sizeof(int*));
    for(i=0; i<R; i++)
        dfa[i] = (int*) malloc(M*sizeof(int));
    int X, j, c;
    dfa[*pat][0] = 1;
    for (X = 0, j = 1; j < M; j++){
        // calculate dfa[][j]
        for(c = 0; c < R; c++){
            dfa[c][j] = dfa[c][X];
        }
        dfa[pat[j]][j] = j+1;
        X = dfa[pat[j]][X];
    }
    return dfa;
}




int kmpSearch(char *txt, char *pat, int **dfa) {
    int j, M = strlen(pat);
    int i, N = strlen(txt);

    for (i = 0, j = 0; i < N && j < M; i++){
        j = dfa[txt[i]][j];
    }
    if (j == M){
        return i - M;
    }
    else{
        return -1;
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
    NodePointer previous = NULL;
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

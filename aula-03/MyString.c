#include <stdio.h>
#include "MyString.h"

int main() {
    char txt[1500];
    char pat[15];
    scanf(" %[^\n]", txt);
    scanf(" %[^\n]", pat);

    int i;
    int** dfa = calculateDfa(pat);

    printf("Texto             :   %s\n", txt);
    int offset = kmpSearch(txt, pat, dfa);
//    int offset = bruteSearch(txt, pat);
    printf("Padrao            :   ");
    for (i = 0; i < offset; i++)
        printf(" ");
    printf("%s\n",pat);
    printf("Posicao do padrao = %d\n", offset+1);
}

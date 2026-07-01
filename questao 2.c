#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
    char dados[MAX];
    int inicio,fim;
}Fila;

typedef struct{
    char dados[MAX];
    int topo;
}Pilha;

void initFila(Fila *f){
    f->inicio=0;
    f->fim=-1;
}

void enfileirar(Fila *f,char c){
    f->dados[++f->fim]=c;
}

char desenfileirar(Fila *f){
    return f->dados[f->inicio++];
}

int filaVazia(Fila *f){
    return f->inicio>f->fim;
}

void initPilha(Pilha *p){
    p->topo=-1;
}

void push(Pilha *p,char c){
    p->dados[++p->topo]=c;
}

char pop(Pilha *p){
    return p->dados[p->topo--];
}

int pilhaVazia(Pilha *p){
    return p->topo==-1;
}

int main(){

    char texto[MAX];

    Fila f;
    Pilha p;

    initFila(&f);
    initPilha(&p);

    printf("Digite uma sequencia: ");
    fgets(texto,MAX,stdin);

    for(int i=0;texto[i]!='\0';i++)
        enfileirar(&f,texto[i]);

    while(!filaVazia(&f)){

        char c=desenfileirar(&f);

        if(isalpha(c))
            push(&p,tolower(c));
        else
            push(&p,c);
    }

    printf("\nResultado:\n");

    while(!pilhaVazia(&p))
        printf("%c",pop(&p));

    return 0;
}

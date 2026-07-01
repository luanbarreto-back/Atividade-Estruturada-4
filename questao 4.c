#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct{

    char dados[MAX];
    int inicio,fim;

}FilaChar;

typedef struct{

    int dados[MAX];
    int inicio,fim,cont;

}FilaInt;

void initChar(FilaChar *f){

    f->inicio=0;
    f->fim=-1;

}

void initInt(FilaInt *f){

    f->inicio=0;
    f->fim=0;
    f->cont=0;

}

void enfileiraChar(FilaChar *f,char c){

    f->dados[++f->fim]=c;

}

void enfileiraInt(FilaInt *f,int valor){

    f->dados[f->fim]=valor;
    f->fim=(f->fim+1)%MAX;
    f->cont++;

}

char desenChar(FilaChar *f){

    return f->dados[f->inicio++];

}

int desenInt(FilaInt *f){

    int valor=f->dados[f->inicio];

    f->inicio=(f->inicio+1)%MAX;

    f->cont--;

    return valor;

}

int main(){

    char texto[MAX];

    FilaChar A;

    FilaInt B;

    initChar(&A);

    initInt(&B);

    printf("Digite uma sequencia: ");

    fgets(texto,MAX,stdin);

    for(int i=0;texto[i]!='\0';i++){

        if(isdigit(texto[i]))
            enfileiraInt(&B,texto[i]-'0');

        else if(isalpha(texto[i]))
            enfileiraChar(&A,texto[i]);

    }

    printf("\nFila B:\n");

    while(B.cont>0)
        printf("%d ",desenInt(&B));

    printf("\n\nFila A:\n");

    while(A.inicio<=A.fim)
        printf("%c ",desenChar(&A));

    return 0;

}

#include <stdio.h>

#define MAX 100

typedef struct{

    int dados[MAX];
    int inicio,fim,quantidade;

}Fila;

void inicializar(Fila *f){

    f->inicio=0;
    f->fim=0;
    f->quantidade=0;

}

int cheia(Fila *f){

    return f->quantidade==MAX;

}

int vazia(Fila *f){

    return f->quantidade==0;

}

void enfileirar(Fila *f,int valor){

    if(!cheia(f)){

        f->dados[f->fim]=valor;
        f->fim=(f->fim+1)%MAX;
        f->quantidade++;

    }

}

int desenfileirar(Fila *f){

    int valor=f->dados[f->inicio];

    f->inicio=(f->inicio+1)%MAX;

    f->quantidade--;

    return valor;

}

int main(){

    Fila fila;

    inicializar(&fila);

    int op,valor;

    do{

        printf("\n1-Enfileirar\n");
        printf("2-Desenfileirar mostrando dobro\n");
        printf("3-Desenfileirar tudo\n");
        printf("4-Sair\n");

        scanf("%d",&op);

        switch(op){

        case 1:

            scanf("%d",&valor);

            if(valor!=0)
                enfileirar(&fila,valor);

            break;

        case 2:

            if(!vazia(&fila))
                printf("%d\n",desenfileirar(&fila)*2);

            break;

        case 3:

            while(!vazia(&fila))
                printf("%d ",desenfileirar(&fila));

            printf("\n");

        }

    }while(op!=4);

    return 0;

}

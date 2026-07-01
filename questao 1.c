#include <stdio.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

void inicializar(Fila *f){
    f->inicio = 0;
    f->fim = -1;
}

int vazia(Fila *f){
    return f->fim < f->inicio;
}

int cheia(Fila *f){
    return f->fim == MAX - 1;
}

void enfileirar(Fila *f, int valor){
    if(!cheia(f))
        f->dados[++f->fim] = valor;
}

int desenfileirar(Fila *f){
    return f->dados[f->inicio++];
}

int main(){

    Fila fila;
    inicializar(&fila);

    int op, valor;

    do{
        printf("\n1 - Enfileirar numero positivo\n");
        printf("2 - Desenfileirar e imprimir multiplos de 2\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&op);

        switch(op){

        case 1:
            printf("Numero: ");
            scanf("%d",&valor);

            if(valor>0)
                enfileirar(&fila,valor);
            else
                printf("Digite apenas numeros positivos!\n");
            break;

        case 2:
            while(!vazia(&fila)){
                valor=desenfileirar(&fila);

                if(valor%2==0)
                    printf("%d ",valor);
            }
            printf("\n");
            break;
        }

    }while(op!=3);

    return 0;
}

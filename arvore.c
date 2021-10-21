#include <stdio.h>
#include <stdlib.h>

struct item
{
    int cod;
};

typedef struct item Item;

struct NO{
    Item info;
    struct NO *esquerda;
    struct NO *direita;
};

typedef struct NO ArvoreBinaria;

ArvoreBinaria *create(){
    return NULL;
}

Item criacaodoitem(int cod){
    Item info;
    info.cod = cod;
    return info;
}

ArvoreBinaria *inserir(ArvoreBinaria *raiz, Item x){
    if(raiz == NULL){
        ArvoreBinaria *novo = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
        novo->info = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }else{
        if(x.cod > raiz->info.cod){
            raiz -> direita = inserir(raiz->direita,x);
        }else if(x.cod < raiz->info.cod){
            raiz -> esquerda = inserir(raiz->esquerda,x);
        }
    }
    return raiz;
}

void imprimir(ArvoreBinaria *raiz){
    if(raiz != NULL){
        printf("\n%d", raiz->info.cod);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

void liberar(ArvoreBinaria *raiz){
    if(raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main(int argc, char const *argv[])
{
    ArvoreBinaria *raiz = create();
    raiz = inserir(raiz, criacaodoitem(24));
    raiz = inserir(raiz, criacaodoitem(10));
    raiz = inserir(raiz, criacaodoitem(32));
    raiz = inserir(raiz, criacaodoitem(5));
    raiz = inserir(raiz, criacaodoitem(29));
    raiz = inserir(raiz, criacaodoitem(12));
    raiz = inserir(raiz, criacaodoitem(35));
    imprimir(raiz);
    
    printf("\n");
    liberar(raiz);
    printf("Lista Liberada");
    return 0;
}

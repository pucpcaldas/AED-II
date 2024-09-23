#include <stdio.h>

typedef struct no {
    float dado;
    struct no *prox;
} No;

No *aloca(float dado);
void print(No *n, int i);

int main() {
    No *n1, *n2, *n3, *n4, *n5;
    n1 = aloca(5.2);
    n2 = aloca(7.8);
    n3 = aloca(9.4);
    n4 = aloca(2.6);
    n5 = aloca(8.1);
    //
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = n4;
    n4->prox = n5;
    //
    print(n1, 1);
    print(n2, 2);
    print(n3, 3);
    print(n4, 4);
    print(n5, 5);
}

No *aloca(float dado) {
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL) exit(1);
    aux->dado = dado;
    aux->prox = NULL;
    return aux;
}

void print(No *n, int i) {
    printf("dado de n%d:  %.2
    f\n", i, n->dado);
    printf("endereco:    %d\n", n);
    printf("aponta para: %d\n\n", n->prox);
}





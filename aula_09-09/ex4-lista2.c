#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[50];
    int ano;
} Carro;

void imprimeVetor(Carro *v);
void preencheVetor(Carro *c, char *nome, int ano);

void trocar(Carro *v, int i, int j);

int particiona(Carro *v, int esq, int dir);
void quicksort(Carro *v, int esq, int dir);

int vez = 0, tam;

int main() {
    tam = 10;
    Carro *v = (Carro *)malloc(tam * sizeof(Carro));
    if(v == NULL) exit(0);

    preencheVetor(&v[0], "Gol", 1990);
    preencheVetor(&v[1], "Onix", 2010);
    preencheVetor(&v[2], "Corsa", 1997);
    preencheVetor(&v[3], "Chevette", 1977);
    preencheVetor(&v[4], "Cruze", 2017);
    preencheVetor(&v[5], "Civic", 2024);
    preencheVetor(&v[6], "Fusion", 2015);
    preencheVetor(&v[7], "Renegadde", 2014);
    preencheVetor(&v[8], "Palio", 2009);
    preencheVetor(&v[9], "Lancer", 2012);
    printf("Vetor a ordenar:\n");
    imprimeVetor(v);

    printf("\n\nExecutando Quicksort\n\n");
    quicksort(v, 0, tam - 1);
    printf("\n\nResutado final:\n");
    imprimeVetor(v);

    free(v);
    return 0;
}

void imprimeVetor(Carro *v) {

    for (int i = 0; i < tam; i++)
    {
        printf("Nome: %s, ano: %d\n", v[i].nome, v[i].ano);
    }
    printf("\n");
}

void preencheVetor(Carro *c, char *nome, int ano) {
    strcpy(c->nome, nome);
    c->ano = ano;
}

void trocar(Carro *v, int i, int j) {
    Carro aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particiona(Carro *v, int esq, int dir) {
    int i, j;
    Carro x;
    i = esq;
    j = dir;
    x = v[esq];

    while (i < j)
    {
        while (strcmp(v[i].nome, x.nome) <= 0 && (i < dir)) i++;
        while (strcmp(v[j].nome, x.nome) > 0 && (j > esq)) j--;
        if (i < j) trocar(v, i, j);
    }

    trocar(v, esq, j);

    return j;
}


void quicksort(Carro *v, int esq, int dir) {
    int pivo;

    if (esq >= dir)
        return;

    pivo = particiona(v, esq, dir);
    quicksort(v, esq, pivo - 1);
    quicksort(v, pivo + 1, dir);
}

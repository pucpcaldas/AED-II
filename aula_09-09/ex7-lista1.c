#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int tam);
void preencheVetor(int *v, int tam);
float calculaMedia(int *v, int tam);

int main() {
    int tam, *v;
    printf("digite eo tamanho do seu vetor: ");
    scanf("%d", &tam);
    v = alocaVetor(tam);
    preencheVetor(v, tam);
    printf("\na media e de %.2f", calculaMedia(v, tam));
    free(v);
}

int *alocaVetor(int tam) {
    int *v = (int*)malloc(sizeof(int)*tam);
    if(v == NULL) exit(0);
    return v;
}

void preencheVetor(int *v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("\ndigite o valor da posicao %d: ", i);
        scanf("%d", &v[i]);
    }
}

float calculaMedia(int *v, int tam) {
    int soma = 0;
    for(int i = 0; i <tam; i++) soma += v[i];
    return soma/tam;
}

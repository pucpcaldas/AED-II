#include "stdio.h", "stdlib.h", "math.h"

typedef struct {
    float coordX;
    float coordY;
} Ponto;

Ponto *alocaVetor(int tam);
void resgistraPonto(Ponto *p);
float calculaLado(Ponto a, Ponto b);
int verificaTipoTriangulo(Ponto *p);

int main() {
    Ponto *v;
    int resultado;
    v = alocaVetor(3);
    for(int i = 0; i < 3; i++) {
        resgistraPonto(&v[i]);
        printf("Valor do ponto %d: X: %.2f\tY: %.2f\n", i, v[i].coordX, v[i].coordY);
    }
    resultado = verificaTipoTriangulo(v);
    switch(resultado){
        case 1: printf("Isoceles");
                break;
        case 2: printf("Equilatero");
                break;
        case 3: printf("Escaleno");
                break;
    }
    free(v);
    return 1;
}

Ponto *alocaVetor(int tam) {
    Ponto *v;
    v = (Ponto *) malloc(sizeof(Ponto) * tam);
    if(v == NULL) {
        printf("falha na alocação");
        exit(0);
    }
    return v;
}

void resgistraPonto(Ponto *p) {
    printf("Digite as coordenadas do X e do Y o ponto:");
    scanf("%f %f", &p->coordX, &p->coordY);
}

float calculaLado(Ponto a, Ponto b) {
    return sqrt(pow(a.coordX - b.coordX, 2) + pow(a.coordY - b.coordY, 2));
}

int verificaTipoTriangulo(Ponto *p) {
    float d1 = calculaLado(p[0], p[1]);
    float d2 = calculaLado(p[0], p[2]);
    float d3 = calculaLado(p[1], p[2]);
    if(d1 == d2 && d1 == d3) return 2;
    else if(d1 == d2 || d1 == d3 || d2 == d3) return 1;
    else return 3;
}

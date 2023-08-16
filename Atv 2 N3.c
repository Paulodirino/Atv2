#include <stdio.h>

#define MAX_SIZE 20

struct Conjunto {
    int elementos[MAX_SIZE];
    int tamanho;
};

void criarConjuntoVazio(struct Conjunto *conjunto) {
    conjunto->tamanho = 0;
}

void lerConjunto(struct Conjunto *conjunto) {
    printf("Digite o tamanho do conjunto (até %d): ", MAX_SIZE);
    scanf("%d", &conjunto->tamanho);

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < conjunto->tamanho; i++) {
        scanf("%d", &conjunto->elementos[i]);
    }
}

void uniaoConjuntos(struct Conjunto *conjuntoA, struct Conjunto *conjuntoB, struct Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        resultado->elementos[resultado->tamanho++] = conjuntoA->elementos[i];
    }

    for (int i = 0; i < conjuntoB->tamanho; i++) {
        int elemento = conjuntoB->elementos[i];
        int encontrado = 0;
        for (int j = 0; j < resultado->tamanho; j++) {
            if (resultado->elementos[j] == elemento) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            resultado->elementos[resultado->tamanho++] = elemento;
        }
    }
}

void intersecaoConjuntos(struct Conjunto *conjuntoA, struct Conjunto *conjuntoB, struct Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        int elemento = conjuntoA->elementos[i];
        for (int j = 0; j < conjuntoB->tamanho; j++) {
            if (conjuntoB->elementos[j] == elemento) {
                resultado->elementos[resultado->tamanho++] = elemento;
                break;
            }
        }
    }
}

int saoIguais(struct Conjunto *conjuntoA, struct Conjunto *conjuntoB) {
    if (conjuntoA->tamanho != conjuntoB->tamanho) {
        return 0;
    }

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        int elementoA = conjuntoA->elementos[i];
        int encontrado = 0;
        for (int j = 0; j < conjuntoB->tamanho; j++) {
            if (conjuntoB->elementos[j] == elementoA) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return 0;
        }
    }

    return 1;
}

void imprimirConjunto(struct Conjunto *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d", conjunto->elementos[i]);
        if (i < conjunto->tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    struct Conjunto conjuntoA, conjuntoB, conjuntoResultado;
    criarConjuntoVazio(&conjuntoA);
    criarConjuntoVazio(&conjuntoB);
    criarConjuntoVazio(&conjuntoResultado);

    printf("Conjunto A:\n");
    lerConjunto(&conjuntoA);

    printf("Conjunto B:\n");
    lerConjunto(&conjuntoB);

    printf("\nConjunto A: ");
    imprimirConjunto(&conjuntoA);

    printf("Conjunto B: ");
    imprimirConjunto(&conjuntoB);

    printf("\nUniao de A e B: ");
    uniaoConjuntos(&conjuntoA, &conjuntoB, &conjuntoResultado);
    imprimirConjunto(&conjuntoResultado);

    printf("Intersecao de A e B: ");
    intersecaoConjuntos(&conjuntoA, &conjuntoB, &conjuntoResultado);
    imprimirConjunto(&conjuntoResultado);

    if (saoIguais(&conjuntoA, &conjuntoB)) {
        printf("Conjunto A e B sao iguais.\n");
    } else {
        printf("Conjunto A e B nao sao iguais.\n");
    }

    return 0;
}

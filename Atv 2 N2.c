#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[100];
    char cargo[50];
    float salarioBase;
    float beneficios;
    float descontos;
    float salarioLiquido;
};

struct Loja {
    struct Funcionario funcionarios[10];
    int numFuncionarios;
};

void calcularSalarioLiquido(struct Funcionario *funcionario) {
    funcionario->salarioLiquido = funcionario->salarioBase + funcionario->beneficios - funcionario->descontos;
}

void exibirDadosFuncionario(struct Funcionario funcionario) {
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario Base: %.2f\n", funcionario.salarioBase);
    printf("Beneficios: %.2f\n", funcionario.beneficios);
    printf("Descontos: %.2f\n", funcionario.descontos);
    printf("Salario Liquido: %.2f\n", funcionario.salarioLiquido);
    printf("\n");
}

void exibirMediaSalarial(struct Loja loja) {
    float somaSalarios = 0;
    for (int i = 0; i < loja.numFuncionarios; i++) {
        somaSalarios += loja.funcionarios[i].salarioLiquido;
    }
    float mediaSalarial = somaSalarios / loja.numFuncionarios;
    printf("Media Salarial da Loja: %.2f\n", mediaSalarial);
}

void exibirMaiorSalario(struct Loja loja) {
    float maiorSalario = 0;
    int indiceMaiorSalario = -1;

    for (int i = 0; i < loja.numFuncionarios; i++) {
        if (loja.funcionarios[i].salarioLiquido > maiorSalario) {
            maiorSalario = loja.funcionarios[i].salarioLiquido;
            indiceMaiorSalario = i;
        }
    }

    if (indiceMaiorSalario != -1) {
        printf("Funcionario com o Maior Salario:\n");
        exibirDadosFuncionario(loja.funcionarios[indiceMaiorSalario]);
    }
}

int main() {
    struct Loja loja;
    loja.numFuncionarios = 0;

    printf("Cadastro de Funcionarios:\n");

    for (int i = 0; i < 10; i++) {
        printf("Funcionario %d:\n", i + 1);
        struct Funcionario novoFuncionario;

        printf("Nome: ");
        scanf("%s", novoFuncionario.nome);

        printf("Cargo: ");
        scanf("%s", novoFuncionario.cargo);

        printf("Salario Base: ");
        scanf("%f", &novoFuncionario.salarioBase);

        printf("Beneficios: ");
        scanf("%f", &novoFuncionario.beneficios);

        printf("Descontos: ");
        scanf("%f", &novoFuncionario.descontos);

        calcularSalarioLiquido(&novoFuncionario);

        loja.funcionarios[loja.numFuncionarios] = novoFuncionario;
        loja.numFuncionarios++;

        char continuar;
        printf("Deseja cadastrar outro funcionario? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'N' || continuar == 'n') {
            break;
        }
    }

    printf("\nDados dos Funcionarios:\n");
    for (int i = 0; i < loja.numFuncionarios; i++) {
        exibirDadosFuncionario(loja.funcionarios[i]);
    }

    exibirMediaSalarial(loja);
    exibirMaiorSalario(loja);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Cliente {
    char nome[100];
    struct Data dataNascimento;
    int idade;
    char sexo;
};

const int MAX_CLIENTES = 50;
struct Cliente *clientes; // Usando um ponteiro para alocar dinamicamente memória
int numeroClientes = 0;

int calcularIdade(struct Data dataNascimento, struct Data dataAtual) {
    int idade = dataAtual.ano - dataNascimento.ano;
    if (dataAtual.mes < dataNascimento.mes || (dataAtual.mes == dataNascimento.mes && dataAtual.dia < dataNascimento.dia)) {
        idade--;
    }
    return idade;
}

void cadastrarCliente() {
    if (numeroClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    struct Cliente novoCliente;
    printf("Nome: ");
    scanf("%s", novoCliente.nome);
    printf("Data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &novoCliente.dataNascimento.dia, &novoCliente.dataNascimento.mes, &novoCliente.dataNascimento.ano);
    printf("Sexo (M/F): ");
    scanf(" %c", &novoCliente.sexo);

    time_t agora = time(NULL);
    struct tm *dataAtual = localtime(&agora);
    novoCliente.idade = calcularIdade(novoCliente.dataNascimento, (struct Data){dataAtual->tm_mday, dataAtual->tm_mon + 1, dataAtual->tm_year + 1900});

    clientes[numeroClientes++] = novoCliente;
    printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes() {
    if (numeroClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Clientes cadastrados:\n");
    for (int i = 0; i < numeroClientes; ++i) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("Data de Nascimento: %d/%d/%d\n", clientes[i].dataNascimento.dia, clientes[i].dataNascimento.mes, clientes[i].dataNascimento.ano);
        printf("Idade: %d anos\n", clientes[i].idade);
        printf("Sexo: %c\n", clientes[i].sexo);
        printf("\n");
    }
}

int main() {
    clientes = malloc(MAX_CLIENTES * sizeof(struct Cliente)); // Aloca memória para o array de clientes

    if (clientes == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    free(clientes); // Libera a memória alocada para o array de clientes
    return 0;
}

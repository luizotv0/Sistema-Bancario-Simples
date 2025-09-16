#include <stdio.h>
#include <string.h>

// Define o numero maximo de transacoes que podem ser armazenadas no extrato
#define MAX_TRANSACOES 50

// Senha correta para autenticacao
#define SENHA_CORRETA "1234"

// Estrutura para guardar cada transacao
typedef struct {
    char descricao[50];
    float valor;
} Transacao;

int main() {
    float saldo = 0;                 // Saldo inicial do usuario
    int opcao;                       // Opcao escolhida no menu
    char senha[10];                  // Armazena a senha digitada pelo usuario
    int tentativas = 0, maxTentativas = 3; // Controle de tentativas de login

    // Array que armazena as transacoes feitas na sessao
    Transacao extrato[MAX_TRANSACOES];
    int totalTransacoes = 0; // Quantidade de transacoes registradas

    printf("=== SISTEMA BANCARIO SIMPLES ===\n");

    /* ========================
       ETAPA 1: AUTENTICACAO
       ======================== */
    while (tentativas < maxTentativas) {
        printf("Digite sua senha: ");
        scanf("%s", senha);

        // Verifica se a senha digitada esta correta
        if (strcmp(senha, SENHA_CORRETA) == 0) {
            printf("\nAcesso permitido! Bem-vindo ao sistema bancario.\n");
            break; // Sai do laco se a senha estiver correta
        } else {
            tentativas++;
            printf("Senha incorreta! Tentativas restantes: %d\n",
                   maxTentativas - tentativas);
        }

        // Caso o usuario erre a senha 3 vezes, o programa e encerrado
        if (tentativas == maxTentativas) {
            printf("\nConta bloqueada. Tente novamente mais tarde.\n");
            return 0;
        }
    }

    /* ========================
       ETAPA 2: MENU PRINCIPAL
       ======================== */
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Deposito\n");
        printf("2 - Saque\n");
        printf("3 - Saldo\n");
        printf("4 - Extrato\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { // OPCAO DEPOSITO
                float valor;
                printf("Digite o valor para deposito: R$ ");
                scanf("%f", &valor);

                if (valor > 0) {
                    saldo += valor; // Atualiza o saldo

                    // Registra a transacao no extrato, se ainda houver espaco
                    if (totalTransacoes < MAX_TRANSACOES) {
                        strcpy(extrato[totalTransacoes].descricao, "Deposito");
                        extrato[totalTransacoes].valor = valor;
                        totalTransacoes++;
                    }

                    printf("Deposito realizado com sucesso!\n");
                } else {
                    printf("Valor invalido! Tente novamente.\n");
                }
                break;
            }

            case 2: { // OPCAO SAQUE
                float valor;
                printf("Digite o valor para saque: R$ ");
                scanf("%f", &valor);

                if (valor > 0 && valor <= saldo) {
                    saldo -= valor; // Atualiza o saldo

                    // Registra a transacao como negativa no extrato
                    if (totalTransacoes < MAX_TRANSACOES) {
                        strcpy(extrato[totalTransacoes].descricao, "Saque");
                        extrato[totalTransacoes].valor = -valor; // valor negativo
                        totalTransacoes++;
                    }

                    printf("Saque realizado com sucesso!\n");
                } else if (valor > saldo) {
                    printf("Saldo insuficiente para este saque!\n");
                } else {
                    printf("Valor invalido! Tente novamente.\n");
                }
                break;
            }

            case 3: // OPCAO SALDO
                printf("Saldo atual: R$ %.2f\n", saldo);
                break;

            case 4: // OPCAO EXTRATO
                printf("\n=== EXTRATO DA SESSAO ===\n");

                if (totalTransacoes == 0) {
                    printf("Nenhuma transacao realizada.\n");
                } else {
                    // Mostra todas as transacoes registradas
                    for (int i = 0; i < totalTransacoes; i++) {
                        printf("%d - %s: R$ %.2f\n",
                               i + 1,
                               extrato[i].descricao,
                               extrato[i].valor);
                    }
                }

                printf("Saldo final: R$ %.2f\n", saldo);
                break;

            case 5: // OPCAO SAIR
                printf("Saindo do sistema... Obrigado por usar nosso banco!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5); // Repete ate o usuario escolher sair

    return 0; // Fim do programa
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void limparTela() {
        system("clear"); 
}

typedef struct {
    int id;
    char nome[50];
    char cpf[15];
    char senha[20];
} Cliente;

Cliente listaClientes[100];
int totalClientes = 0;

void exibirMenuPrincipal();
void cadastrarCliente();
int loginUsuario();
void menuCliente(int idClienteLogado);

int main() {
    printf("Carregando Sistema Connect Barber - MVP Fase 1...\n");
    exibirMenuPrincipal();
    return 0;
}

void exibirMenuPrincipal() {
    int opcao;
    int leituraCorreta; 
    
    do {
        printf("\n=== BARBEARIA TRATO FINO ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Login do Cliente\n");
        printf("0. Sair do Sistema\n");
        printf("Escolha uma opcao: ");
        
        leituraCorreta = scanf("%d", &opcao);

        if (leituraCorreta == 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            opcao = -1; 
        }

        if (opcao == 1) {
            cadastrarCliente();
        } else if (opcao == 2) {
            int id = loginUsuario();
            if (id != -1) {
                menuCliente(id); 
            }
        } else if (opcao != 0) {
            printf("\n-> Opcao invalida. Digite apenas os numeros do menu.\n");
        }
    } while (opcao != 0);
    
    printf("Sistema encerrado com sucesso.\n");
}

void cadastrarCliente() {
    printf("\n--- CADASTRO DE CLIENTE ---\n");
    Cliente novo;
    novo.id = totalClientes + 1;
    
    printf("Nome completo: ");
    scanf(" %[^\n]", novo.nome); 
    
    int cpfValido; 
    do {
        cpfValido = 1; 
        
        printf("CPF (Exatamente 11 numeros): ");
        scanf("%s", novo.cpf);
        
        int tamanhoCpf = strlen(novo.cpf);
        
        if (tamanhoCpf != 11) {
            printf("-> Erro: O CPF deve conter exatamente 11 digitos!\n");
            cpfValido = 0; 
        } else {
            for (int i = 0; i < 11; i++) {
                if (novo.cpf[i] < '0' || novo.cpf[i] > '9') {
                    printf("-> Erro: O CPF nao pode conter letras ou simbolos, digite APENAS NUMEROS!\n");
                    cpfValido = 0; 
                    break; 
                }
            }
            
            if (cpfValido == 1) { 
                for (int i = 0; i < totalClientes; i++) {
                    if (strcmp(listaClientes[i].cpf, novo.cpf) == 0) {
                        printf("-> Erro: Este CPF ja esta cadastrado no sistema! Tente outro.\n");
                        cpfValido = 0; 
                        break;
                    }
                }
            }
        }
    } while (cpfValido == 0); 
    
    printf("Senha: ");
    scanf("%s", novo.senha);

    listaClientes[totalClientes] = novo;
    totalClientes++;
    
    printf("-> Cliente '%s' cadastrado com sucesso! ID de acesso: %d\n", novo.nome, novo.id);
}

int loginUsuario() {
    char cpf[15], senha[20];
    printf("\n--- LOGIN DE ACESSO ---\n");
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(listaClientes[i].cpf, cpf) == 0 && strcmp(listaClientes[i].senha, senha) == 0) {
            printf("-> Autenticacao concluida! Bem-vindo(a), %s.\n", listaClientes[i].nome);
            return listaClientes[i].id; 
        }
    }
    
    printf("-> Erro: Credenciais invalidas ou cliente nao encontrado.\n");
    return -1; 
}

void menuCliente(int idClienteLogado) {
    int opcao;
    int leituraCorreta;
    
    do {
        printf("\n--- PAINEL DO CLIENTE ---\n");
        printf("0. Fazer Logout\n");
        printf("Escolha uma opcao: ");
        
        leituraCorreta = scanf("%d", &opcao);

        if (leituraCorreta == 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            opcao = -1; 
        }

        if (opcao != 0) {
            printf("-> Opcao invalida. Digite apenas os numeros do menu.\n");
        }
    } while (opcao != 0);
    
    limparTela(); 
    printf("-> Logout realizado com sucesso.\n");
}

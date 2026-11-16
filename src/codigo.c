#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <termios.h> 
#include <unistd.h>

typedef struct {
    int id;
    char nome[50];
    char cpf[15];
    char senha[20];
} Cliente;

typedef struct {
    int idAgendamento;
    int idCliente;
    char data[11];
    char horario[6];
    int status;
} Agendamento;

Cliente listaClientes[100];
int totalClientes = 0;

Agendamento listaAgendamentos[100];
int totalAgendamentos = 0;

void limparTela();
void lerSenha(char *senha);
void exibirMenuPrincipal();
void cadastrarCliente();
void listarClientes(); 
int loginUsuario();
void menuCliente(int idClienteLogado);
void agendarServico(int idClienteLogado);

int validarCPFReal(char *cpf); 
int validarData(char *data);
int validarHorario(char *horario);
int verificarDisponibilidade(char data[], char horario[]);
int ehBissexto(int a);


int main() {
    limparTela();
    printf("Carregando Sistema Connect Barber...\n");
    exibirMenuPrincipal();
    return 0;
}

void limparTela() {
    system("clear"); 
}

void lerSenha(char *senha) {
    int i = 0;
    char ch;
    
    #ifdef _WIN32
        while (1) {
            ch = _getch();
            if (ch == '\r') { 
                senha[i] = '\0';
                break;
            } else if (ch == '\b' && i > 0) { 
                i--;
                printf("\b \b");
            } else if (ch != '\b' && i < 19) { 
                senha[i++] = ch;
                printf("*");
            }
        }
        printf("\n");
    #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ECHO); 
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        fgets(senha, 20, stdin);
        senha[strcspn(senha, "\n")] = 0;
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
        printf("\n");
    #endif
}

void exibirMenuPrincipal() {
    int opcao;
    char entrada[50]; 
    
    do {
        printf("\n=== BARBEARIA TRATO FINO ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Login do Cliente\n");
        printf("3. Listar Clientes Cadastrados\n"); 
        printf("0. Sair do Sistema\n");
        printf("Escolha uma opcao: ");
        
        fgets(entrada, 50, stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = -1; 
        }

        if (opcao == 1) {
            cadastrarCliente();
        } else if (opcao == 2) {
            int id = loginUsuario();
            if (id != -1) {
                menuCliente(id); 
            }
        } else if (opcao == 3) {
            listarClientes(); 
        } else if (opcao != 0) {
            printf("\n-> Opcao invalida. Digite apenas os numeros do menu.\n");
        }
    } while (opcao != 0);
    
    printf("\nSistema encerrado com sucesso.\n");
}

void menuCliente(int idClienteLogado) {
    int opcao;
    char entrada[50];
    
    do {
        printf("\n--- PAINEL DO CLIENTE ---\n");
        printf("1. Agendar Servico\n");
        printf("0. Fazer Logout\n");
        printf("Escolha uma opcao: ");
        
        fgets(entrada, 50, stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = -1; 
        }

        if (opcao == 1) {
            agendarServico(idClienteLogado);
        } else if (opcao != 0) {
            limparTela();
            printf("-> Opcao invalida. Digite apenas os numeros do menu.\n");
        }
    } while (opcao != 0);
    
    limparTela(); 
    printf("-> Logout realizado com sucesso.\n");
}

void cadastrarCliente() {
    limparTela();
    printf("\n--- CADASTRO DE CLIENTE ---\n");
    Cliente novo;
    novo.id = totalClientes + 1;

    int nomeValido;
    do {
        nomeValido = 1;
        printf("Nome completo: ");
        fgets(novo.nome, 50, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = 0; 
        
        int apenasEspacos = 1;
        for(int i = 0; i < strlen(novo.nome); i++) {
            if(novo.nome[i] != ' ') {
                apenasEspacos = 0;
                break;
            }
        }
        
        if (strlen(novo.nome) == 0 || apenasEspacos == 1) {
            printf("-> Erro: O nome nao pode ficar em branco ou conter apenas espacos!\n");
            nomeValido = 0;
        }
    } while (nomeValido == 0);
    
    int cpfValido; 
    do {
        cpfValido = 1; 
        printf("CPF (Apenas numeros): ");
        fgets(novo.cpf, 15, stdin);
        novo.cpf[strcspn(novo.cpf, "\n")] = 0; 
        
        if (strlen(novo.cpf) != 11) {
            printf("-> Erro: O CPF deve conter exatamente 11 digitos!\n");
            cpfValido = 0; 
        } else {
            for (int i = 0; i < 11; i++) {
                if (novo.cpf[i] < '0' || novo.cpf[i] > '9') {
                    printf("-> Erro: Apenas numeros sao permitidos!\n");
                    cpfValido = 0; 
                    break; 
                }
            }
            
            if (cpfValido == 1 && validarCPFReal(novo.cpf) == 0) {
                printf("-> Erro: CPF invalido!\n");
                cpfValido = 0;
            }

            if (cpfValido == 1) { 
                for (int i = 0; i < totalClientes; i++) {
                    if (strcmp(listaClientes[i].cpf, novo.cpf) == 0) {
                        printf("-> Erro: Este CPF ja esta cadastrado no sistema!\n");
                        cpfValido = 0; 
                        break;
                    }
                }
            }
        }
    } while (cpfValido == 0); 
    
    printf("Senha: ");
    lerSenha(novo.senha);

    listaClientes[totalClientes] = novo;
    totalClientes++;
    
    limparTela();
    printf("-> Cliente '%s' cadastrado com sucesso! ID: %d\n", novo.nome, novo.id);
}

void listarClientes() {
    limparTela();
    printf("\n--- LISTA DE CLIENTES CADASTRADOS ---\n");
    
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado no momento.\n");
    } else {
        for (int i = 0; i < totalClientes; i++) {
            printf("ID: %d | Nome: %-20s | CPF: %s\n", 
                   listaClientes[i].id, 
                   listaClientes[i].nome, 
                   listaClientes[i].cpf);
        }
    }
    printf("-------------------------------------\n");
}

int loginUsuario() {
    char cpf[15], senha[20];
    limparTela();
    printf("\n--- LOGIN DE ACESSO ---\n");
    printf("CPF: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    
    printf("Senha: ");
    lerSenha(senha);

    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(listaClientes[i].cpf, cpf) == 0 && strcmp(listaClientes[i].senha, senha) == 0) {
            limparTela();
            printf("-> Autenticacao concluida! Bem-vindo(a), %s.\n", listaClientes[i].nome);
            return listaClientes[i].id; 
        }
    }
    
    limparTela();
    printf("-> Erro: Credenciais invalidas ou cliente nao encontrado.\n");
    return -1; 
}

void agendarServico(int idClienteLogado) {
    limparTela();
    printf("\n--- NOVO AGENDAMENTO ---\n");
    
    Agendamento novo;
    novo.idAgendamento = totalAgendamentos + 1;
    novo.idCliente = idClienteLogado;
    novo.status = 1; 
    
    int dataValida;
    do {
        printf("Digite a data (DD/MM/AAAA): ");
        fgets(novo.data, 15, stdin);
        novo.data[strcspn(novo.data, "\n")] = 0;
        
        dataValida = validarData(novo.data);
        if (dataValida == 0) printf("-> Erro: Data invalida!\n\n");
    } while (dataValida == 0);
    
    int horarioValido;
    do {
        horarioValido = 1; 
        printf("Digite o horario entre 07:00 e 18:00 (HH:MM): ");
        fgets(novo.horario, 10, stdin);
        novo.horario[strcspn(novo.horario, "\n")] = 0;
        
        if (validarHorario(novo.horario) == 0) {
            printf("-> Erro: Horario invalido!(Apenas intervalos de 30 min).\n\n");
            horarioValido = 0;
        } else {
            if (verificarDisponibilidade(novo.data, novo.horario) == 0) {
                printf("-> Erro: Este horario ja esta reservado! Escolha outro.\n\n");
                horarioValido = 0; 
            }
        }
    } while (horarioValido == 0);
    
    listaAgendamentos[totalAgendamentos] = novo;
    totalAgendamentos++;
    
    limparTela();
    printf("-> Sucesso! Agendamento salvo para o dia %s as %s.\n", novo.data, novo.horario);
}

int validarCPFReal(char *cpf) {
    int i, soma, resto, digito1, digito2;
    int todosIguais = 1;

    for (i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            todosIguais = 0;
            break;
        }
    }
    if (todosIguais == 1) return 0;

    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : (11 - resto);

    if ((cpf[9] - '0') != digito1) return 0;

    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : (11 - resto);

    if ((cpf[10] - '0') != digito2) return 0;

    return 1; 
}

int verificarDisponibilidade(char data[], char horario[]) {
    for (int i = 0; i < totalAgendamentos; i++) {
        if (listaAgendamentos[i].status == 1 && strcmp(listaAgendamentos[i].data, data) == 0 && strcmp(listaAgendamentos[i].horario, horario) == 0) {
            return 0; 
        }
    }
    return 1; 
}

int ehBissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int validarData(char *data) {
    int d, m, a;
    if (sscanf(data, "%d/%d/%d", &d, &m, &a) != 3) return 0;
    if (a < 2026 || m < 1 || m > 12) return 0;
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias = dias[m];
    if (m == 2 && ehBissexto(a)) maxDias = 29;
    return (d >= 1 && d <= maxDias);
}

int validarHorario(char *horario) {
    int h, m;
    if (strlen(horario) != 5 || horario[2] != ':') return 0;
    if (sscanf(horario, "%d:%d", &h, &m) != 2) return 0;
    
    if (m != 0 && m != 30) return 0;
    
    if (h < 7 || h > 18) return 0;
    if (h == 18 && m > 0) return 0; 
    return 1; 
}

/* =========================================
   MÓDULO DE AGENDAMENTO (FASE 2)
   Dependências globais: struct Agendamento, 
   vetor listaAgendamentos, limparTela()
   ========================================= */

int verificarDisponibilidade(char data[], char horario[]) {
    for (int i = 0; i < totalAgendamentos; i++) {
        if (listaAgendamentos[i].status == 1) {
            if (strcmp(listaAgendamentos[i].data, data) == 0 && 
                strcmp(listaAgendamentos[i].horario, horario) == 0) {
                return 0; 
            }
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
    
    if (m == 2 && ehBissexto(a)) {
        maxDias = 29;
    }
    
    return (d >= 1 && d <= maxDias);
}

int validarHorario(char *horario) {
    int h, m;
    
    if (strlen(horario) != 5 || horario[2] != ':') return 0;
    if (sscanf(horario, "%d:%d", &h, &m) != 2) return 0;
    
    if (m < 0 || m > 59) return 0;
    if (h < 7 || h > 18) return 0;
    
    if (h == 18 && m > 0) return 0; 
    
    return 1; 
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
        scanf("%s", novo.data);
        
        dataValida = validarData(novo.data);
        
        if (dataValida == 0) {
            printf("-> Erro: Data invalida! Verifique se o dia/mes existe e se nao esta no passado.\n\n");
        }
    } while (dataValida == 0);
    
    int horarioValido;
    do {
        horarioValido = 1; 
        printf("Digite o horario (HH:MM): ");
        scanf("%s", novo.horario);
        
        if (validarHorario(novo.horario) == 0) {
            printf("-> Erro: Horario invalido! Digite entre 07:00 e 18:00 (minutos de 00 a 59).\n\n");
            horarioValido = 0;
        } else {
            if (verificarDisponibilidade(novo.data, novo.horario) == 0) {
                printf("-> Erro: Este horario ja esta reservado para este dia! Escolha outro.\n\n");
                horarioValido = 0; 
            }
        }
    } while (horarioValido == 0);
  
    listaAgendamentos[totalAgendamentos] = novo;
    totalAgendamentos++;
    
    limparTela();
    printf("-> Sucesso! Agendamento %d salvo para o dia %s as %s.\n", novo.idAgendamento, novo.data, novo.horario);
}

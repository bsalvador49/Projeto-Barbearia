# 💈 Connect Barber - Sistema de Gestão e Agendamento (Barbearia Trato Fino)

Sistema desenvolvido para automatizar e modernizar o atendimento, o controle de agenda e a gestão da **Barbearia Trato Fino** (Ceilândia Norte - Brasília/DF).

---

## 📖 Sobre o Projeto

O **Connect Barber** nasceu como um Projeto Integrador (Engenharia de Software e Programação Estruturada - UNIEURO) para resolver gargalos operacionais causados pela gestão manual em cadernos e planilhas, como conflitos de horários, ausência de histórico de clientes e falhas na comunicação.

O projeto está dividido em duas frentes de maturidade:
1. **MVP Funcional (Atual):** Protótipo via terminal desenvolvido em **Linguagem C**, utilizando armazenamento em memória (vetores e `structs`) para validar as regras centrais de cadastro, login, bloqueio de conflitos e cancelamento.
2. **Arquitetura Alvo (Web):** Aplicação completa com interfaces responsivas (Cliente, Barbeiro, Recepcionista e Gerente), banco de dados relacional e integração automatizada via WhatsApp (ChatGuru).

---

## 🛠️ Tecnologias Utilizadas

### Implementação Atual (MVP)
* **Linguagem C (Padrão C99/C11):** Core da aplicação estruturada, manipulação de `structs`, vetores globais e controle de fluxo.
* **Bibliotecas Padrão C:** `stdio.h`, `stdlib.h`, `string.h` (lógica de autenticação, comparação de strings e persistência em memória).
* **Git & GitHub:** Controle de versão e hospedagem do código-fonte.

### Arquitetura Modelada (Especificação Web)
* **Front-end:** HTML5, CSS3, JavaScript (Interfaces responsivas e compatíveis com diretrizes de acessibilidade WCAG).
* **Modelagem & Design:** UML (Diagramas de Casos de Uso), MER/DER (Modelo Entidade-Relacionamento) e Prototipação de Telas (TL001 a TL020).
* **Integrações Externas:** API **ChatGuru** (envio automatizado de confirmações, lembretes e promoções via WhatsApp/SMS/E-mail).

---

## ✨ Funcionalidades Desenvolvidas

### No Protótipo Atual (`codigo.c`)
* **Cadastro e Autenticação de Clientes (`RF001` / `RF005`):** Registro em memória com validação de CPF e senha, gerando ID único.
* **Agendamento com Bloqueio Automático (`RF004`):** Seleção de serviço, barbeiro, data e horário. Valida o horário comercial (**07:00 às 18:00**) e impede sobreposição de horários para o mesmo profissional.
* **Cancelamento com Regra de Antecedência (`RF006`):** Permite ao cliente visualizar seus agendamentos ativos e cancelar reservas, respeitando a trava de **24 horas de antecedência**.
* **Listagem de Serviços e Histórico:** Consulta de serviços disponíveis e histórico vinculado ao ID do cliente logado.

### Mapeadas na Modelagem Completa
* **Painel do Barbeiro/Recepcionista (`RF009` / `RF010`):** Visualização da agenda diária/semanal, atualização de status (*Confirmado, Em Andamento, Concluído, Cancelado*) e bloqueio manual de horários (almoço/folga).
* **Gestão Administrativa e Financeira (`UC6`):** Dashboard do gerente com faturamento total, contagem de clientes ativos/inativos, ticket por cliente e exportação de relatórios (PDF/CSV/Excel).
* **Notificações Automatizadas (`RF011`):** Disparo de protocolos de confirmação e lembretes via ChatGuru.

---

## ⚙️ Pré-requisitos e Dependências de Execução

Como o MVP atual é desenvolvido em Linguagem C pura, não há dependências de pacotes externos de terceiros, exigindo apenas um ambiente de compilação C:

* **Compilador C:** `GCC` (MinGW no Windows, GCC no Linux ou Clang no macOS).
* **Terminal / Console:** Prompt de Comando, PowerShell, Bash ou terminal integrado de uma IDE (VS Code, Code::Blocks, Dev-C++).
* **Git** (opcional, para clonar o repositório).

### Como Compilar e Executar

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/bsalvador49/Projeto-Barbearia.git](https://github.com/bsalvador49/Projeto-Barbearia.git)
   cd Projeto-Barbearia

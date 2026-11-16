# 💈 Connect Barber - Sistema de Gestão e Agendamento

Sistema desenvolvido para automatizar, organizar e modernizar o atendimento e o controle de agenda da **Barbearia Trato Fino**, localizada em Ceilândia Norte, Brasília/DF[cite: 2, 4, 115].

---

## 📖 Sobre o Projeto

O **Connect Barber** é um Projeto Integrador desenvolvido no âmbito acadêmico (UNIEURO) com o objetivo de solucionar os gargalos operacionais gerados por métodos manuais (como agendamentos por telefone e anotações em planilhas ou cadernos)[cite: 1, 2, 3, 115]. 

O projeto contempla duas frentes principais:
1. **MVP Funcional em Linguagem C:** Protótipo executável via terminal que valida a lógica central de cadastros, validações de segurança e regras de agendamento em memória.
2. **Modelagem e Protótipo Visual (Figma):** Especificação completa de requisitos funcionais/não funcionais, diagramas UML, Modelo Entidade-Relacionamento (DER) e telas do sistema desenhadas no Figma[cite: 12, 41, 110, 147].

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem C (Padrão C99/C11):** Desenvolvimento da lógica estruturada do MVP (`codigo.c`)[cite: 118].
- **Bibliotecas Padrão e Sistema:** `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<conio.h>`, `<termios.h>` e `<unistd.h>` (para manipulação de menus, vetores, structs e ocultação segura de senhas no terminal).
- **Figma:** Ferramenta utilizada para o design de interface e prototipagem das telas do sistema (`TL001` a `TL020`)[cite: 41, 110].
- **Git & GitHub:** Controle de versão e hospedagem do código-fonte e documentações.

---

## ✨ Funcionalidades Desenvolvidas (MVP Atual)

O código atual (`codigo.c`) implementa com robustez as seguintes funcionalidades:

- **Segurança na Entrada de Dados:** 
  * Ocultação de caracteres da senha com asteriscos (`*`) em tempo de digitação, com suporte multiplataforma (Windows e sistemas Unix/Linux/macOS).
- **Módulo de Clientes (`RF001`, `RF005`):**
  * Cadastro completo de clientes (Nome, CPF e Senha) com validação contra campos em branco ou preenchidos apenas com espaços.
  * **Validação Real de CPF:** Verificação matemática completa dos dígitos verificadores do CPF e bloqueio automático de CPFs duplicados no sistema.
  * Sistema de Login integrado com verificação de credenciais e redirecionamento dinâmico para o painel do cliente.
- **Módulo de Agendamento Inteligente (`RF004`):**
  * **Validação de Data:** Garante o formato correto (`DD/MM/AAAA`), valida anos a partir de 2026, limites de dias por mês e cálculo automático de anos bissextos (`ehBissexto`).
  * **Controle de Horário Comercial:** Restringe os agendamentos estritamente ao horário de funcionamento da barbearia (das **07:00 às 18:00**), aceitando intervalos de 30 em 30 minutos.
  * **Bloqueio Automático de Conflitos:** Varredura em tempo real na base de dados em memória para impedir que múltiplos clientes reservem o mesmo dia e horário.

---

## 📂 Organização do Repositório

```text
Projeto-Barbearia/
├── assets/
│   └── figma/           # Capturas de tela e fluxos desenhados no Figma
├── docs/                # Documentação detalhada do projeto e diagramas UML/DER
├── codigo.c             # Código-fonte principal do MVP em C
└── README.md            # Documentação técnica do repositório

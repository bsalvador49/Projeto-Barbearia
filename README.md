<div align="center">

# 💈 Connect Barber
**Sistema de Gestão Operacional e Agendamento — Barbearia Trato Fino**

![Java](https://img.shields.io/badge/Java-17%2B-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)
![PostgreSQL](https://img.shields.io/badge/PostgreSQL-316192?style=for-the-badge&logo=postgresql&logoColor=white)
![JUnit](https://img.shields.io/badge/JUnit-25A162?style=for-the-badge&logo=junit5&logoColor=white)
![CLI](https://img.shields.io/badge/Interface-CLI-4D4D4D?style=for-the-badge&logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Versão_Alfa-blue?style=for-the-badge)

</div>

---

## 📖 Sobre o Projeto

O **Connect Barber** é uma solução desenvolvida para automatizar e centralizar a rotina operacional da **Barbearia Trato Fino**, eliminando gargalos causados pelo controle manual em papel e planilhas[cite: 2, 17]. 

Evoluindo de um protótipo inicial estruturado em linguagem C para uma arquitetura robusta orientada a objetos em **Java** com persistência relacional em **PostgreSQL**, o sistema opera via **Interface de Linha de Comando (CLI)**[cite: 2, 6]. O foco principal é garantir a integridade dos dados, prevenir conflitos de horários em tempo real e oferecer controle financeiro e administrativo eficiente[cite: 2, 3].

---

## 🛠️ Tecnologias Utilizadas

| Categoria | Tecnologia / Padrão | Descrição |
| :--- | :--- | :--- |
| **Linguagem** | Java (JDK 17+) | Desenvolvimento baseado no paradigma Orientado a Objetos (POO)[cite: 2]. |
| **Banco de Dados** | PostgreSQL | SGBD relacional utilizado para persistência segura e controle de concorrência[cite: 2, 6]. |
| **Persistência** | JDBC (Padrão DAO) | Camada de acesso a dados desacoplada para operações SQL[cite: 3]. |
| **Interface** | CLI (Console) | Menus textuais interativos executados diretamente no terminal[cite: 6]. |
| **Segurança** | BCrypt / SHA-256 | Hashing criptográfico com *salt* para proteção das senhas dos usuários[cite: 3, 6]. |
| **Testes** | JUnit | Testes unitários automatizados para validação das regras de negócio[cite: 3]. |

---

## ✨ Funcionalidades Desenvolvidas

### 🔐 Autenticação e Perfis de Acesso
* Registro e login com validação de credenciais por **CPF e senha**[cite: 4, 8].
* Redirecionamento dinâmico de menus conforme o nível de permissão: **Cliente**, **Barbeiro/Recepcionista** e **Gerente**[cite: 4, 8, 11].

### ✂️ Catálogo de Serviços
* Listagem organizada contendo nome do serviço, descrição, valor e tempo de duração estimado em minutos[cite: 4].

### 📅 Gestão de Agendamentos
* **Marcação Segura:** Verificação automática de disponibilidade no banco de dados, bloqueando horários duplicados para o mesmo barbeiro[cite: 5].
* **Remarcação e Cancelamento:** Alteração ou cancelamento de reservas com liberação imediata na agenda (respeitando a regra de antecedência mínima de 24 horas)[cite: 5, 21].

### 📋 Controle de Agenda Interna (Equipe)
* Visualização filtrada por período e por ID do profissional logado[cite: 4, 7].
* Atualização de status dos atendimentos (`Pendente`, `Confirmado`, `Concluído`, `Cancelado`)[cite: 4, 7].

### 📊 Administração e Relatórios (Gerente)
* Cadastro, edição e inativação de **barbeiros** e **serviços** no catálogo[cite: 5].
* Emissão de relatórios financeiros consolidados no terminal baseados nos atendimentos concluídos[cite: 8].

---

## ⚙️ Pré-requisitos

Antes de iniciar, certifique-se de ter as seguintes ferramentas instaladas em sua máquina:

* **[Java Development Kit (JDK) 17+](https://www.oracle.com/java/technologies/downloads/)**
* **[PostgreSQL 12+](https://www.postgresql.org/download/)** ativo e em execução
* **Driver JDBC do PostgreSQL** configurado no *classpath* / gerenciador de dependências do projeto

---

## 🔧 Variáveis de Ambiente e Configuração

Crie um arquivo `.env` na raiz do projeto (ou configure as variáveis diretamente no sistema operacional / arquivo `application.properties`) com os dados de acesso ao banco:

```env
# Configurações de Conexão com o Banco de Dados PostgreSQL
DB_URL=jdbc:postgresql://localhost:5432/connect_barber
DB_USER=postgres
DB_PASSWORD=sua_senha_aqui

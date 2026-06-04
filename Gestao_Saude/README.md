# SIGEH-DF — Sistema Integrado de Gestao Hospitalar do Distrito Federal

Projeto educacional de um sistema hospitalar feito em C puro, executado pelo terminal e organizado em uma estrutura inspirada em projetos Java/Maven.

A aplicacao foi criada para praticar Algoritmos e Logica de Programacao, modularizacao, structs, vetores, strings com `char[]`, regras de negocio, controle de menus, exclusao logica, triagem, agendamentos, controle de leitos e relatorios.

O projeto nao usa interface grafica, banco de dados ou API web nesta etapa. Toda a interacao acontece pelo terminal.

---

## Indice

- [Visao geral](#visao-geral)
- [Estado atual](#estado-atual)
- [Funcionalidades](#funcionalidades)
- [Tecnologias](#tecnologias)
- [Como executar](#como-executar)
- [Estrutura do projeto](#estrutura-do-projeto)
- [Mapa dos arquivos](#mapa-dos-arquivos)
- [Guia arquivo por arquivo](#guia-arquivo-por-arquivo)
- [Organizacao da aplicacao](#organizacao-da-aplicacao)
- [Fluxo principal da aplicacao](#fluxo-principal-da-aplicacao)
- [Regras de dominio](#regras-de-dominio)
- [Persistencia atual](#persistencia-atual)
- [Plano de persistencia](#plano-de-persistencia)
- [Testes automatizados](#testes-automatizados)
- [Conceitos praticados](#conceitos-praticados)
- [Linha do tempo planejada](#linha-do-tempo-planejada)

---

## Visao geral

O SIGEH-DF representa um sistema hospitalar simples para terminal. Ele permite organizar pacientes, medicos, agendamentos, alas, leitos, internacoes, triagens e relatorios gerais.

A ideia principal do projeto e separar bem cada responsabilidade:

- a camada `app` cuida da execucao no terminal;
- a camada `model` concentra estruturas centrais do dominio;
- a camada `persistence` contem os modulos atuais do sistema e seus headers;
- os testes em `src/test/c` serao usados futuramente para verificar regras e operacoes.

Essa separacao ajuda a manter o codigo organizado. O menu principal nao deve concentrar todas as regras do sistema, e cada modulo deve cuidar de uma area especifica do fluxo hospitalar.

---

## Estado atual

A aplicacao funciona em memoria, usando vetores globais de structs. Os dados sao perdidos quando o programa encerra.

Pontos principais do estado atual:

- `main.c` exibe o menu principal e chama os menus dos modulos.
- `hospital.h` centraliza structs, constantes e declaracoes `extern`.
- Os modulos de pacientes, medicos, agendamentos, alas, leitos, internacoes, triagem e relatorios estao separados.
- Os arquivos `.c` e `.h` dos modulos ficam em `src/main/c/persistence`.
- Ainda nao ha persistencia em arquivos ou SQLite.
- Os arquivos de teste existem como preparacao, mas ainda nao possuem testes implementados.
- O comando `make test` apenas exibe uma mensagem informando que os testes serao implementados depois.

---

## Funcionalidades

- Cadastrar, listar, editar e remover logicamente pacientes.
- Registrar regiao administrativa do paciente.
- Cadastrar, listar, editar e remover logicamente medicos.
- Criar, listar, cancelar e concluir agendamentos.
- Validar conflito de agenda por medico, data e horario.
- Cadastrar, listar e remover logicamente alas.
- Cadastrar e listar leitos.
- Internar paciente em leito disponivel.
- Registrar alta e liberar leito.
- Realizar triagem por pontuacao.
- Listar triagens realizadas.
- Exibir relatorios gerais e taxa de ocupacao por ala.

---

## Tecnologias

- Linguagem C.
- GCC.
- Makefile.
- Terminal.
- `assert.h` planejado para testes futuros.

Ferramentas principais configuradas:

| Item | Uso |
|---|---|
| `gcc` | Compila o sistema em C |
| `Makefile` | Centraliza comandos de build, execucao, limpeza e teste |
| `-Wall -Wextra -pedantic` | Ativa avisos importantes de compilacao |
| `-Isrc/main/c/model` | Permite incluir `hospital.h` com include simples |
| `-Isrc/main/c/persistence` | Permite incluir headers dos modulos com include simples |

---

## Como executar

Na raiz do projeto, compile com:

```bash
make
```

Para compilar e executar:

```bash
make run
```

Ao iniciar, a aplicacao:

1. cria os vetores globais em memoria;
2. exibe o menu principal;
3. direciona o usuario para o modulo escolhido;
4. executa as operacoes ate o usuario escolher sair.

Menu principal:

```text
1. Gerenciar Pacientes
2. Gerenciar Medicos
3. Gerenciar Agendamentos
4. Gerenciar Alas
5. Gerenciar Leitos
6. Gerenciar Internacoes
7. Gerenciar Triagem
8. Gerar Relatorios
0. Sair
```

Para limpar o binario:

```bash
make clean
```

Para a etapa futura de testes:

```bash
make test
```

Comando manual equivalente:

```bash
gcc -Wall -Wextra -pedantic -Isrc/main/c/model -Isrc/main/c/persistence src/main/c/app/main.c src/main/c/persistence/paciente.c src/main/c/persistence/medico.c src/main/c/persistence/agendamento.c src/main/c/persistence/ala.c src/main/c/persistence/leito.c src/main/c/persistence/internacao.c src/main/c/persistence/triagem.c src/main/c/persistence/relatorio.c -o sigeh
```

---

## Estrutura do projeto

```text
.
├── Makefile
├── README.md
├── .gitignore
├── src
│   ├── main
│   │   └── c
│   │       ├── app
│   │       │   └── main.c
│   │       ├── model
│   │       │   └── hospital.h
│   │       └── persistence
│   │           ├── agendamento.c
│   │           ├── agendamento.h
│   │           ├── ala.c
│   │           ├── ala.h
│   │           ├── internacao.c
│   │           ├── internacao.h
│   │           ├── leito.c
│   │           ├── leito.h
│   │           ├── medico.c
│   │           ├── medico.h
│   │           ├── paciente.c
│   │           ├── paciente.h
│   │           ├── relatorio.c
│   │           ├── relatorio.h
│   │           ├── triagem.c
│   │           └── triagem.h
│   └── test
│       └── c
│           ├── model
│           └── persistence
│               ├── test_agendamento.c
│               ├── test_leito.c
│               ├── test_medico.c
│               ├── test_paciente.c
│               └── test_triagem.c
└── data
```

A pasta `data/` sera usada em tempo de execucao quando a persistencia em arquivos for implementada.

Arquivos gerados, como binarios e dados locais, nao devem ser versionados no Git.

---

## Mapa dos arquivos

Esta parte mostra onde cada arquivo entra no projeto.

```text
Makefile
```

Arquivo de compilacao. Define compilador, flags, arquivos-fonte, nome do binario e comandos `make`, `make run`, `make clean` e `make test`.

```text
.gitignore
```

Arquivo que impede o Git de versionar arquivos gerados pela IDE, pelo sistema operacional ou pela compilacao.

```text
README.md
```

Arquivo central de documentacao. Reune visao geral, estrutura de pastas, explicacao dos modulos, regras, conceitos estudados e plano de evolucao.

```text
src/main/c/app
```

Pasta da aplicacao de terminal. Aqui fica o ponto de entrada do sistema: `main.c`.

```text
src/main/c/model
```

Pasta do modelo central. Aqui fica `hospital.h`, com as structs, constantes e declaracoes globais externas.

```text
src/main/c/persistence
```

Pasta dos modulos atuais. Aqui ficam os arquivos `.c` e `.h` dos menus e regras de pacientes, medicos, agendamentos, alas, leitos, internacoes, triagem e relatorios.

```text
src/test/c/model
```

Pasta reservada para testes futuros das estruturas centrais.

```text
src/test/c/persistence
```

Pasta reservada para testes futuros dos modulos do sistema.

---

## Guia arquivo por arquivo

O objetivo desta parte e explicar a funcao de cada arquivo no projeto.

---

### `Makefile`

| Parte | Explicacao |
|---|---|
| `CC = gcc` | Define o compilador usado. |
| `CFLAGS` | Define avisos de compilacao e caminhos de include. |
| `SRC` | Lista todos os arquivos `.c` usados na compilacao. |
| `OUT = sigeh` | Define o nome do binario final. |
| `all` | Compila o sistema. |
| `run` | Compila e executa. |
| `clean` | Remove o binario. |
| `test` | Indica que testes automatizados ainda serao implementados. |

---

### `src/main/c/app/main.c`

Arquivo principal da aplicacao. Define os vetores e contadores globais, exibe o menu principal e chama os menus dos modulos.

Responsabilidades:

- iniciar o loop principal;
- ler a opcao do usuario;
- chamar `menuPacientes`, `menuMedicos`, `menuAgendamentos`, `menuAlas`, `menuLeitos`, `menuInternacoes`, `menuTriagem` e `menuRelatorios`;
- encerrar o sistema quando o usuario escolhe sair.

---

### `src/main/c/model/hospital.h`

Header central do projeto.

Responsabilidades:

- incluir bibliotecas padrao usadas pelo sistema;
- definir constantes com `#define`;
- declarar as structs principais;
- declarar vetores e contadores globais com `extern`.

Structs definidas:

- `Paciente`;
- `Medico`;
- `Agendamento`;
- `Ala`;
- `Leito`;
- `Internacao`;
- `Triagem`.

---

### `src/main/c/persistence/paciente.c` e `paciente.h`

Modulo de pacientes.

Responsabilidades:

- cadastrar paciente;
- listar pacientes ativos;
- editar dados do paciente;
- remover paciente por exclusao logica;
- registrar regiao administrativa.

---

### `src/main/c/persistence/medico.c` e `medico.h`

Modulo de medicos.

Responsabilidades:

- cadastrar medico;
- listar medicos ativos;
- editar nome, CRM e especialidade;
- remover medico por exclusao logica.

---

### `src/main/c/persistence/agendamento.c` e `agendamento.h`

Modulo de agendamentos.

Responsabilidades:

- criar agendamento;
- listar agendamentos;
- cancelar agendamento;
- concluir agendamento;
- validar conflito por medico, data e horario.

---

### `src/main/c/persistence/ala.c` e `ala.h`

Modulo de alas.

Responsabilidades:

- cadastrar ala;
- listar alas ativas;
- remover ala por exclusao logica;
- manter total de leitos e leitos ocupados.

---

### `src/main/c/persistence/leito.c` e `leito.h`

Modulo de leitos.

Responsabilidades:

- cadastrar leito;
- listar leitos;
- associar leito a uma ala;
- indicar se o leito esta ocupado.

---

### `src/main/c/persistence/internacao.c` e `internacao.h`

Modulo de internacoes.

Responsabilidades:

- internar paciente;
- validar paciente ativo;
- validar leito livre;
- marcar leito como ocupado;
- registrar alta;
- liberar leito apos alta;
- listar internacoes.

---

### `src/main/c/persistence/triagem.c` e `triagem.h`

Modulo de triagem.

Responsabilidades:

- registrar sintomas;
- calcular pontuacao;
- classificar prioridade;
- listar triagens.

---

### `src/main/c/persistence/relatorio.c` e `relatorio.h`

Modulo de relatorios.

Responsabilidades:

- exibir totais gerais;
- mostrar ocupacao por ala;
- servir como base para o futuro Painel Situacional do DF.

---

## Organizacao da aplicacao

A aplicacao esta dividida em tres areas principais:

- `app`: entrada do sistema e menu principal;
- `model`: estruturas centrais do dominio;
- `persistence`: modulos atuais do sistema e ponto futuro para persistencia.

Embora o nome `persistence` seja inspirado no projeto Java de referencia, nesta etapa ele ainda nao implementa gravacao em arquivos ou banco. Os dados continuam armazenados em memoria.

---

## Fluxo principal da aplicacao

1. O usuario executa `make run` ou `./sigeh`.
2. `main.c` exibe o menu principal.
3. O usuario escolhe uma opcao.
4. O sistema chama o menu do modulo correspondente.
5. O modulo executa cadastros, listagens, edicoes ou validacoes.
6. O usuario retorna ao menu principal.
7. Ao escolher `0`, o sistema encerra.

---

## Regras de dominio

- Um paciente inativo nao deve ser usado como paciente valido em novas operacoes.
- Um medico inativo nao deve ser usado para novos agendamentos.
- O mesmo medico nao pode ter dois agendamentos ativos no mesmo dia e horario.
- Agendamentos cancelados nao geram conflito.
- Medicos diferentes podem atender no mesmo dia e horario.
- Um leito ocupado nao pode receber outro paciente.
- Registrar alta libera o leito.
- A triagem soma pontos por sintomas e idade.
- A exclusao logica usa `ativo = 0`.

---

## Persistencia atual

Ainda nao ha persistencia real implementada.

Atualmente:

- os dados ficam em memoria;
- os vetores globais sao definidos em `main.c`;
- os contadores globais controlam quantos registros existem;
- ao encerrar o programa, os dados cadastrados sao perdidos.

---

## Plano de persistencia

Evolucoes planejadas:

1. Salvar dados em arquivos `.txt` dentro de `data/`.
2. Criar funcoes de leitura e escrita por modulo.
3. Separar melhor codigo de dominio e codigo de persistencia.
4. Evoluir para SQLite no futuro.

---

## Testes automatizados

Os arquivos de teste foram criados como preparacao:

- `test_agendamento.c`;
- `test_paciente.c`;
- `test_medico.c`;
- `test_leito.c`;
- `test_triagem.c`.

No momento, eles ainda nao implementam testes. A ideia futura e usar `assert.h` para validar regras como:

- conflito de agendamento;
- exclusao logica;
- paciente ativo/inativo;
- medico ativo/inativo;
- leito ocupado/livre;
- classificacao de triagem.

---

## Conceitos praticados

- `structs`;
- vetores;
- strings com `char[]`;
- constantes com `#define`;
- funcoes;
- headers `.h`;
- modularizacao;
- `do while`;
- `switch case`;
- `for`;
- `if/else`;
- `strcmp`;
- `strcpy`;
- busca linear;
- exclusao logica;
- validacao de regras de negocio.

---

## Linha do tempo planejada

1. Consolidar structs, vetores e menus.
2. Separar o projeto em modulos.
3. Organizar a estrutura em formato inspirado no Maven.
4. Implementar testes com `assert.h`.
5. Implementar persistencia em arquivos `.txt`.
6. Criar indicadores para o Painel Situacional do DF.
7. Planejar prontuario integrado.
8. Planejar exames integrados.
9. Evoluir para SQLite.

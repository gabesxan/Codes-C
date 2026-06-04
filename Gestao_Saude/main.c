#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACIENTES 100
#define MAX_MEDICOS 50
#define MAX_AGENDAMENTOS 200
#define MAX_ALAS 20
#define MAX_LEITOS 300
#define MAX_INTERNACOES 200
#define MAX_TRIAGENS 300

typedef struct
{
    int id;
    char nome[100];
    char cpf[15];
    int idade;
    char telefone[20];
    char sexo;
    int ativo;
} Paciente;

typedef struct
{
    int id;
    char nome[100];
    char crm[20];
    char especialidade[50];
    int ativo;
} Medico;

typedef struct
{
    int id;
    int pacienteId;
    int medicoId;
    char data[11];
    char horario[6];
    char status[20];
} Agendamento;

typedef struct
{
    int id;
    char nome[100];
    char tipo[50];
    int totalLeitos;
    int leitosOcupados;
    int ativo;
} Ala;

typedef struct
{
    int id;
    int alaId;
    int numero;
    int ocupado;
    int pacienteId;
} Leito;

typedef struct
{
    int id;
    int pacienteId;
    int alaId;
    int leitoId;
    char dataEntrada[11];
    char dataAlta[11];
    char status[20];
} Internacao;

typedef struct
{
    int id;
    int pacienteId;
    int febre;
    int faltaAr;
    int dorIntensa;
    int pressaoAlta;
    int pontuacao;
    char classificacao[30];
} Triagem;

Paciente pacientes[MAX_PACIENTES];
Medico medicos[MAX_MEDICOS];
Agendamento agendamentos[MAX_AGENDAMENTOS];
Ala alas[MAX_ALAS];
Leito leitos[MAX_LEITOS];
Internacao internacoes[MAX_INTERNACOES];
Triagem triagens[MAX_TRIAGENS];

int totalPacientes = 0;
int totalMedicos = 0;
int totalAgendamentos = 0;
int totalAlas = 0;
int totalLeitos = 0;
int totalInternacoes = 0;
int totalTriagens = 0;

int main(void)
{
    int opcao;

    do
    {
        printf("\n=============================================\n");
        printf("SIGEH-DF - Sistema de Gestao Hospitalar do DF\n");
        printf("=============================================\n");
        printf("1. Gerenciar Pacientes\n");
        printf("2. Gerenciar Medicos\n");
        printf("3. Gerenciar Agendamentos\n");
        printf("4. Gerenciar Alas\n");
        printf("5. Gerenciar Leitos\n");
        printf("6. Gerenciar Internacoes\n");
        printf("7. Gerenciar Triagem\n");
        printf("8. Gerar Relatorios\n");
        printf("0. Sair\n");
        printf("---------------------------------------------\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int caso1;

            printf("\nVoce escolheu: Gerenciar Pacientes\n");

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE PACIENTES\n");
                printf("=============================================\n");
                printf("1. Cadastrar Paciente\n");
                printf("2. Listar Pacientes\n");
                printf("3. Editar Paciente\n");
                printf("4. Excluir Paciente\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &caso1);

                switch (caso1)
                {
                case 1:
                {
                    if (totalPacientes >= MAX_PACIENTES)
                    {
                        printf("\nLimite de pacientes atingido. Nao e possivel cadastrar mais.\n");
                        break;
                    }
                    pacientes[totalPacientes].id = totalPacientes + 1;

                    printf("\nNome: ");
                    scanf(" %[^\n]", pacientes[totalPacientes].nome);

                    printf("CPF: ");
                    scanf(" %[^\n]", pacientes[totalPacientes].cpf);

                    printf("Idade: ");
                    scanf("%d", &pacientes[totalPacientes].idade);

                    printf("Telefone: ");
                    scanf(" %[^\n]", pacientes[totalPacientes].telefone);

                    printf("Sexo (M/F/O): ");
                    scanf(" %c", &pacientes[totalPacientes].sexo);

                    pacientes[totalPacientes].ativo = 1;
                    totalPacientes++;

                    printf("\nPaciente cadastrado com sucesso! ID: %d\n", pacientes[totalPacientes - 1].id);
                    break;
                }

                case 2:
                {
                    if (totalPacientes == 0)
                    {
                        printf("\nNenhum paciente cadastrado.\n");
                        break;
                    }
                    printf("\nLista de Pacientes:\n");
                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].ativo == 1)
                        {
                            printf("\nID: %d\n", pacientes[i].id);
                            printf("Nome: %s\n", pacientes[i].nome);
                            printf("CPF: %s\n", pacientes[i].cpf);
                            printf("Idade: %d\n", pacientes[i].idade);
                            printf("Telefone: %s\n", pacientes[i].telefone);
                            printf("Sexo: %c\n", pacientes[i].sexo);
                        }
                    }
                    break;
                }

                case 3:
                {
                    int idBusca;
                    int encontrado = 0;
                    int opcaoEditar;

                    printf("\nDigite o ID do paciente que deseja editar: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].id == idBusca && pacientes[i].ativo == 1)
                        {
                            encontrado = 1;

                            printf("\nPaciente encontrado:\n");
                            printf("ID: %d\n", pacientes[i].id);
                            printf("Nome: %s\n", pacientes[i].nome);
                            printf("CPF: %s\n", pacientes[i].cpf);
                            printf("Idade: %d\n", pacientes[i].idade);
                            printf("Telefone: %s\n", pacientes[i].telefone);
                            printf("Sexo: %c\n", pacientes[i].sexo);

                            printf("\nO que deseja editar?\n");
                            printf("1. Nome\n");
                            printf("2. CPF\n");
                            printf("3. Idade\n");
                            printf("4. Telefone\n");
                            printf("5. Sexo\n");
                            printf("0. Cancelar\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &opcaoEditar);

                            switch (opcaoEditar)
                            {
                            case 1:
                                printf("Novo nome: ");
                                scanf(" %[^\n]", pacientes[i].nome);
                                printf("\nNome atualizado com sucesso.\n");
                                break;

                            case 2:
                                printf("Novo CPF: ");
                                scanf(" %[^\n]", pacientes[i].cpf);
                                printf("\nCPF atualizado com sucesso.\n");
                                break;

                            case 3:
                                printf("Nova idade: ");
                                scanf("%d", &pacientes[i].idade);
                                printf("\nIdade atualizada com sucesso.\n");
                                break;

                            case 4:
                                printf("Novo telefone: ");
                                scanf(" %[^\n]", pacientes[i].telefone);
                                printf("\nTelefone atualizado com sucesso.\n");
                                break;

                            case 5:
                                printf("Novo sexo (M/F/O): ");
                                scanf(" %c", &pacientes[i].sexo);
                                printf("\nSexo atualizado com sucesso.\n");
                                break;

                            case 0:
                                printf("\nEdicao cancelada.\n");
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }

                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nPaciente nao encontrado ou inativo.\n");
                    }

                    break;
                }

                case 4:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID do paciente que deseja excluir: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].id == idBusca && pacientes[i].ativo == 1)
                        {
                            pacientes[i].ativo = 0;
                            encontrado = 1;

                            printf("\nPaciente removido com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nPaciente nao encontrado ou ja inativo.\n");
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso1 != 0);

            break;
        }

        case 2:
        {
            int caso2;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE MEDICOS\n");
                printf("=============================================\n");
                printf("1. Cadastrar Medico\n");
                printf("2. Listar Medicos\n");
                printf("3. Editar Medico\n");
                printf("4. Excluir Medico\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &caso2);

                switch (caso2)
                {
                case 1:
                {
                    if (totalMedicos >= MAX_MEDICOS)
                    {
                        printf("\nLimite de medicos atingido.\n");
                        break;
                    }

                    medicos[totalMedicos].id = totalMedicos + 1;

                    printf("\nNome do medico, sem Dr/Dr(a): ");
                    scanf(" %[^\n]", medicos[totalMedicos].nome);

                    printf("Numero do CRM: ");
                    scanf(" %[^\n]", medicos[totalMedicos].crm);

                    printf("Especialidade: ");
                    scanf(" %[^\n]", medicos[totalMedicos].especialidade);

                    medicos[totalMedicos].ativo = 1;
                    totalMedicos++;

                    printf("\nMedico cadastrado com sucesso! ID: %d\n", medicos[totalMedicos - 1].id);
                    break;
                }

                case 2:
                {
                    if (totalMedicos == 0)
                    {
                        printf("\nNenhum medico cadastrado.\n");
                        break;
                    }

                    printf("\nLista de Medicos:\n");

                    for (int i = 0; i < totalMedicos; i++)
                    {
                        if (medicos[i].ativo == 1)
                        {
                            printf("\nID: %d\n", medicos[i].id);
                            printf("Nome: Dr(a). %s\n", medicos[i].nome);
                            printf("CRM: CRM%s\n", medicos[i].crm);
                            printf("Especialidade: %s\n", medicos[i].especialidade);
                        }
                    }

                    break;
                }

                case 3:
                {
                    int idBusca;
                    int encontrado = 0;
                    int opcaoEditar;

                    printf("\nDigite o ID do medico que deseja editar: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalMedicos; i++)
                    {
                        if (medicos[i].id == idBusca && medicos[i].ativo == 1)
                        {
                            encontrado = 1;

                            printf("\nMedico encontrado:\n");
                            printf("ID: %d\n", medicos[i].id);
                            printf("Nome: Dr(a). %s\n", medicos[i].nome);
                            printf("CRM: CRM%s\n", medicos[i].crm);
                            printf("Especialidade: %s\n", medicos[i].especialidade);

                            printf("\nO que deseja editar?\n");
                            printf("1. Nome\n");
                            printf("2. CRM\n");
                            printf("3. Especialidade\n");
                            printf("0. Cancelar\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d", &opcaoEditar);

                            switch (opcaoEditar)
                            {
                            case 1:
                                printf("Novo nome do medico, sem Dr/Dr(a): ");
                                scanf(" %[^\n]", medicos[i].nome);
                                printf("\nNome atualizado com sucesso.\n");
                                break;

                            case 2:
                                printf("Novo numero do CRM: ");
                                scanf(" %[^\n]", medicos[i].crm);
                                printf("\nCRM atualizado com sucesso.\n");
                                break;

                            case 3:
                                printf("Nova especialidade: ");
                                scanf(" %[^\n]", medicos[i].especialidade);
                                printf("\nEspecialidade atualizada com sucesso.\n");
                                break;

                            case 0:
                                printf("\nEdicao cancelada.\n");
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }

                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nMedico nao encontrado ou inativo.\n");
                    }

                    break;
                }

                case 4:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID do medico que deseja excluir: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalMedicos; i++)
                    {
                        if (medicos[i].id == idBusca && medicos[i].ativo == 1)
                        {
                            medicos[i].ativo = 0;
                            encontrado = 1;

                            printf("\nMedico removido com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nMedico nao encontrado ou ja inativo.\n");
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso2 != 0);

            break;
        }
        case 3:
        {
            int caso3;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE AGENDAMENTOS\n");
                printf("=============================================\n");
                printf("1. Criar Agendamento\n");
                printf("2. Listar Agendamentos\n");
                printf("3. Cancelar Agendamento\n");
                printf("4. Concluir Agendamento\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &caso3);

                switch (caso3)
                {
                case 1:
                {
                    int pacienteId;
                    int medicoId;
                    int pacienteEncontrado = 0;
                    int medicoEncontrado = 0;
                    int conflito = 0;
                    char data[11];
                    char horario[6];

                    if (totalAgendamentos >= MAX_AGENDAMENTOS)
                    {
                        printf("\nLimite de agendamentos atingido.\n");
                        break;
                    }

                    printf("\nID do paciente: ");
                    scanf("%d", &pacienteId);

                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].id == pacienteId && pacientes[i].ativo == 1)
                        {
                            pacienteEncontrado = 1;
                            break;
                        }
                    }

                    if (pacienteEncontrado == 0)
                    {
                        printf("\nPaciente nao encontrado ou inativo.\n");
                        break;
                    }

                    printf("ID do medico: ");
                    scanf("%d", &medicoId);

                    for (int i = 0; i < totalMedicos; i++)
                    {
                        if (medicos[i].id == medicoId && medicos[i].ativo == 1)
                        {
                            medicoEncontrado = 1;
                            break;
                        }
                    }

                    if (medicoEncontrado == 0)
                    {
                        printf("\nMedico nao encontrado ou inativo.\n");
                        break;
                    }

                    printf("Data (DD/MM/AAAA): ");
                    scanf(" %[^\n]", data);

                    printf("Horario (HH:MM): ");
                    scanf(" %[^\n]", horario);

                    for (int i = 0; i < totalAgendamentos; i++)
                    {
                        if (agendamentos[i].medicoId == medicoId &&
                            strcmp(agendamentos[i].data, data) == 0 &&
                            strcmp(agendamentos[i].horario, horario) == 0 &&
                            strcmp(agendamentos[i].status, "CANCELADO") != 0)
                        {
                            conflito = 1;
                            break;
                        }
                    }

                    if (conflito == 1)
                    {
                        printf("\nEste medico ja possui agendamento nesse dia e horario.\n");
                        break;
                    }

                    agendamentos[totalAgendamentos].id = totalAgendamentos + 1;
                    agendamentos[totalAgendamentos].pacienteId = pacienteId;
                    agendamentos[totalAgendamentos].medicoId = medicoId;
                    strcpy(agendamentos[totalAgendamentos].data, data);
                    strcpy(agendamentos[totalAgendamentos].horario, horario);
                    strcpy(agendamentos[totalAgendamentos].status, "AGENDADO");

                    totalAgendamentos++;

                    printf("\nAgendamento criado com sucesso! ID: %d\n", agendamentos[totalAgendamentos - 1].id);

                    break;
                }
                case 2:
                {
                    if (totalAgendamentos == 0)
                    {
                        printf("\nNenhum agendamento cadastrado.\n");
                        break;
                    }

                    printf("\nLista de Agendamentos:\n");

                    for (int i = 0; i < totalAgendamentos; i++)
                    {
                        printf("\nID: %d\n", agendamentos[i].id);
                        printf("Paciente ID: %d\n", agendamentos[i].pacienteId);
                        printf("Medico ID: %d\n", agendamentos[i].medicoId);
                        printf("Data: %s\n", agendamentos[i].data);
                        printf("Horario: %s\n", agendamentos[i].horario);
                        printf("Status: %s\n", agendamentos[i].status);
                    }

                    break;
                }
                case 3:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID do agendamento que deseja cancelar: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalAgendamentos; i++)
                    {
                        if (agendamentos[i].id == idBusca)
                        {
                            strcpy(agendamentos[i].status, "CANCELADO");
                            encontrado = 1;

                            printf("\nAgendamento cancelado com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nAgendamento nao encontrado.\n");
                    }

                    break;
                }
                case 4:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID do agendamento que deseja concluir: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalAgendamentos; i++)
                    {
                        if (agendamentos[i].id == idBusca)
                        {
                            strcpy(agendamentos[i].status, "CONCLUIDO");
                            encontrado = 1;

                            printf("\nAgendamento concluido com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nAgendamento nao encontrado.\n");
                    }

                    break;
                }
                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso3 != 0);

            break;
        }
        case 4:
        {
            int caso4;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE ALAS\n");
                printf("=============================================\n");
                printf("1. Cadastrar Ala\n");
                printf("2. Listar Alas\n");
                printf("3. Excluir Ala\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &caso4);

                switch (caso4)
                {
                case 1:
                {
                    if (totalAlas >= MAX_ALAS)
                    {
                        printf("\nLimite de alas atingido.\n");
                        break;
                    }

                    alas[totalAlas].id = totalAlas + 1;

                    printf("\nNome da ala: ");
                    scanf(" %[^\n]", alas[totalAlas].nome);

                    printf("Tipo da ala: ");
                    scanf(" %[^\n]", alas[totalAlas].tipo);

                    printf("Total de leitos: ");
                    scanf("%d", &alas[totalAlas].totalLeitos);

                    alas[totalAlas].leitosOcupados = 0;
                    alas[totalAlas].ativo = 1;
                    totalAlas++;

                    printf("\nAla cadastrada com sucesso! ID: %d\n", alas[totalAlas - 1].id);
                    break;
                }

                case 2:
                {
                    if (totalAlas == 0)
                    {
                        printf("\nNenhuma ala cadastrada.\n");
                        break;
                    }

                    printf("\nLista de Alas:\n");

                    for (int i = 0; i < totalAlas; i++)
                    {
                        if (alas[i].ativo == 1)
                        {
                            printf("\nID: %d\n", alas[i].id);
                            printf("Nome: %s\n", alas[i].nome);
                            printf("Tipo: %s\n", alas[i].tipo);
                            printf("Total de leitos: %d\n", alas[i].totalLeitos);
                            printf("Leitos ocupados: %d\n", alas[i].leitosOcupados);
                        }
                    }

                    break;
                }

                case 3:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID da ala que deseja excluir: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalAlas; i++)
                    {
                        if (alas[i].id == idBusca && alas[i].ativo == 1)
                        {
                            alas[i].ativo = 0;
                            encontrado = 1;
                            printf("\nAla removida com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nAla nao encontrada ou ja inativa.\n");
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso4 != 0);

            break;
        }

        case 5:
        {
            int caso5;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE LEITOS\n");
                printf("=============================================\n");
                printf("1. Cadastrar Leito\n");
                printf("2. Listar Leitos\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &caso5);

                switch (caso5)
                {
                case 1:
                {
                    int alaId;
                    int alaEncontrada = 0;

                    if (totalLeitos >= MAX_LEITOS)
                    {
                        printf("\nLimite de leitos atingido.\n");
                        break;
                    }

                    printf("\nID da ala: ");
                    scanf("%d", &alaId);

                    for (int i = 0; i < totalAlas; i++)
                    {
                        if (alas[i].id == alaId && alas[i].ativo == 1)
                        {
                            alaEncontrada = 1;
                            break;
                        }
                    }

                    if (alaEncontrada == 0)
                    {
                        printf("\nAla nao encontrada ou inativa.\n");
                        break;
                    }

                    leitos[totalLeitos].id = totalLeitos + 1;
                    leitos[totalLeitos].alaId = alaId;

                    printf("Numero do leito: ");
                    scanf("%d", &leitos[totalLeitos].numero);

                    leitos[totalLeitos].ocupado = 0;
                    leitos[totalLeitos].pacienteId = 0;
                    totalLeitos++;

                    printf("\nLeito cadastrado com sucesso! ID: %d\n", leitos[totalLeitos - 1].id);
                    break;
                }

                case 2:
                {
                    if (totalLeitos == 0)
                    {
                        printf("\nNenhum leito cadastrado.\n");
                        break;
                    }

                    printf("\nLista de Leitos:\n");

                    for (int i = 0; i < totalLeitos; i++)
                    {
                        printf("\nID: %d\n", leitos[i].id);
                        printf("Ala ID: %d\n", leitos[i].alaId);
                        printf("Numero: %d\n", leitos[i].numero);
                        printf("Ocupado: %s\n", leitos[i].ocupado == 1 ? "Sim" : "Nao");
                        printf("Paciente ID: %d\n", leitos[i].pacienteId);
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso5 != 0);

            break;
        }
        case 6:
        {
            int caso6;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE INTERNACOES\n");
                printf("=============================================\n");
                printf("1. Internar Paciente\n");
                printf("2. Dar Alta\n");
                printf("3. Listar Internacoes\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &caso6);

                switch (caso6)
                {
                case 1:
                {
                    int pacienteId, leitoId;
                    int pacienteEncontrado = 0;
                    int leitoEncontrado = 0;
                    int indiceLeito = -1;
                    int indiceAla = -1;

                    if (totalInternacoes >= MAX_INTERNACOES)
                    {
                        printf("\nLimite de internacoes atingido.\n");
                        break;
                    }

                    printf("\nID do paciente: ");
                    scanf("%d", &pacienteId);

                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].id == pacienteId && pacientes[i].ativo == 1)
                        {
                            pacienteEncontrado = 1;
                            break;
                        }
                    }

                    if (pacienteEncontrado == 0)
                    {
                        printf("\nPaciente nao encontrado ou inativo.\n");
                        break;
                    }

                    printf("ID do leito: ");
                    scanf("%d", &leitoId);

                    for (int i = 0; i < totalLeitos; i++)
                    {
                        if (leitos[i].id == leitoId)
                        {
                            leitoEncontrado = 1;
                            indiceLeito = i;
                            break;
                        }
                    }

                    if (leitoEncontrado == 0 || leitos[indiceLeito].ocupado == 1)
                    {
                        printf("\nLeito nao encontrado ou ja ocupado.\n");
                        break;
                    }

                    for (int i = 0; i < totalAlas; i++)
                    {
                        if (alas[i].id == leitos[indiceLeito].alaId && alas[i].ativo == 1)
                        {
                            indiceAla = i;
                            break;
                        }
                    }

                    internacoes[totalInternacoes].id = totalInternacoes + 1;
                    internacoes[totalInternacoes].pacienteId = pacienteId;
                    internacoes[totalInternacoes].alaId = leitos[indiceLeito].alaId;
                    internacoes[totalInternacoes].leitoId = leitoId;

                    printf("Data de entrada (DD/MM/AAAA): ");
                    scanf(" %[^\n]", internacoes[totalInternacoes].dataEntrada);

                    strcpy(internacoes[totalInternacoes].dataAlta, "00/00/0000");
                    strcpy(internacoes[totalInternacoes].status, "INTERNADO");

                    leitos[indiceLeito].ocupado = 1;
                    leitos[indiceLeito].pacienteId = pacienteId;

                    if (indiceAla != -1)
                    {
                        alas[indiceAla].leitosOcupados++;
                    }

                    totalInternacoes++;

                    printf("\nPaciente internado com sucesso! ID da internacao: %d\n", internacoes[totalInternacoes - 1].id);
                    break;
                }

                case 2:
                {
                    int idBusca;
                    int encontrado = 0;

                    printf("\nDigite o ID da internacao: ");
                    scanf("%d", &idBusca);

                    for (int i = 0; i < totalInternacoes; i++)
                    {
                        if (internacoes[i].id == idBusca && strcmp(internacoes[i].status, "INTERNADO") == 0)
                        {
                            printf("Data de alta (DD/MM/AAAA): ");
                            scanf(" %[^\n]", internacoes[i].dataAlta);

                            strcpy(internacoes[i].status, "ALTA");

                            for (int j = 0; j < totalLeitos; j++)
                            {
                                if (leitos[j].id == internacoes[i].leitoId)
                                {
                                    leitos[j].ocupado = 0;
                                    leitos[j].pacienteId = 0;
                                    break;
                                }
                            }

                            for (int j = 0; j < totalAlas; j++)
                            {
                                if (alas[j].id == internacoes[i].alaId && alas[j].leitosOcupados > 0)
                                {
                                    alas[j].leitosOcupados--;
                                    break;
                                }
                            }

                            encontrado = 1;
                            printf("\nAlta registrada com sucesso.\n");
                            break;
                        }
                    }

                    if (encontrado == 0)
                    {
                        printf("\nInternacao nao encontrada ou ja finalizada.\n");
                    }

                    break;
                }

                case 3:
                {
                    if (totalInternacoes == 0)
                    {
                        printf("\nNenhuma internacao cadastrada.\n");
                        break;
                    }

                    printf("\nLista de Internacoes:\n");

                    for (int i = 0; i < totalInternacoes; i++)
                    {
                        printf("\nID: %d\n", internacoes[i].id);
                        printf("Paciente ID: %d\n", internacoes[i].pacienteId);
                        printf("Ala ID: %d\n", internacoes[i].alaId);
                        printf("Leito ID: %d\n", internacoes[i].leitoId);
                        printf("Entrada: %s\n", internacoes[i].dataEntrada);
                        printf("Alta: %s\n", internacoes[i].dataAlta);
                        printf("Status: %s\n", internacoes[i].status);
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso6 != 0);

            break;
        }

        case 7:
        {
            int caso7;

            do
            {
                printf("\n=============================================\n");
                printf("MENU GERENCIAMENTO DE TRIAGEM\n");
                printf("=============================================\n");
                printf("1. Realizar Triagem\n");
                printf("2. Listar Triagens\n");
                printf("0. Voltar ao Menu Principal\n");
                printf("---------------------------------------------\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &caso7);

                switch (caso7)
                {
                case 1:
                {
                    int pacienteId;
                    int idadePaciente = 0;
                    int pacienteEncontrado = 0;

                    if (totalTriagens >= MAX_TRIAGENS)
                    {
                        printf("\nLimite de triagens atingido.\n");
                        break;
                    }

                    printf("\nID do paciente: ");
                    scanf("%d", &pacienteId);

                    for (int i = 0; i < totalPacientes; i++)
                    {
                        if (pacientes[i].id == pacienteId && pacientes[i].ativo == 1)
                        {
                            pacienteEncontrado = 1;
                            idadePaciente = pacientes[i].idade;
                            break;
                        }
                    }

                    if (pacienteEncontrado == 0)
                    {
                        printf("\nPaciente nao encontrado ou inativo.\n");
                        break;
                    }

                    triagens[totalTriagens].id = totalTriagens + 1;
                    triagens[totalTriagens].pacienteId = pacienteId;

                    printf("Febre? (1-Sim / 0-Nao): ");
                    scanf("%d", &triagens[totalTriagens].febre);

                    printf("Falta de ar? (1-Sim / 0-Nao): ");
                    scanf("%d", &triagens[totalTriagens].faltaAr);

                    printf("Dor intensa? (1-Sim / 0-Nao): ");
                    scanf("%d", &triagens[totalTriagens].dorIntensa);

                    printf("Pressao alta? (1-Sim / 0-Nao): ");
                    scanf("%d", &triagens[totalTriagens].pressaoAlta);

                    triagens[totalTriagens].pontuacao = 0;

                    if (triagens[totalTriagens].faltaAr == 1)
                        triagens[totalTriagens].pontuacao += 5;
                    if (triagens[totalTriagens].dorIntensa == 1)
                        triagens[totalTriagens].pontuacao += 4;
                    if (triagens[totalTriagens].febre == 1)
                        triagens[totalTriagens].pontuacao += 2;
                    if (triagens[totalTriagens].pressaoAlta == 1)
                        triagens[totalTriagens].pontuacao += 2;
                    if (idadePaciente >= 60 || idadePaciente <= 5)
                        triagens[totalTriagens].pontuacao += 2;

                    if (triagens[totalTriagens].pontuacao >= 8)
                        strcpy(triagens[totalTriagens].classificacao, "Emergencia");
                    else if (triagens[totalTriagens].pontuacao >= 5)
                        strcpy(triagens[totalTriagens].classificacao, "Muito prioritario");
                    else if (triagens[totalTriagens].pontuacao >= 3)
                        strcpy(triagens[totalTriagens].classificacao, "Prioritario");
                    else if (triagens[totalTriagens].pontuacao >= 1)
                        strcpy(triagens[totalTriagens].classificacao, "Comum");
                    else
                        strcpy(triagens[totalTriagens].classificacao, "Orientacao basica");

                    printf("\nTriagem registrada com sucesso.\n");
                    printf("Pontuacao: %d\n", triagens[totalTriagens].pontuacao);
                    printf("Classificacao: %s\n", triagens[totalTriagens].classificacao);

                    totalTriagens++;
                    break;
                }

                case 2:
                {
                    if (totalTriagens == 0)
                    {
                        printf("\nNenhuma triagem cadastrada.\n");
                        break;
                    }

                    printf("\nLista de Triagens:\n");

                    for (int i = 0; i < totalTriagens; i++)
                    {
                        printf("\nID: %d\n", triagens[i].id);
                        printf("Paciente ID: %d\n", triagens[i].pacienteId);
                        printf("Pontuacao: %d\n", triagens[i].pontuacao);
                        printf("Classificacao: %s\n", triagens[i].classificacao);
                    }

                    break;
                }

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.\n");
                    break;
                }

            } while (caso7 != 0);

            break;
        }
        case 8:
        {
            printf("\n=============================================\n");
            printf("RELATORIOS GERAIS\n");
            printf("=============================================\n");
            printf("Total de pacientes cadastrados: %d\n", totalPacientes);
            printf("Total de medicos cadastrados: %d\n", totalMedicos);
            printf("Total de agendamentos cadastrados: %d\n", totalAgendamentos);
            printf("Total de alas cadastradas: %d\n", totalAlas);
            printf("Total de leitos cadastrados: %d\n", totalLeitos);
            printf("Total de internacoes cadastradas: %d\n", totalInternacoes);
            printf("Total de triagens cadastradas: %d\n", totalTriagens);

            printf("\nLeitos ocupados por ala:\n");

            for (int i = 0; i < totalAlas; i++)
            {
                if (alas[i].ativo == 1)
                {
                    float taxa = 0;

                    if (alas[i].totalLeitos > 0)
                    {
                        taxa = (alas[i].leitosOcupados * 100.0) / alas[i].totalLeitos;
                    }

                    printf("\nAla: %s\n", alas[i].nome);
                    printf("Ocupados: %d/%d\n", alas[i].leitosOcupados, alas[i].totalLeitos);
                    printf("Taxa de ocupacao: %.2f%%\n", taxa);
                }
            }

            break;
        }
        case 0:
        {
            printf("\nEncerrando o SIGEH-DF...\n");
            break;
        }

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

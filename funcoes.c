#include "declaracoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

Aluno alunos[MAX_ALUNOS] = {0};
int dia, mes, ano, opcao,opcaog, matricula, cursos = 0, totalAlunos = 0, m = 1;
char materia[99],nome[50], solicitar_e[99], ADM[10] = "ridis", ADMS[10] = "123";
bool opcaoin2 = true, admin = false;
// main variaveis
int p=0,i=0,opc4,opp4,opf = 0,id_aluno;
char adn[8], ads[8];

void exibirAlunos() {
    setlocale(LC_ALL, "portuguese");
    if (id_aluno < 0 || id_aluno >= m || alunos[id_aluno].nome[0] == '\0') {
        printf("Aluno inválido ou não cadastrado.\n");
        Sleep(2000);
        system("cls");
        return;
    }

    printf("\nNome: %s", alunos[id_aluno].nome);
    printf("\nData de Nascimento: %s", alunos[id_aluno].DataNascimento);
    printf("\nEndereço: %s", alunos[id_aluno].endereco);
    printf("\nTelefone: %s", alunos[id_aluno].telefone);
    printf("\nCurso: %s", alunos[id_aluno].curso_do_aluno);
    printf("\nRA: %s", alunos[id_aluno].matricula);
    printf("\nTurma: %d", alunos[id_aluno].turma[0]); // Ajustado para turma[0]
    printf("\n>>Para Voltar [1]<<\n");

    int opea;
    scanf("%d", &opea);
    if (opea == 1) {
        system("cls");
    }
}

void ordenarAlunosPorNome() {
    setlocale(LC_ALL, "portuguese");
    if (m <= 0) {
        printf("Nenhum aluno cadastrado.\n");
        Sleep(2000);
        return;
    }

    Aluno temp;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

    printf("\nAlunos ordenados por nome:\n");
    for (int i = 0; i < m; i++) {
        if (alunos[i].nome[0] != '\0') {
            printf("Aluno[%d]: %s\n", i, alunos[i].nome);
        }
    }
    printf("\nPressione qualquer tecla para voltar...\n");
    getchar();
    scanf("%*c");
}

void adicionarmaterias(int i) {
    setlocale(LC_ALL, "portuguese");
    if (i < 0 || i >= MAX_ALUNOS || alunos[i].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        return;
    }

    if (strcmp(alunos[i].curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas") == 0) {
        strcpy(alunos[i].materias[0], "TC.TI = Lógica de Programação");
        strcpy(alunos[i].materias[1], "TC.TI = Eletro Eletrônica");
        strcpy(alunos[i].materias[2], "TC.TI = Idealização de Projetos");
    } else if (strcmp(alunos[i].curso_do_aluno, "[SOLD]Soldagem") == 0) {
        strcpy(alunos[i].materias[0], "SOLD = Introdução à Soldagem");
        strcpy(alunos[i].materias[1], "SOLD = Segurança na Soldagem");
        strcpy(alunos[i].materias[2], "SOLD = Leitura e Interpretação de Desenho Técnico");
    } else if (strcmp(alunos[i].curso_do_aluno, "[ELET.T]Eletrotecnico") == 0) {
        strcpy(alunos[i].materias[0], "ELET.T = Fundamentos de Eletricidade");
        strcpy(alunos[i].materias[1], "ELET.T = Segurança em Instalações Elétricas");
        strcpy(alunos[i].materias[2], "ELET.T = Eletrônica Básica");
    } else if (strcmp(alunos[i].curso_do_aluno, "[MECA]Mecatrônica") == 0) {
        strcpy(alunos[i].materias[0], "MECA = Segurança do Trabalho");
        strcpy(alunos[i].materias[1], "MECA = Fundamentos de Automação Industrial");
        strcpy(alunos[i].materias[2], "MECA = Uso de EPIs e EPCs");
    } else {
        printf("Curso selecionado não corresponde.\n");
    }
}

float calcularnotas(int aluno_idx) {
    setlocale(LC_ALL, "portuguese");
    if (aluno_idx < 0 || aluno_idx >= m || alunos[aluno_idx].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        return 0.0;
    }

    // Inicializar notas apenas uma vez, se necessário
    if (alunos[aluno_idx].notas[0] == 0 && alunos[aluno_idx].notas[1] == 0 && alunos[aluno_idx].notas[2] == 0) {
        alunos[aluno_idx].notas[0] = rand() % 11;
        alunos[aluno_idx].notas[1] = rand() % 11;
        alunos[aluno_idx].notas[2] = rand() % 11;
    }

    float nota1 = alunos[aluno_idx].notas[0];
    float nota2 = alunos[aluno_idx].notas[1];
    float nota3 = alunos[aluno_idx].notas[2];
    return (nota1 + nota2 + nota3) / 3.0;
}

void lancar_notas() {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    if (m <= 0) {
        printf("É necessário pelo menos um aluno cadastrado.\n");
        Sleep(2000);
        return;
    }

    printf("De qual aluno deseja lançar notas? Digite o número correspondente:\n");
    for (int i = 0; i < m; i++) {
        printf("Aluno[%d]: %s\n", i, alunos[i].nome);
    }
    int opc;
    scanf("%d", &opc);
    if (opc < 0 || opc >= m || alunos[opc].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        Sleep(2000);
        return;
    }

    printf("Digite a Nota 1: ");
    scanf("%f", &alunos[opc].notas[0]);
    printf("Digite a Nota 2: ");
    scanf("%f", &alunos[opc].notas[1]);
    printf("Digite a Nota 3: ");
    scanf("%f", &alunos[opc].notas[2]);
    printf("Notas lançadas com sucesso.\n");
    Sleep(2000);
    system("cls");
}

void vernotas() {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    if (id_aluno < 0 || id_aluno >= m || alunos[id_aluno].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        Sleep(2000);
        return;
    }

    float media = calcularnotas(id_aluno);
    printf("------NOTAS------\n");
    printf("%s\n\n", alunos[id_aluno].curso_do_aluno);
    printf("Em: %s no Módulo 1 sua nota foi: %.2f\n", alunos[id_aluno].materias[0], alunos[id_aluno].notas[0]);
    printf("Em: %s no Módulo 2 sua nota foi: %.2f\n", alunos[id_aluno].materias[1], alunos[id_aluno].notas[1]);
    printf("Em: %s no Módulo 3 sua nota foi: %.2f\n", alunos[id_aluno].materias[2], alunos[id_aluno].notas[2]);

    if (media >= 7.0) {
        printf("\nSua média foi: %.2f. Parabéns! Você foi aprovado.\n", media);
    } else if (media >= 5.0) {
        printf("\nSua média foi: %.2f. Você está em recuperação. A data para reavaliação será 03/10/2025.\n", media);
    } else {
        printf("\nSua média foi: %.2f. Você reprovou. Contate a secretaria.\n", media);
    }

    printf(">>Pressione [1] para voltar<<\n");
    int option_extra;
    scanf("%d", &option_extra);
    if (option_extra == 1) {
        system("cls");
    }
}

void cadastro() {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    if (admin == true) {
        printf("Quantos alunos deseja cadastrar? (Máximo %d): ", MAX_ALUNOS - m);
        scanf("%d", &m);
        if (m <= 0 || m + totalAlunos > MAX_ALUNOS) {
            printf("Número de alunos inválido ou excede o limite.\n");
            Sleep(2000);
            system("cls");
            return;
        }
    } else {
        m = 1; // Cadastra apenas 1 aluno se não for admin
    }

    for (int i = 0; i < m; i++) {
        char nome_arquivo[100];
        system("cls");
        printf("\nAluno [%d]\n", i);
        id_aluno = i + totalAlunos;

        printf("Digite o nome completo: ");
        getchar(); // Limpar buffer
        fgets(alunos[id_aluno].nome, sizeof(alunos[id_aluno].nome), stdin);
        alunos[id_aluno].nome[strcspn(alunos[id_aluno].nome, "\n")] = 0;

        snprintf(nome_arquivo, sizeof(nome_arquivo), "%s.txt", alunos[id_aluno].nome);
        FILE *arquivo = fopen(nome_arquivo, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s\n", nome_arquivo);
            continue;
        }
        fprintf(arquivo, "Nome: %s\n", alunos[id_aluno].nome);

        printf("Digite a senha: ");
        fgets(alunos[id_aluno].senha, sizeof(alunos[id_aluno].senha), stdin);
        alunos[id_aluno].senha[strcspn(alunos[id_aluno].senha, "\n")] = 0;
        fprintf(arquivo, "Senha: %s\n", alunos[id_aluno].senha);

        printf("Digite o endereço: ");
        fgets(alunos[id_aluno].endereco, sizeof(alunos[id_aluno].endereco), stdin);
        alunos[id_aluno].endereco[strcspn(alunos[id_aluno].endereco, "\n")] = 0;
        fprintf(arquivo, "Endereço: %s\n", alunos[id_aluno].endereco);

        printf("Digite o telefone: ");
        fgets(alunos[id_aluno].telefone, sizeof(alunos[id_aluno].telefone), stdin);
        alunos[id_aluno].telefone[strcspn(alunos[id_aluno].telefone, "\n")] = 0;
        fprintf(arquivo, "Telefone: %s\n", alunos[id_aluno].telefone);

        printf("Digite a data de nascimento\n");
        printf("Dia: ");
        scanf("%d", &dia);
        printf("Mês: ");
        scanf("%d", &mes);
        printf("Ano: ");
        scanf("%d", &ano);
        snprintf(alunos[id_aluno].DataNascimento, sizeof(alunos[id_aluno].DataNascimento), "%02d.%02d.%04d", dia, mes, ano);
        fprintf(arquivo, "Data de Nascimento: %s\n", alunos[id_aluno].DataNascimento);

        system("cls");
        printf("Escolha um curso\n");
        printf("-----------------------\n");
        printf("CURSOS DISPONÍVEIS\n");
        printf("-----------------------\n");
        int opf = 0;
        do {
            printf("\n1 = Desenvolvimento de Sistemas\n2 = Soldagem\n3 = Eletrotécnico\n4 = Mecatrônica\n");
            scanf("%d", &cursos);
            switch (cursos) {
                case 1:
                    strcpy(alunos[id_aluno].curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas");
                    opf = 1;
                    break;
                case 2:
                    strcpy(alunos[id_aluno].curso_do_aluno, "[SOLD]Soldagem");
                    opf = 1;
                    break;
                case 3:
                    strcpy(alunos[id_aluno].curso_do_aluno, "[ELET.T]Eletrotécnico");
                    opf = 1;
                    break;
                case 4:
                    strcpy(alunos[id_aluno].curso_do_aluno, "[MECA]Mecatrônica");
                    opf = 1;
                    break;
                default:
                    printf("\n>>Opção inválida<<\n");
                    Sleep(1000);
                    break;
            }
        } while (opf == 0);
        adicionarmaterias(id_aluno);

        for (int j = 0; j < 3; j++) {
            fprintf(arquivo, "Matéria %d: %s\n", j + 1, alunos[id_aluno].materias[j]);
        }

        char uni[10];
        srand(time(NULL));
        int num1 = rand() % 1000;
        int num2 = (rand() % 9000) + 1000;
        snprintf(uni, sizeof(uni), "%d.%d", num1, num2);
        strncpy(alunos[id_aluno].matricula, uni, sizeof(alunos[id_aluno].matricula));
        fprintf(arquivo, "Matrícula: %s\n", alunos[id_aluno].matricula);
        alunos[id_aluno].turma[0] = rand() % 999;
        fprintf(arquivo, "Turma: %d\n", alunos[id_aluno].turma[0]);
        fprintf(arquivo, "Curso: %s\n", alunos[id_aluno].curso_do_aluno);
        fclose(arquivo);
    }
    totalAlunos += m;
    system("cls");
}

void editarcadastro(int alunes) {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    if (alunes < 0 || alunes >= m || alunos[alunes].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        Sleep(2000);
        return;
    }

    int op_e = 0;
    do {
        printf("|||Para editar o cadastro escolha a opção que deseja editar|||\n");
        printf("[1] Nome || [2] Senha || [3] Endereço || [4] Telefone || [5] Data de Nascimento || [6] Voltar\n");
        scanf("%d", &op_e);
        getchar(); // Limpar buffer
        switch (op_e) {
            case 1:
                system("cls");
                printf("Seu nome atual: %s\n", alunos[alunes].nome);
                printf("Digite o novo nome: ");
                fgets(alunos[alunes].nome, sizeof(alunos[alunes].nome), stdin);
                alunos[alunes].nome[strcspn(alunos[alunes].nome, "\n")] = 0;
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Digite a nova senha: ");
                fgets(alunos[alunes].senha, sizeof(alunos[alunes].senha), stdin);
                alunos[alunes].senha[strcspn(alunos[alunes].senha, "\n")] = 0;
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Seu endereço atual: %s\n", alunos[alunes].endereco);
                printf("Digite o novo endereço: ");
                fgets(alunos[alunes].endereco, sizeof(alunos[alunes].endereco), stdin);
                alunos[alunes].endereco[strcspn(alunos[alunes].endereco, "\n")] = 0;
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Seu telefone atual: %s\n", alunos[alunes].telefone);
                printf("Digite o novo telefone: ");
                fgets(alunos[alunes].telefone, sizeof(alunos[alunes].telefone), stdin);
                alunos[alunes].telefone[strcspn(alunos[alunes].telefone, "\n")] = 0;
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Sua data de nascimento atual: %s\n", alunos[alunes].DataNascimento);
                printf("Digite a nova data de nascimento\n");
                printf("Dia: ");
                scanf("%d", &dia);
                printf("Mês: ");
                scanf("%d", &mes);
                printf("Ano: ");
                scanf("%d", &ano);
                snprintf(alunos[alunes].DataNascimento, sizeof(alunos[alunes].DataNascimento), "%02d.%02d.%04d", dia, mes, ano);
                system("cls");
                break;
            case 6:
                system("cls");
                op_e = 0;
                break;
            default:
                printf("Opção inválida.\n");
                Sleep(1000);
                break;
        }
    } while (op_e != 0);
}

void suporte() {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    if (id_aluno < 0 || id_aluno >= m || alunos[id_aluno].nome[0] == '\0') {
        printf("Aluno inválido.\n");
        Sleep(2000);
        return;
    }

    int ops1 = 0;
    do {
        printf("||||||| Bem-vindo ao SUPORTE |||||||\n\n");
        printf("[1] Solicitar mudança de turma\n[2] Solicitar cancelamento de matrícula\n[3] Solicitar mudança de curso\n[4] Outros\n[5] Voltar\n");
        scanf("%d", &ops1);
        switch (ops1) {
            case 1:
                system("cls");
                printf("Sua turma atual: %d\n", alunos[id_aluno].turma[0]);
                printf("[Escolha uma das turmas disponíveis]\n");
                int turmas[4];
                for (int i = 0; i < 4; i++) {
                    turmas[i] = rand() % 999;
                    printf("Turma %d: %d\n", i, turmas[i]);
                }
                int turmaescolhida;
                scanf("%d", &turmaescolhida);
                alunos[id_aluno].turma[0] = turmas[turmaescolhida];
                printf("Mudança de turma solicitada.\n");
                Sleep(2000);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Para solicitar o cancelamento de matrícula, digite sua senha: ");
                char tempsenha[99];
                scanf("%s", tempsenha);
                if (strcmp(alunos[id_aluno].senha, tempsenha) == 0) {
                    printf("Cancelamento de matrícula solicitado.\n");
                    Sleep(2000);
                    system("cls");
                } else {
                    printf("Senha incorreta. Tente novamente.\n");
                    Sleep(2000);
                    system("cls");
                }
                break;
            case 3:
                system("cls");
                printf("Tem certeza que deseja mudar de curso? [1] Sim [2] Não\n");
                int mudar;
                scanf("%d", &mudar);
                if (mudar == 1) {
                    printf("A mudança de curso só pode ser feita pela administração.\n");
                    printf("Sua solicitação foi registrada com prazo de 3 dias úteis.\n");
                    Sleep(4000);
                    system("cls");
                } else {
                    printf("Mudança cancelada.\n");
                    Sleep(2000);
                    system("cls");
                }
                break;
            case 4:
                system("cls");
                printf("Digite sua solicitação (seja breve): ");
                getchar();
                fgets(solicitar_e, sizeof(solicitar_e), stdin);
                solicitar_e[strcspn(solicitar_e, "\n")] = 0;
                printf("Solicitação registrada: %s\n", solicitar_e);
                Sleep(2000);
                system("cls");
                break;
            case 5:
                system("cls");
                ops1 = 0;
                break;
            default:
                printf("Opção inválida.\n");
                Sleep(1000);
                break;
        }
    } while (ops1 != 0);
}

void limparBuffer() {
	setlocale(LC_ALL, "portuguese");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include "declaracoes.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); // Inicializar gerador de números aleatórios

    int opcaoin = 0;
    char op_cadastro[2];

    do {
        while (opcaoin == 0) {
            printf("\n========== MENU ESCOLA ==========\n");
            printf("Opção desejada?\n >>[C]Cadastro<< || >>[L]Login<< || >>[A]ADM\n");
            fgets(op_cadastro, sizeof(op_cadastro), stdin);
            op_cadastro[strcspn(op_cadastro, "\n")] = 0;

            switch (op_cadastro[0]) {
                case 'l':
                case 'L':
                    printf("Por favor, use [C] para cadastro ou [A] para ADM.\n");
                    Sleep(2000);
                    system("cls");
                    break;
                case 'c':
                case 'C':
                    cadastro();
                    opcaoin = 1;
                    Sleep(40);
                    break;
                case 'a':
                case 'A':
                    system("cls");
                    printf("Login Administrador\n");
                    printf("Digite o Nome: ");
                    fgets(adn, sizeof(adn), stdin);
                    adn[strcspn(adn, "\n")] = 0;
                    printf("Digite a Senha: ");
                    fgets(ads, sizeof(ads), stdin);
                    ads[strcspn(ads, "\n")] = 0;
                    if (strcmp(adn, ADM) == 0 && strcmp(ads, ADMS) == 0) {
                        opcaoin = 1;
                        admin = true;
                    } else {
                        printf("Nome ou senha incorretos.\n");
                        Sleep(2000);
                        system("cls");
                        opcaoin = 0;
                    }
                    break;
                default:
                    printf("Opção inválida. Tente novamente.\n");
                    Sleep(2000);
                    system("cls");
                    break;
            }
        }

        if (admin == false) {
            system("cls");
            printf("----------------Portal do Aluno----------------\n\n");
            printf("[1] Notas\n");
            printf("[2] Ver Cadastro\n");
            printf("[3] Editar Cadastro\n");
            printf("[4] Suporte\n");
            printf("[5] Sair\n");
            printf("[6] Fechar\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            limparBuffer();

            switch (opcao) {
                case 1:
                    if (id_aluno >= 0 && id_aluno < m && alunos[id_aluno].nome[0] != '\0') {
                        vernotas();
                    } else {
                        printf("Nenhum aluno selecionado.\n");
                        Sleep(2000);
                        system("cls");
                    }
                    break;
                case 2:
                    if (id_aluno >= 0 && id_aluno < m && alunos[id_aluno].nome[0] != '\0') {
                        exibirAlunos();
                    } else {
                        printf("Nenhum aluno selecionado.\n");
                        Sleep(2000);
                        system("cls");
                    }
                    break;
                case 3:
                    if (id_aluno >= 0 && id_aluno < m && alunos[id_aluno].nome[0] != '\0') {
                        editarcadastro(id_aluno);
                    } else {
                        printf("Nenhum aluno selecionado.\n");
                        Sleep(2000);
                        system("cls");
                    }
                    break;
                case 4:
                    if (id_aluno >= 0 && id_aluno < m && alunos[id_aluno].nome[0] != '\0') {
                        suporte();
                    } else {
                        printf("Nenhum aluno selecionado.\n");
                        Sleep(2000);
                        system("cls");
                    }
                    break;
                case 5:
                    system("cls");
                    opcaoin = 0;
                    break;
                case 6:
                    printf("Encerrando o programa...\n");
                    Sleep(1000);
                    opc4 = 5;
                    break;
                default:
                    printf("Opção inválida.\n");
                    Sleep(1000);
                    system("cls");
                    break;
            }
        } else {
            system("cls");
            printf("----------------Portal do Administrador---------------\n\n");
            printf("[1] Lançar Notas\n");
            printf("[2] Cadastrar Alunos\n");
            printf("[3] Editar Cadastros\n");
            printf("[4] Listar Alunos\n");
            printf("[5] Sair\n");
            printf("[6] Fechar\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            limparBuffer();

            switch (opcao) {
                case 1:
                    lancar_notas();
                    break;
                case 2:
                    cadastro();
                    break;
                case 3:
                    if (m <= 0) {
                        printf("É necessário pelo menos um aluno cadastrado.\n");
                        Sleep(2000);
                        system("cls");
                    } else {
                        printf("De qual aluno deseja editar o cadastro? Digite o número correspondente:\n");
                        for (int i = 0; i < m; i++) {
                            printf("Aluno[%d]: %s\n", i, alunos[i].nome);
                        }
                        scanf("%d", &p);
                        limparBuffer();
                        if (p >= 0 && p < m && alunos[p].nome[0] != '\0') {
                            editarcadastro(p);
                        } else {
                            printf("Aluno inválido.\n");
                            Sleep(2000);
                            system("cls");
                        }
                    }
                    break;
                case 4:
                    if (m <= 0) {
                        printf("É necessário pelo menos um aluno cadastrado.\n");
                        Sleep(2000);
                        system("cls");
                    } else {
                        ordenarAlunosPorNome();
                        Sleep(5000);
                        system("cls");
                    }
                    break;
                case 5:
                    system("cls");
                    opcaoin = 0;
                    admin = false;
                    break;
                case 6:
                    printf("Encerrando o programa...\n");
                    Sleep(1000);
                    opc4 = 5;
                    break;
                default:
                    printf("Opção inválida.\n");
                    Sleep(1000);
                    system("cls");
                    break;
            }
        }
    } while (opc4 != 5);

    return 0;
}

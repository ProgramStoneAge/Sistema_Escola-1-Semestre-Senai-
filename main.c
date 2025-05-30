main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include "declaracoes.h"

int main(){
    setlocale(LC_CTYPE, "portuguese");
    int opcaoin = 0;
    char op_cadastro;
    do{
        while (opcaoin == 0)
        {                    
            printf("\n========== MENU ESCOLA ==========\n");
            printf("Op?ão Desejada?\n >>[C]Cadastro<< || >>Login<< || >>[A]ADM\n");
            op_cadastro = getchar();
            switch (op_cadastro)
            {
                case 'l':
                    printf("Op��o Secreta Ativada..\nAutoDestrui��o do Pc Inciada...");
                    Sleep(4000);
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
                    scanf("%s",adn);
                    printf("Digite A Senha: ");
                    scanf("%s",ads);
                    if(strcmp(adn, ADM) == 0 && strcmp(ads, ADMS) == 0){
                        opcaoin = 1;
                        admin = true;
                    }
                    else{
                        opcaoin = 0;
                    }
                break;
                default:
                    system("cls");
                break;
            }
        }
        if(admin == false){
        	system("cls");
            printf("----------------Portal Do Aluno----------------\n\n");
            printf("[1] ||Notas||\n");
            printf("[2] ||Ver Cadastro||\n");
            printf("[3] ||Editar Cadastro||\n");
            printf("[4] ||Suporte||\n");
            printf("[5] ||SAIR||\n");
            printf("[6] ||FECHAR||\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
        }
        else if(admin == true){
            system("cls");
            printf("----------------Portal Do Administrador---------------\n\n");
            printf("[1] ||Lan�ar Notas||\n"); 
            printf("[2] ||Cadastrar Alunos||\n");
            printf("[3] ||Editar Cadastros||\n");
            printf("[4] ||Listar Alunos||\n");
            printf("[5] ||SAIR||\n"); 
            printf("[6] ||FECHAR||\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
        }
        switch (opcao) {
                case 1:
                    if(admin == false){
                        vernotas();
                    }
                    else{
                        lancar_notas();
                    }
                    break;

                case 2:
                    if(admin == false){                   
                        system("cls");
                        do{
                            exibirAlunos();
                        }
                        while (opcaoin2 == true);
                    }
                    else
                    {
                        cadastro();
                    }
                    break;

                case 3:
                    if(admin == false){
                        editarcadastro(p);
                    }
                    else{
                        if(alunos[0].nome[0] == '\0'){
                            printf("� Necessario Mais de um aluno para isto");
                            Sleep(4000);
                        }
                        else{                          
                            printf("De Qual Aluno Deseja Editar Cadastro? Digite o Numero Correspondente\n");
                            for(i; i < m; i++){
                                printf("\nAluno[%d]: %s",i,alunos[i].nome);
                            }
                            printf("\n");
                            scanf("%d",&p);
                            editarcadastro(p);
                        }
                    }
                    break;
                case 4:
                    if(admin == false){
                        suporte();
                    }
                    else{
                        if(alunos[0].nome[0] == '\0'){
                            printf("� Necessario Mais de um aluno para isto");
                            Sleep(4000);
                        }
                        else{
                            system("cls");
                            ordenarAlunosPorNome();
                            Sleep(5000);
                        }
                    }
                    break;
                case 5:
                    system("cls");
                    opcaoin = 0;
                    limparBuffer();
                    break;
                case 6:
                    opc4 = 5;
                    break;
                default:
                    printf("Op��o Invalida");
                break;
        }
    }while (opc4 != 5);
    return 0;
}
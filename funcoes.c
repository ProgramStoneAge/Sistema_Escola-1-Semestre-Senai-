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

void exibirAlunos(){
	setlocale(LC_ALL, "portuguese");
    int opea = 0;
    printf("\nNome: %s",alunos[id_aluno].nome);
    printf("\nData De Nascimento: %s",alunos->DataNascimento);   
    printf("\nEndere?o: %s",alunos->endereco);   
    printf("\nTelefone: %s",alunos->telefone);   
    printf("\nCurso: %s",alunos->curso_do_aluno);   
    printf("\nRA: %s",alunos->matricula);
    printf("\nTurma: %d",alunos[id_aluno].turma[1]);
    printf("\n>>Para Voltar[1]<<\n");
    scanf("%d",&opea);
    if(opea == 1){
        opcaoin2 = false;
        system("cls");
    }
}

void ordenarAlunosPorNome() {
	setlocale(LC_ALL, "portuguese");
    Aluno temp;
    int i, j;

    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

    printf("\nAlunos ordenados por nome:\n");
    for (i = 0; i < m; i++) {
        printf("Aluno[%d]: %s\n", i, alunos[i].nome);
    }
}

void adicionarmaterias(int i) {
	setlocale(LC_ALL, "portuguese");
    if (strcmp(alunos[i].curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas") == 0) {
        strcpy(alunos[i].materias[1], "TC.TI = Logica de Programa  o");
        strcpy(alunos[i].materias[2], "TC.TI = Eletro Eletronica");
        strcpy(alunos[i].materias[3], "TC.TI = Idealiza  o De Projetos");
    } else if (strcmp(alunos[i].curso_do_aluno, "[SOLD]Soldagem") == 0) {
        strcpy(alunos[i].materias[1], "SOLD = Introdu  o a Soldagem");
        strcpy(alunos[i].materias[2], "SOLD = Seguran a na Soldagem");
        strcpy(alunos[i].materias[3], "SOLD = Leitura e Interpreta  o de Desenho T cnico");
    } else if (strcmp(alunos[i].curso_do_aluno, "[ELET.T]Eletrotecnico") == 0) {
        strcpy(alunos[i].materias[1], "ELET.T = Fundamentos de Eletricidade");
        strcpy(alunos[i].materias[2], "ELET.T = Seguran a em Instala  es El tricas");
        strcpy(alunos[i].materias[3], "ELET.T = Eletr nica B sica");
    } else if (strcmp(alunos[i].curso_do_aluno, "[MECA]Mecatr nica") == 0) {
        strcpy(alunos[i].materias[1], "MECA = Seguran a do Trabalho");
        strcpy(alunos[i].materias[2], "MECA = Fundamentos de Automa  o Industrial");
        strcpy(alunos[i].materias[3], "MECA = Uso de EPIs e EPCs");
    } else {
        printf("Curso Selecionado n o corresponde\n");
    }
}

float calcularnotas(){
	setlocale(LC_ALL, "portuguese");
    float clc = 0;
    srand(time(NULL));
    if(alunos[8].notas[1] == 0){
        alunos[8].notas[1] = rand() % 11;
        alunos[8].notas[2] = rand() % 11;
        alunos[8].notas[3] = rand() % 11;
    }
    float nota1 = alunos[8].notas[1];
    float nota2 = alunos[8].notas[2];
    float nota3 = alunos[8].notas[3];
    clc = (nota1 + nota2 + nota3) /3;
    return clc;
}

void lancar_notas(){
	setlocale(LC_ALL, "portuguese");
    system("cls");
    int opc = 0;
    int i = 0;
    if(alunos[0].nome[0] == '\0'){
        printf("? Necess rio Mais de um aluno para isto");
        Sleep(4000);
    }
    else{
        printf("De Qual Aluno Deseja Lan ar Notas? Digite o Numero Correspondente\n");
        for(i; i < m; i++){
            printf("\nAluno[%d]: %s",i,alunos[i].nome);
        }
        printf("\n");
        scanf("%d",&opc);
        printf("\nDigite a Nota 1: ");
        scanf("%f",&alunos[opc].notas[1]);
        printf("\nDigite a Nota 2: ");
        scanf("%f",&alunos[opc].notas[2]);
        printf("\nDigite a Nota 3: ");
        scanf("%f",&alunos[opc].notas[3]);
    }
}

void vernotas(){
	setlocale(LC_ALL, "portuguese");
    system("cls");
    float clc2 = calcularnotas();
    int option_extra = 0;
    do{
        printf("------NOTAS------\n");
        printf("%s\n\n",alunos->curso_do_aluno);
        printf("Em: %s no M dulo 1 sua nota foi: %.2f\n",alunos->materias[1], alunos[8].notas[1]);
        printf("Em: %s no M dulo 2 sua nota foi: %.2f\n",alunos->materias[2], alunos[8].notas[2]);
        printf("Em: %s no M dulo 3 sua nota foi: %.2f\n",alunos->materias[3], alunos[8].notas[3]);
        if(clc2 >= 7.0){
            printf("\nSua M dia foi: %.2f Parabens! Voce Foi Aprovado\n",clc2);
        }
        else if(clc2 >= 5.0){
            printf("\nSua M dia foi: %.2f Voc  est  em Recupera  o, a data para a reavalia  o ser? 03/10/2025\n",clc2);
        }
        else{
            printf("\nSua M dia foi: %.2f Voc  Reprovou, Contate A Secretaria\n",clc2);
        }
        printf(">>Pessione [1] Para Voltar<<\n");
        scanf("%d",&option_extra);
        if(option_extra == 1){
            option_extra = 1;
            system("cls");
        }
    }while (option_extra == 0);
}

void cadastro(){
	setlocale(LC_ALL, "portuguese");
    int i = 0,j = 0;
    if(admin == true){
        system("cls");
        printf("Quantos Alunos Deseja Cadastrar?: ");
        scanf("%d",&m);
    }
    for(i = 0; i < m; i++){
    	char nome_arquivo[100];
        char nome_base[50];

        int opf = 0;
        char dtn[99];
        if(admin == true){
            printf("\nAluno [%d]\n",i);
        }
        getchar();
        id_aluno = i;

        printf("Digite O Nome Completo: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;
        
        strcpy(nome_base, alunos[i].nome);
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%s.txt", nome_base);

        FILE *arquivo = fopen(nome_arquivo, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s\n", nome_arquivo);
            continue;
        }
        fprintf(arquivo,"Nome: %s\n",alunos[i].nome);

        printf("\nDigite A Senha: " );
        fgets(alunos[i].senha, sizeof(alunos[i].senha), stdin);
        alunos[i].senha[strcspn(alunos[i].senha, "\n")] = 0;
        fprintf(arquivo, "Senha: %s\n", alunos[i].senha);

        printf("\nDigite O Endere o: ");
        fgets(alunos[i].endereco, sizeof(alunos[i].endereco), stdin);
        alunos[i].endereco[strcspn(alunos[i].endereco, "\n")] = 0;
        fprintf(arquivo, "Endereco: %s\n", alunos[i].endereco);

        printf("\nDigite O Telefone: ");
        fgets(alunos[i].telefone, sizeof(alunos[i].telefone), stdin);
        alunos[i].telefone[strcspn(alunos[i].telefone, "\n")] = 0;
        fprintf(arquivo, "Telefone: %s\n", alunos[i].telefone);
        char buf[16];

        printf("Digite sua Data de Nascimento\n");

        printf("Dia: ");
        if (fgets(buf, sizeof(buf), stdin) == NULL || sscanf(buf, "%d", &dia) != 1) {
            printf("Entrada inv lida para o dia.\n");
            fclose(arquivo);
            continue;
        }

        printf("M s: ");
        if (fgets(buf, sizeof(buf), stdin) == NULL || sscanf(buf, "%d", &mes) != 1) {
            printf("Entrada inv lida para o m s.\n");
            fclose(arquivo);
            continue;
        }

        printf("Ano: ");
        if (fgets(buf, sizeof(buf), stdin) == NULL || sscanf(buf, "%d", &ano) != 1) {
            printf("Entrada inv lida para o ano.\n");
            fclose(arquivo);
            continue;
        }
        
        snprintf(dtn, sizeof(dtn), "%02d.%02d.%04d", dia, mes, ano);
        strcpy(alunos[i].DataNascimento, dtn);

        fprintf(arquivo, "Data de Nascimento: %s\n", dtn);

        system("cls");
        printf("Escolha um Curso\n");
        printf("-----------------------");
        printf("\nCURSOS DISPONIVEIS\n");
        printf("-----------------------\n");
        do{
            printf("\n1 = Desenvolvimento de sistmeas\n2 = Soldagem\n3 = Eletrotecnico\n4 = Mecatr nica\n");
            scanf("%d",&cursos);
            switch (cursos)
            {
            case 1:
                strcpy(alunos[i].curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas");
                opf = 1;
                system("cls");
                break;
            case 2:
                strcpy(alunos[i].curso_do_aluno, "[SOLD]Soldagem");
                opf = 1;
                system("cls");
                break;
            case 3:
                strcpy(alunos[i].curso_do_aluno, "[ELET.T]Eletrotecnico");
                opf = 1;
                system("cls");
                break;
            case 4:
                strcpy(alunos[i].curso_do_aluno, "[MECA]Mecatr nica");
                opf = 1;
                system("cls");
            default:
                printf("\n>>Op  o Inv lida<<\n");
                Sleep(4);
                opf = 0;
                break;
            }
        }while(opf == 0);
        adicionarmaterias(i);

        for (j = 0; j < 3; j++) {
            fprintf(arquivo, "Mat ria %d: %s\n", j+1, alunos[i].materias[j+1]);
        }

        int num1,num2;
        char uni[10];
        srand(time(NULL));
        num1 = rand() % 1000;
        num2 = (rand() % 9000) + 1000;
        snprintf(uni, sizeof(uni), "%d.%d", num1, num2);
        strncpy(alunos[i].matricula, uni, sizeof(alunos[i].matricula));
        fprintf(arquivo, "Matr cula: %s\n", alunos[i].matricula);
        alunos[i].turma[1] = rand() % 999;
        
        fprintf(arquivo, "Turma: %d\n", alunos[i].turma);
        fprintf(arquivo, "Curso: %s\n", alunos[i].curso_do_aluno);
        fclose(arquivo);
    }
}

void editarcadastro(int alunes){
	setlocale(LC_ALL, "portuguese");
    system("cls");
    int op_e = 0,op_e2 = 0,op_e3 = 0,op_e4 = 0, i;
    int dia1,mes2,ano3,dtn;
    do{
        do{
            printf("|||Para editar o cadastro escolha a op  o que deseja editar|||\n");
            printf("[1]Nome || [2]Senha || [3]Endere o || [4]Telefone || [5]Data de Nascimento || [6]Voltar\n");
            scanf("%d",&op_e2);
            switch (op_e2)
            {
            case 1:
                system("cls" );
                printf("Seu nome atual ?: %s\n",alunos[alunes].nome);
                printf("Digite o novo Nome: ");
                scanf("%s",alunos[alunes].nome);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Digite a nova Senha: ");
                scanf("%s",alunos[alunes].senha);
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Seu Endere o atual ?: %s\n",alunos[alunes].endereco);
                printf("Digite o novo Endere o: ");
                scanf("%s",alunos[alunes].endereco);
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Seu Telefone atual ?: %s\n",alunos[alunes].telefone);
                printf("Digite o novo Telefone: ");
                scanf("%s",alunos[alunes].nome);
                system("cls"); 
                break;
            case 5:
                system("cls");
                printf("Sua Data De Nascimento atual ?: %s\n",alunos[alunes].DataNascimento);
                printf("\nDigite A Data de Nascimento\n");
                printf("Dia: ");
                scanf("%d",&dia1);
                printf("\nM s: ");
                scanf("%d",&mes2);
                printf("\nAno: ");
                scanf("%d",&ano3);
                char dtn[20];
                snprintf(dtn, sizeof(dtn), "%d.%d.%d", dia1, mes2, ano3);
                strncpy(alunos[alunes].DataNascimento, dtn, sizeof(alunos[alunes].DataNascimento));
                system("cls");
                break;
            case 6:
                system("cls");
                op_e3 = 1;
                op_e = 1;
                break;
            default:
                printf("\n\nOp  o Escolhida ? Inv lida");
                break;
            }
        }while (op_e3 == 0);
    }while (op_e == 0);
}

void suporte(){
	setlocale(LC_ALL, "portuguese");
    system("cls");
    int op = 0,ops1 = 0,i = 0,turmaescolhida,mudar;
    int turmas[5];
    char tempsenha[99];
    int tmptmp = 0;
    do{
        printf("||||||| Bem vindo ao >SUPORTE< |||||||\n\n");
        printf("[1]Solicitar Mudan a de Turma\n[2] Solicitar Cancelamento de Matricula\n[3]Solicitar Mundan a de Curso\n[4]Outros\n[5]Voltar\n");       
        scanf("%d",&ops1);
        switch (ops1)
        {
        case 1:
            system("cls");
            printf("Sua Turma Atual ?: %d\n",alunos[9].turma[1]);
            printf("[Escolha uma das Turmas Disponiveis]\n");
            srand(time(NULL));
            for(i; i < 4; i++){              
                turmas[i] = rand() % 999;
                printf("Turma %d: %d\n",i,turmas[i]);
            }
            scanf("%d",&turmaescolhida);
            alunos[9].turma[1] = turmaescolhida;
            system("cls");
            break;
        
        case 2:
            system("cls");
            printf("Para Solicitar o Cancelamento de Matr cula Digite Sua Senha: ");
            scanf("%s",&tempsenha);
            if(strcmp(alunos->senha, tempsenha) == 0){
                strcpy(alunos->senha, tempsenha);
                tmptmp = 1;
                system("cls");
            }
            else{
                system("cls");
                printf("Senha Digitada Est  Incorreta, Tente Novamente em 4 Segundos");
                Sleep(4000);
                system("cls");
            }
            break;
        case 3:
            system("cls");
            printf("Tem Certeza que Deseja Mudar de Curso? [1]Sim [2]N o\n");
            scanf("%d",&mudar);
            if(mudar == 1){
                system("cls");
                printf("\nA Mudan a de Curso s  Pode Ser Feita Pela Administra  o\nSua Solicita oo Foi Guardada com um Prazo de 3 dias  teis Para ser Validada");
                Sleep(4000);
                system("cls");
            }
            else{
                printf("\nMudan a Cancelada");
            }
        break;
        case 4:
            system("cls");
            printf("Caso Tenha outra D vida ou Solicita  o Digite aqui (Seja Breve)\n");
            scanf("%s",&solicitar_e);
            system("cls");
            break;
        case 5:
            system("cls");
            op = 1;
        default:
            break;
        }
    }while(op == 0);
}

void limparBuffer() {
	setlocale(LC_ALL, "portuguese");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

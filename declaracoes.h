#ifndef declaracoes_h
#define declaracoes_h
#define MAX_ALUNOS 100
#include <stdbool.h>

// Inteiros
extern int dia, mes, ano, opcao,opcaog, matricula, cursos, totalAlunos, m;
// Def Temporaria
extern char materia[99],nome[50], solicitar_e[99], ADM[10], ADMS[10];
// Boleanas para condicionas
extern bool opcaoin2, admin;
// variaveis que estao dentro do main
extern int p,i,opc4,opp4,opf;
extern char adn[8], ads[8];

void exibirAlunos();
void ordenarAlunosPorNome();
void adicionarmaterias();
float calcularnotas();
void lancar_notas();
void vernotas();
void cadastro();
void editarcadastro(int alunes);
void suporte();
void limparBuffer();

// Ana esse é o struct dos alunos
typedef struct {
    char nome[50];
    char senha[99];
    char telefone[50];
    char endereco[99];
    char DataNascimento[99];
    char curso_do_aluno[99];
    char matricula[99];
    char materias[3][99];
    float notas[4];
    int turma[99]; 
    float media[99];
    char status[15];
} Aluno;
extern Aluno alunos[MAX_ALUNOS];

#endif
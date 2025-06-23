#ifndef DECLARACOES_H
#define DECLARACOES_H
#define MAX_ALUNOS 100
#include <stdbool.h>

// Variáveis globais necessárias
extern int dia, mes, ano, opcao, opcaog, cursos, totalAlunos, m, id_aluno;
extern char materia[99], nome[50], solicitar_e[99], ADM[10], ADMS[10];
extern bool opcaoin2, admin;

// Declarações de funções
void exibirAlunos();
void ordenarAlunosPorNome();
void adicionarmaterias(int i);
float calcularnotas(int aluno_idx);
void lancar_notas();
void vernotas();
void cadastro();
void editarcadastro(int alunes);
void suporte();
void limparBuffer();

// Struct dos alunos
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
    int turma; // Simplificado de int turma[99]
} Aluno;
extern Aluno alunos[MAX_ALUNOS];

#endif

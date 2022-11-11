#ifndef TRABALHO2_H
#define TRABALHO2_H

typedef struct No{
    int id;
    struct No *prox;
}no;

typedef struct Alunos{
    char nome[30];
    char curso[30];
    int id;
    no*amg;
}al;

typedef struct lista{      
    al aluno;
    struct lista *prox;
    struct lista *ant;
                          
 }alList;
al *leAluno ();//
alList *criar();//
void alterarNome(al*a);//
void alterarCurso(al*a);//
void insereOrdenado(alList **a,al*b);
void printList(alList **a);//printa a lista
void case2(alList**a);//altera os dados dos alunos chamando alteraNome e alteraCurso
void removerAl(alList**a);//Remove um aluno do cadastro e de todas as suas respectivas relaçoes de amizade
void imprimeAluno(al a);//
void inserirAmigo(alList**a);//
char*retornaCurso(al*a);//
void cursoFilter(alList**a);//filtra os alunos por curso e printa os cadastrados no curso solicitado
void printFriend(alList**a);//
void removerAmigo(alList**a);//
void printaNoArquivo(al*a,FILE*f);
void insereTudoNoArquivo(alList **a,FILE*f);
void leitorArquivo(alList**l,FILE*f);

#endif /* TRABALHO2_H */


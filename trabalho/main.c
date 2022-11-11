
#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

/*
 * 
 */
int main(){
    alList *systmAl=criar();
    FILE *fileR;
    fileR = fopen("arquivo.txt", "r");
    if(fileR){
    leitorArquivo(&systmAl,fileR);//função que le o arquivo de alunos dado pela professora(ultimos codigos do tad.c)
    fclose(fileR);
    }
    int request,loop=1;
    while(loop==1){
        printf("________________MENU___DE___INTERACAO_________________");
        printf("\n\nEscolha a opção desejada:\n1 - Inserir um novo aluno\n2 - Alterar os dados de um aluno\n3 - Remover um aluno\n4 - Imprimir a lista de alunos\n5 – Inserir relação de amizade\n6 – Remover relação de amizade\n7 – Imprimir amigos de um aluno\n8 – Imprimir a lista de alunos por curso\n9 – Sair\n->");
        scanf("%d",&request);
        switch(request){
            case 1:{//inserir novo aluno ok
                al *a =leAluno();
                insereOrdenado(&systmAl,a);
                system("clear");//para windows
                system("cls");
                break;
                }
            case 2://alterar os dados de um aluno ok
                case2(&systmAl);
                system("clear");//para windows
                system("cls");
                break;
            case 3://remover um aluno ok
                removerAl(&systmAl);
                system("clear");//para windows
                system("cls");
                break;
            case 4://Imprimir a lista de alunos ok
                system("clear");//para windows
                system("cls");
                printList(&systmAl);
                break;
            case 5://inserir relação de amizade ok
                inserirAmigo(&systmAl);
                system("clear");//para windows
                system("cls");
                break;
            case 6://remover relação de amizade ok
                removerAmigo(&systmAl);
               system("clear");//para windows
               system("cls");
                break;
            case 7://imprimir amigos de um aluno ok
                system("clear");//para windows
                system("cls");
                printFriend(&systmAl);
                break;
            case 8://imprimir a lista de alunos por curso ok
                system("clear");//para windows
                system("cls");
                cursoFilter(&systmAl);
                break;
            case 9:{//sair ok
                FILE *fileW;
                fileW=fopen("arquivo.txt","w");
                if(fileW){
                insereTudoNoArquivo(&systmAl,fileW);
                fclose(fileW);
                }
                loop=0;
                break;
                }
            default:
                system("clear");//para windows
                system("cls");
                printf("NUMERACAO INVALIDA!\n");
            
        }
    };
    return EXIT_SUCCESS;
}


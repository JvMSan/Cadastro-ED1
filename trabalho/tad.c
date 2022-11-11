#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int al_id = 0;

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


 //funçoes fecilitadoras:
alList* criar(){
    alList*p=malloc(sizeof(alList));
    p=NULL;
    return p;
}
 int verify(al a,al *b){
    int confirm = strcmp(a.nome,b->nome);
    return confirm;
}

//----------------------------------------------------------

void imprimeAluno(al*a){
    setbuf(stdin,NULL);
    printf("Aluno: %s|---|Curso: %s|---|ID:%d\n",a->nome,a->curso,a->id);
    setbuf(stdin,NULL);
}

al *leAluno (){
    al *b = malloc(sizeof(al));
    al_id++;
    printf("insira o nome do Novo aluno:\n");
    setbuf(stdin,NULL);
    scanf("%[^\n]",b->nome);
    setbuf(stdin,NULL);
    printf("insira o curso do Novo aluno:\n");
    setbuf(stdin,NULL);
    scanf("%[^\n]",b->curso);
    setbuf(stdin,NULL);
    b->id=al_id;
    b->amg=NULL;
    return b;
 }
void alterarNome(al*a){
    printf("O nome atual e: %s\nInsira o novo nome:\n ",a->nome);
    setbuf(stdin,NULL);
    scanf("%[^\n]",a->nome);
    setbuf(stdin,NULL);
}
void alterarCurso(al*a){
    printf("O curso atual e:%s\nInsira o novo curso:\n",a->curso);
    setbuf(stdin,NULL);
    scanf("%[^\n]",a->curso);
    setbuf(stdin,NULL);
    
}
void insereOrdenado(alList **a,al *b){
    alList *p,*anterior,*aux=malloc(sizeof(alList));
    if((*a)==NULL){
        aux->aluno=*b;
        *a=aux;
        (*a)->ant=NULL;
        (*a)->prox=NULL;
    }else if(strcmp((*a)->aluno.nome,b->nome)>0){
        aux->aluno=*b;
        (*a)->ant=aux;
        aux->prox=*a;
        aux->ant=NULL;
        *a=aux;
    }else{
        for(p=*a;p!=NULL&& strcmp(p->aluno.nome,b->nome)<0;p=p->prox){
            anterior=p;
        };
        if(p!=NULL){
            aux->aluno=*b;
            p->ant->prox=aux;
            aux->ant=p->ant;
            aux->prox=p;
            p->ant=aux;
        }else{
            aux->aluno=*b;
            anterior->prox=aux;
            aux->ant=anterior;
            aux->prox=NULL;
        }
    }
}

void printList(alList **a){
    al aux;
    if(a!=NULL){
        for(alList*p=*a;p!=NULL;p=p->prox){
                aux=p->aluno;
                setbuf(stdin,NULL);
                imprimeAluno(&aux);
                setbuf(stdin,NULL);
        }
    }else{
        printf("A lista esta vazia!\n");
    }
}

void case2(alList**a){
    printf("Insira do id do aluno que deseja alterar os dados:\n");
    int id_request;
    scanf("%d",&id_request);
    for(alList*aux=*a;aux!=NULL;aux=aux->prox){
        if(aux->aluno.id==id_request){
            alterarNome(&aux->aluno);
            alterarCurso(&aux->aluno);
        }
    }; 
}

void removerAl(alList**a){
    printf("Insira o ID do Aluno que sera removido:\n");
    int id_rem;
    scanf("%d",&id_rem);
    
    for(alList*b=*a;b!=NULL;b=b->prox){
        
        if(b->aluno.id==id_rem){
            for(alList*p=*a;p!=NULL;p=p->prox){//remover da lista de amigos de todos
                if(p->aluno.amg!=NULL){
                    no*aju=p->aluno.amg;
                    no*anter,*y;
                    if(aju->id==id_rem){
                        p->aluno.amg=aju->prox;
                    }else{
                        for(y=aju;y!=NULL&&y->id!=id_rem;y=y->prox){
                            anter=y;
                        }
                        anter->prox=y;
                    }
                }
            }
            if(b->ant!=NULL&&b->prox==NULL){
                b->ant->prox=NULL;
                b->ant=NULL;
                free(b);
            }else if(b->ant==NULL && b->prox!=NULL){
                b->prox->ant=NULL;
                b->prox=NULL;
                free(b);
            }else if(b->ant!=NULL &&b->prox!=NULL){
                b->ant->prox=b->prox;
                b->prox->ant=b->ant;
                b->ant=b->prox=NULL;
                free(b);
            }else{
                b=NULL;
            }
            break;
        }
    }      
}

//inserir_amigo_mk2
void inserirAmigo(alList**a){
	printf("Insira o id do aluno que deseja adicionar uma relacao de amizade:\n");
	int id_remetente, id_amg;
	scanf("%d",&id_remetente);
	printf("Insira o id do amigo que sera inserido:\n");
	scanf("%d",&id_amg);
        for(alList*at=*a;at!=NULL;at=at->prox){
        if(at->aluno.id==id_remetente){
            no*aux=malloc(sizeof(no));
            aux->id=id_amg;
            aux->prox=NULL;
            if(at->aluno.amg==NULL){
                at->aluno.amg=aux;
            }else{
                for(no*p=at->aluno.amg;p!=NULL;p=p->prox){
                    if(p->prox==NULL){
                        p->prox=aux;
                        break;
                    }
                }
            } 
        }
    }
            for(alList*at=*a;at!=NULL;at=at->prox){
        if(at->aluno.id==id_amg){
            no*aux=malloc(sizeof(no));
            aux->id=id_remetente;
            aux->prox=NULL;
            if(at->aluno.amg==NULL){
                printf("3\n");
                at->aluno.amg=aux;
            }else{
                printf("4\n");
                for(no*p=at->aluno.amg;p!=NULL;p=p->prox){
                    printf("5\n");
                    if(p->prox==NULL){
                        printf("6\n");
                        p->prox=aux;
                        break;
                    }
                }
            } 
        }
    }
}


//imprimir amigos de um al

void printFriend(alList**a){
	printf("Insira o id do aluno que deseja imprimir a lista de amizade:\n");
	int id_request;
	scanf("%d",&id_request);
        for(alList*aux=*a;aux!=NULL;aux=aux->prox){
        if(aux->aluno.id==id_request){
            setbuf(stdin,NULL); 
		printf("Lista de amigos de %s:\n",aux->aluno.nome);
                setbuf(stdin,NULL);
		int i=1;
		for(no*x=aux->aluno.amg;x!=NULL;x=x->prox){
                    setbuf(stdin,NULL);
                    for(alList*auxi=*a;auxi!=NULL;auxi=auxi->prox){
                        if(auxi->aluno.id==x->id){
                        setbuf(stdin,NULL);
                        printf("%d)%s\n",i,auxi->aluno.nome);
                        setbuf(stdin,NULL);
                        i++;
                        }
                    }
                }
        }
    };
}

//funcao de retornar curso

char*retornaCurso(al*a){
    return (a->curso);
}

//imprimir a lista de alunos por curso

void cursoFilter(alList**a){
	printf("Insira o curso para serem mostrados os alunos matriculados:\n");
	char filter_curso[30];
        setbuf(stdin,NULL);
	scanf("%[^\n]s",filter_curso);
        setbuf(stdin,NULL);
	int i=1;
	for(alList*p=*a;p!=NULL;p=p->prox){
            if(strcmp(filter_curso,retornaCurso(&p->aluno))==0){
		imprimeAluno(&p->aluno);
            }
        }
}

void removerAmigo(alList**a){
    printf("Insira o id do aluno que deseja remover uma relacao de amizade:\n");
    int id_remetente, id_amg;
    scanf("%d",&id_remetente);
    printf("Insira o id do amigo que sera removido:\n");
    scanf("%d",&id_amg);
    for(alList*x=*a;x!=NULL;x=x->prox){
        if(x->aluno.id==id_amg){
            no*cw=x->aluno.amg;
            no*anterior2;
            if(cw->id==id_remetente){
                x->aluno.amg=x->aluno.amg->prox;
            }else{
                no*d;
                for(d=cw;d!=NULL&&d->id!=id_remetente;d=d->prox){
                    anterior2=d;
                }
                anterior2->prox=d->prox;
            }
        }
    }
    for(alList*x=*a;x!=NULL;x=x->prox){
        if(x->aluno.id==id_remetente){
            no*cw=x->aluno.amg;
            no*anterior2;
            if(cw->id==id_amg){
                x->aluno.amg=x->aluno.amg->prox;
            }else{
                no*d;
                for(d=cw;d!=NULL&&d->id!=id_amg;d=d->prox){
                    anterior2=d;
                }
                anterior2->prox=d->prox;
            }
        }
    }
}
//FUNÇOES USADAS NO TRABALHO 2 -----------------------------------------------------------------------------------------------------------------------------------------
void printaNoArquivo(al*a,FILE*f){
    setbuf(stdin,NULL);
    fprintf(f,"%s\t%d\t%s\n",a->nome,a->id,a->curso);
    setbuf(stdin,NULL);
    fprintf(f,"\t");
    for(no*aux= a->amg;aux!=NULL;aux=aux->prox){
        fprintf(f,"%d ",aux->id);
    }
    fprintf(f,"\n");
}

void insereTudoNoArquivo(alList **a,FILE*f){
    if(a!=NULL){
        for(alList*p=*a;p!=NULL;p=p->prox){
                setbuf(stdin,NULL);
                printaNoArquivo(&(p->aluno),f);
                setbuf(stdin,NULL);
        }
    }else{
        printf("A lista esta vazia!\n");
    }
}

void leitorArquivo(alList**l,FILE*f){ 
    if (f != NULL){
    al*b=malloc(sizeof(al));
    
    while(fscanf(f,"%[^\t]%d\t%[^\n]",b->nome,&b->id,b->curso)!=EOF){
        b->amg=NULL;
        int id_amg;
        while(fscanf(f,"%d ",&id_amg)==1){
            no*Amg=malloc(sizeof(no));
            Amg->id=id_amg;
            Amg->prox=b->amg;
            b->amg=Amg;
            
        }
        if(b->id>=al_id){
            al_id=(b->id);
        }
        insereOrdenado(l,b);
    }    
    }
}




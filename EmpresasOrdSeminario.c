#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef char TIPOCHAVE;
FILE *fp; // Ponteiro para abertura de arquivos.

typedef struct aux{
	TIPOCHAVE nome[200];
	char dataPubAto[11];
	char municipio[100];
	char uf[3];
	struct aux *esq, *dir;	
} NO;

typedef NO* PONT;

PONT inicializa(){
	return(NULL);
}

PONT adiciona(PONT raiz, PONT no){
	if(raiz == NULL) return(no);
	if(strcmp(no->nome,raiz->nome)<0) raiz->esq = adiciona(raiz->esq, no);
	else raiz->dir = adiciona(raiz->dir, no);
	return raiz;
}

PONT criaNovoNo(char nome[], char dataPubAto[], char municipio[], char uf[]){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	strcpy(novoNo->nome, nome);
	strcpy(novoNo->dataPubAto, dataPubAto);
	strcpy(novoNo->municipio, municipio);
	strcpy(novoNo->uf, uf);
	return(novoNo);	
}

PONT contem( char nome[], PONT raiz){
	if(raiz == NULL) return(NULL);
	if(strcmp(raiz->nome, nome)==0) return (raiz);
	if(strcmp(raiz->nome, nome)>0) return(contem(nome, raiz->esq));
	return(contem(nome, raiz->dir));
}

PONT buscaNo(PONT raiz, TIPOCHAVE nome[], PONT *pai){
	PONT atual = raiz;
	*pai = NULL;
	while (atual){
		if(strcmp(atual->nome, nome)==0) return atual;
		*pai = atual;
		if(strcmp(nome, atual->nome)<0) atual = atual->esq;
		else atual = atual->dir;
	}
	return NULL;
}

PONT removeNo(PONT raiz, TIPOCHAVE nome[]){
	PONT pai, no, p, q;
	no = buscaNo(raiz, nome, &pai);
	if(no == NULL) return raiz;
	if(!no->esq || !no->dir){
		if(!no->esq) q = no->dir;
		else q = no->esq;
	}
	else{
		p = no;
		q = no->esq;
		while (q->dir){
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
	if(!pai){
		free(no);
		return q;
	}
	if(strcmp(nome, pai->nome) < 0) pai->esq = q;
	else pai->dir = q;
	free(no);
	return raiz;
}

void main(){
	clock_t t;
	setlocale(LC_ALL, "Portuguese");
	TIPOCHAVE nome[200];
	char dataPubAto[11];
	char municipio[100];
	char uf[3];
	// Inicialização da árvore
	PONT r = inicializa();
	PONT no = inicializa();
	char opcao = 0;
	do{
		system("cls");
		printf("\t\t MENU\n");
		printf("1 - Inserir\n");
		printf("2 - Buscar\n");
		printf("3 - Excluir\n");
		printf("4 - Sair\n");
	
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opcao);
		fflush(stdin);
		switch(opcao){
			case 1:
				// Abre o arquivo para leitura:
    			fp = fopen("EmpresasOrd.csv", "r");
    			// Seta o ponteiro do arquivo para a segunda linha, descartando a primeira:
      			char descarte[200];
      			fgets(descarte, sizeof(descarte), fp);
    			while(fscanf(fp, "%[^;];%[^;];%[^;];%s\n", nome, dataPubAto, municipio, uf) != EOF){
                    /*printf("%s\n", nome);
                    printf("%s\n", dataPubAto);
                    printf("%s\n", municipio);
                    printf("%s\n\n", uf);*/
                    no = criaNovoNo(strupr(nome), dataPubAto, strupr(municipio), strupr(uf));
					r = adiciona(r,no);
      			}
				system("pause");
				break;
			case 2:
				printf("Digite o nome da empresa que deseja buscar: ");
				gets(nome);
				fflush(stdin);
				t = clock();
				no = contem(strupr(nome), r);
				if( no != NULL ){
					printf("Nome: %s\n", no->nome);
					printf("Data de publicação do ato: %s\n", no->dataPubAto);
					printf("Municipio: %s\n", no->municipio);
					printf("UF: %s\n", no->uf);
				}
				else printf("Empresa não cadastrada");
				t = clock() - t;
      			printf ("\n-------------------------------------\nTempo de execução: %f segundos.\n",((float)t)/CLOCKS_PER_SEC);
				system("pause");
				break;
			case 3:
				printf("Digite o nome da empresa que deseja excluir: ");
				gets(nome);
				fflush(stdin);
				no = removeNo(r, strupr(nome));
				if( no != NULL ){
					printf("Empresa Removida com sucesso\n");
				}
				else printf("Empresa não cadastrada\n");
				system("pause");
				break;
			case 4:
				printf("Sair\n");
				system("pause");
				break;
			default:
				printf("Opção inváida.\n");
				break;
		}
	}while(opcao != 4);
}

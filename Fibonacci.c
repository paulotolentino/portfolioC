#include <stdio.h>
#include <locale.h>

int pedirNumero(){
	int termo;
	printf("Insira um número que represente o n-ésimo termo da sequência de Fibonacci: ");
	scanf("%d", &termo);
	return termo;
}
int iterativo(int termo){
	int ant = 0;
	int velhoSoma;
	int soma = 1;
	int i;
	for (i = 1; i < termo; i++){
		velhoSoma = soma;
		soma += ant;
		ant = velhoSoma;
	}
	return soma;
}

// Caso geral
int recursivoMaior(int termo, int ant, int atual){

	if(termo == 2) return 1;
	int novo = ant + atual;
	int soma = ant;
	return ant + recursivoMaior(--termo, atual, novo);	
}

void main(){
	
	int termo, escolha;
	setlocale(LC_ALL, "Portuguese");
	printf("\t MENU\n");
	printf("Escolha a opção desejada\n");
	printf("1 - Solução iterativa\n");
	printf("2 - Solução recursiva\n");
	printf("Opção: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:
			termo = pedirNumero();
			if(termo<1) printf("Número inválido");
			else printf("O %d termo da sequência de Fibonacci é %d.\n", termo, iterativo(termo));
			system("pause");
			break;
		case 2:
			termo = pedirNumero();
			// Caso Base
			if(termo<=2 && termo>0) printf("O %d termo da sequência de Fibonacci é 1.", termo);
			// Caso Geral
			else if(termo>2) printf("O %d termo da sequência de Fibonacci é %d.", termo, recursivoMaior(termo, 1, 1));
			else printf("Número inválido\n");
			system("pause");
			break;
		default:
			printf("Opção inválida\n");
			system("pause");
	}	
}

#include <stdio.h>
#include <locale.h>

int pedirNumero(){
	int termo;
	printf("Insira um n�mero que represente o n-�simo termo da sequ�ncia de Fibonacci: ");
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
	printf("Escolha a op��o desejada\n");
	printf("1 - Solu��o iterativa\n");
	printf("2 - Solu��o recursiva\n");
	printf("Op��o: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:
			termo = pedirNumero();
			if(termo<1) printf("N�mero inv�lido");
			else printf("O %d termo da sequ�ncia de Fibonacci � %d.\n", termo, iterativo(termo));
			system("pause");
			break;
		case 2:
			termo = pedirNumero();
			// Caso Base
			if(termo<=2 && termo>0) printf("O %d termo da sequ�ncia de Fibonacci � 1.", termo);
			// Caso Geral
			else if(termo>2) printf("O %d termo da sequ�ncia de Fibonacci � %d.", termo, recursivoMaior(termo, 1, 1));
			else printf("N�mero inv�lido\n");
			system("pause");
			break;
		default:
			printf("Op��o inv�lida\n");
			system("pause");
	}	
}

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

int main()
{
	//setlocale(LC_ALL, NULL);
	unsigned long int n, x;
	int cont;
	//printf("ESTE � UM PROGRAMA PARA C�LCULO DO N�MERO DE FERMAT\n\n\n");
	printf("ESTE E UM PROGRAMA PARA CALCULO DO NUMERO DE FERMAT\n\n\n");
	for(cont=1;;cont++)
	{
		//printf("Insira um n�mero inteiro positivo: ");
		printf("Insira um numero inteiro positivo: ");
		scanf("%ld", &n);
		x = pow(2,n);
		x = pow(2,x);
		x++;
		printf("%ld\n", x);
		getch();
	}
	return 0;
}

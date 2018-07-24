#include <stdio.h>
#include <locale.h>
#include <math.h>

int ehPrimo(long int numero)
{
    long int n, divisores=0;
    for(n=1; n<= sqrt(numero); n++)
        if ( numero%n==0) divisores++;
    if ( divisores==1 ) return 1;
    else return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    long int num, x;
    printf("Digite um n�mero inteiro: ");
    scanf("%ld", &num);
    for(x=1; x<=num; x++)
        if (ehPrimo(x)) printf("%ld\t", x);
    printf("\n");
	system("pause");
    return 0;
}

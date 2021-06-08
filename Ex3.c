#include <stdio.h>
#include <stdlib.h>

int Rec_Multp(base, exp)
{
    if(exp == 1) // se exp for igual a 1, significa que vamos multiplicar a base apenas por 1, ou seja, a propria base, retornamos base
    {
        return base;
    }
    else if(exp == 0)// se o expoente é igual a 0 ja retornamos o resultado = 0
    {
        return 0;
    }
    return base + Rec_Multp(base, --exp);// a parte de recursivade do codigo somamos a variavel base e chamamos a funçao novamente diminuindo uma unidade em exp, assim será repetido até exp ser = 0

}
int main ()
{
    int base, exp;
    printf("Digite o numero base:\n");
    scanf_s("%d", &base);
    printf("Digite o numero expoente:\n");
    scanf_s("%d", &exp);
    printf("Resultado: %d\n", Rec_Multp(base, exp));// solicitamos no printf o resultado da funçao Rec_Multp que chamamos com parametros base e expoente
    system("pause");
    return 0;
}

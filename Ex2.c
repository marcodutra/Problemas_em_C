#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void calc_soma(int *mat_A, int *mat_B, int *mat_C) // passamos cada matriz por ponteiro para fazermos a soma de matriz A+B para formamos matriz C
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            mat_C[i * TAM + j] = mat_A[i * TAM + j] + mat_B[i * TAM + j]; // soma posiçoes iguais nas matrizes (A[i][j]+B[i][j]) e guarda na respectiva posição na matriz C[i][j]

        }
    }

}

void imprime(int *mat_X) // funcão para imprimir a respectiva matriz, que é passada por ponteiro
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        if (i != 0) printf("\n");
        for (j = 0; j < TAM; j++)
        {
            printf("\t%d", mat_X[i * TAM + j]);
        }
    }
}

int main()
{
    int mat_A[TAM][TAM], mat_B[TAM][TAM], mat_C[TAM][TAM];// declaramos as 3 matrizes, com tamanhos 4x4 definidos por TAM
    int i, j; // variaveis auxiliares
    for(i = 0; i < 4; i++) //preenchemos a matriz A com valores digitados pelo usuario, caso numero negativo o programa termina
    {
        for(j = 0; j < 4; j++)
        {
            printf("Digite valor da matriz A[%d]x[%d]=", i+1, j+1);
            scanf_s("%d", &mat_A[i][j]); // le o valor e guarda na posiçao [i][j]
            if(mat_A[i][j] < 0)// se o valor na posição [i][j] é negativo, encerramos o programa
            {
                printf("erro, valor negativo digitado");
                exit(1);
            }
        }
    }

    for(i = 0; i < 4; i++) //preenchemos a matriz B com valores digitados pelo usuario, caso numero negativo o programa termina
    {
        for(j = 0; j < 4; j++)
        {
            printf("Digite valor da matriz B[%d]x[%d]=", i+1, j+1);
            scanf_s("%d", &mat_B[i][j]); // le o valor e guarda na posiçao [i][j]
            if(mat_B[i][j] < 0)// se o valor na posição [i][j] é negativo, encerramos o programa
            {
                printf("erro, valor negativo digitado");
                exit(1);
            }
        }
    }
    calc_soma(mat_A, mat_B, mat_C); // passamos matriz A, B e C (C no caso vazia) para somarmos e formar matriz C
    imprime(mat_A); // imprime matriz A
    printf("\n\n");
    imprime(mat_B);// imprime matriz B
    printf("\n\n");
    imprime(mat_C);// imprime matriz C com resultado final
    printf("\n\n");
    system("pause");
    return 0;
}

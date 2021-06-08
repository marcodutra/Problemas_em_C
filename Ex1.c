#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct renda { // struct(registro) contendo nossas variaveis para alocar salario e ponteiro para um vetor nome
    char* nome;
    float salario;
    float alip;
    float aliv;
} Renda;

Renda* Aloca() // função para inicializarmos e alocarmos dinamicamente nossa struct
{
    Renda* r = (Renda*)malloc(sizeof(Renda));
    r->nome = (char*)malloc(TAM * sizeof(char));
    r->salario = 0;
    r->alip = 0;
    r->aliv = 0;
    return r;
}

void Coloca(Renda* r) // passamos nossa variavel r do tipo Renda (struct) para essa funçao
{
    printf("\nDigite seu nome:");
    scanf("%[^\n]", r->nome); // pegamos do usuario seu nome, incluindo espaços no teclado
    printf("\nDigite seu Salario:");
    scanf("%f", &r->salario); // alocamos seu salario
}

void Calcula_aliquota(Renda* r) // passamos nossa variavel r do tipo Renda (struct) para essa funçao ja sabendo o salario do usuario
{                               // cada if a seguir representa um intervalo de salario, caso se encaixe retornamos a porcentagem da aliquota e o valor de acordo com salario
    if (r->salario <= 1903.98)
    {
        r->alip = 0.00;
    }
    else if (r->salario > 1903.98 && r->salario <= 2826.65) // se salario está no intervalo entre 1903,99  e 2826,65, aliquota = 7,5% e salario vai ser multiplicado por 0,075, representando o valor a ser pago em imposto
    {
        r->alip = 7.50;
        r->aliv = r->salario * 0.075;

    }
    else if (r->salario > 2826.65 && r->salario <= 3751.05)
    {
        r->alip = 15.00;
        r->aliv = r->salario * 0.150;
    }
    else if (r->salario > 3751.05 && r->salario <= 4664.68)
        r->alip = 22.50;
        r->aliv = r->salario * 0.225;
    }
    else if(r->salario > 4664.68) //se salario é maior 4664,68, aliquota = 27,00% e salario vai ser multiplicado por 0,270, representando o valor a ser pago em imposto
    {
    {
        r->alip = 27.00;
        r->aliv = r->salario * 0.270;
    }

}

void Imprime_Aliquota(Renda* r) // imprime as informaçoes solicitadas
{
    printf("\nNOME:%s", r->nome); // nome do usuario
    printf("\nSALARIO:%2.f", r->salario); // salario do usuario
    printf("\nALIQUOTA:%2.f", r->alip); // aliquota em porcentagem
    printf("\nIMPOSTO ANUAL:%2.f", r->aliv); // valor do imposto a ser pago
}

int main()
{
    Renda* r = Aloca(); // chamamos a funçao que cria dinamicamente uma struct do tipo Renda
    Coloca(r); // captura os dados informados pelo o usuario e guarda
    Calcula_aliquota(r); // calcula aliquota de acordo com salario informado
    Imprime_Aliquota(r); // imprime salario, nome, aliquota de acordo com salario e porcentagem de aliquota
    free(r); // liberamos a memória alocada para variável r do tipo Renda alocada dinamicamente
}

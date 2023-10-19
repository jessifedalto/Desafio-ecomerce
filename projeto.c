/*Crie um programa em C que simule um e-commerce de material de construção. Seu programa deverá cadastrar novos produtos, alocando memória para a quantidade necessária.
 O usuário poderá inserir novos produtos após a primeira inserção. Poderá ser feito um orçamento do valor que será gasto na compra de produtos escolhidos.
  O usuário poderá efetuar a compra se o valor inserido que foi inserido for suficiente. Caso o valor seja maior, devolva o troco. Após esses processos,
 imprima uma nota fiscal em um arquivo de texto e permita dentro do programa exibir todas as compras inseridas em um arquivo de texto.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char produto[100];
    float preco;

}desafio;





int main()
{
    int op;
    int tamanho;
    int x = 0;

    printf("\nQuantos materias diferentes a empresa fornece? ");
    scanf("\n%d", &tamanho);


    desafio * cadastrar = malloc(tamanho*sizeof(char));

    while(op != 0)
    {
        printf("\n----------MENU---------");
        printf("\n-----1. cadastrar ------");
        printf("\n-----2. carrinho--------");
        printf("\n-----3. orçamento-------");
        printf("\n-----4. adicionar novo produto-----");
        scanf("\n%d", &op);

        switch (op)
        {
        case 1:
            for (int i = x; i < tamanho; i++)
            {
                pritf("\nNome do material: ");
                scanf("\n%s", cadastrar[i].produto);
                printf("\nPreço: ");
                scanf("\n%f", cadastrar[i].preco);

                x = x + 1;
            }
            break;
        
        case 2:
            for (int i = 0; i < tamanho; i++)
            {
                printf("\nProduto: %s", cadastrar[i].produto);
                printf("\tPreco: %2.f", cadastrar[i].preco);
            }
            

            break;
        }
    }
}
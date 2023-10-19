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

typedef struct 
{
    char p1[50];
    float valor;
}carrinho;




int main()
{
    int op;
    int tamanho;
    int x = 0;
    int quantidade_produtos = 0;
    int y = 0;
    int w = 0;
    char nome[50];
    int qtd = 0;
    float soma[5];
    float total;

    FILE * arquivo;

    printf("\nQuantos materias diferentes a empresa fornece? ");
    scanf("\n%d", &tamanho);

    arquivo = fopen("notafiscal.txt", "a");

    desafio * cadastrar = malloc(tamanho*sizeof(desafio));

    while(op != 0)
    {
        printf("\n----------MENU---------");
        printf("\n-----1. cadastrar ------");
        printf("\n-----2. carrinho--------");
        printf("\n-----3. orçamento-------");
        printf("\n-----4. adicionar novo produto-----");
        printf("\n-------5. adicionar ao carrinho ------");
        scanf("\n%d", &op);

        switch (op)
        {
        case 1:
            for (int i = x; i < tamanho; i++)
            {
                pritf("\nNome do material: ");
                scanf("%[^\n]", cadastrar[i].produto);
                printf("\nPreço: ");
                scanf("%[^\n]", cadastrar[i].preco);

                x = x + 1;
            }
            break;
        
        case 2:
            for (int i = 0; i < tamanho; i++)
            {
                printf("\n %d - Produto: %s", i, cadastrar[i].produto);
                printf("\tPreco: %2.f", cadastrar[i].preco);
            }
            printf("\nQuantos produtos diferentes serao adicionados ao carrinho: ");
            scanf("%d", &quantidade_produtos);

            carrinho * escolhas = malloc(quantidade_produtos*sizeof(carrinho));

            for (int i = y; i < quantidade_produtos; i++)
            {
                printf("\n Qual o nome produto desejado? ");
                scanf("%[^\n]", nome);
                for (int i = 0; i < tamanho; i++)
                {
                    if (nome == cadastrar[i].produto)
                    {
                        //escolhas[w]->p1 = cadastrar[i].produto;
                        escolhas[w].valor = cadastrar[i].preco;
                        w = w + 1;
                    }
                }
                y = y + 1;
            }
            
            break;

        case 3:
            for (int i = 0; i < quantidade_produtos; i++)
            {
                printf("\nQual a quantidade do %d produto? ", i+1);
                scanf("%d", &qtd);
                soma[i] = qtd * escolhas[i].valor;
            }
            for (int i = 0; i < quantidade_produtos; i++)
            {
                total = soma[i]++;
            }
            
            printf("\nO total e: %2.f", total);
            
            break;
        case 4:
            printf("Quantos itens serao no total? ");
            scanf("%d", &tamanho);
            cadastrar = realloc(cadastrar, tamanho*sizeof(desafio));
            
        }
    }
}
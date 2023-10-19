/*Crie um programa em C que simule um e-commerce de material de construção. Seu programa deverá cadastrar novos produtos, alocando memória para a quantidade necessária.
 O usuário poderá inserir novos produtos após a primeira inserção. Poderá ser feito um orçamento do valor que será gasto na compra de produtos escolhidos.
  O usuário poderá efetuar a compra se o valor inserido que foi inserido for suficiente. Caso o valor seja maior, devolva o troco. Após esses processos,
 imprima uma nota fiscal em um arquivo de texto e permita dentro do programa exibir todas as compras inseridas em um arquivo de texto.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char produto[50];
    float preco;

}desafio;

typedef struct 
{
    char p1[50];
    float valor;
}carrinho;




int main()
{
    FILE * arquivo;
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
    float dinheiro = 0;
    float troco = 0;

    

    printf("\nQuantos materias diferentes a empresa fornece? ");
    scanf("\n%d", &tamanho);

    

    desafio * cadastrar = malloc(tamanho*sizeof(desafio));

    while(op != 0)
    {
        printf("\n----------MENU---------");
        printf("\n-----1. cadastrar ------");
        printf("\n-----2. carrinho--------");
        printf("\n-----3. orçamento-------");
        printf("\n-----4. adicionar novo produto-----");
        printf("\n-------5. pagar ------\n");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            for (int i = x; i < tamanho; i++)
            {
                printf("\nNome do material: ");
                scanf(" %[^\n]", cadastrar[i].produto);
                printf("\nPreço: ");
                scanf(" %f", &cadastrar[i].preco);

                x = x + 1;
            }
            break;
        
        case 2:
            for (int i = 0; i < tamanho; i++)
            {
                printf("\n %d - Produto: %s", i, cadastrar[i].produto);
                printf("\tPreco: %.2f", cadastrar[i].preco);
            }
            printf("\nQuantos produtos diferentes serao adicionados ao carrinho: ");
            scanf("%d", &quantidade_produtos);

            carrinho * escolhas = malloc(quantidade_produtos*sizeof(carrinho));

            for (int i = y; i < quantidade_produtos; i++)
            {
                printf("\n Qual o nome produto desejado? ");
                scanf(" %[^\n]", nome);
                for (int j = 0; j < tamanho; j++)
                {
                    if (strcmp(nome, cadastrar[j].produto)==0)
                    {
                        strcpy(escolhas[w].p1,cadastrar[j].produto);
                        escolhas[w].valor = cadastrar[j].preco;
                        w = w + 1;
                    }
                }
                y = y + 1;
            }
            
            break;

        case 3:
            
            arquivo = fopen("notafiscal.txt", "a");
            for (int i = 0; i < quantidade_produtos; i++)
            {
                printf("\nQual a quantidade do %d produto? ", i+1);
                scanf("%d", &qtd);
                soma[i] = qtd * escolhas[i].valor;
                fprintf(arquivo, "\nProduto: %s \t Preco: %.2f \t Quantidade: %d", escolhas[i].p1, escolhas[i].valor, qtd);
                
            }
            for (int i = 0; i < quantidade_produtos; i++)
            {
                total = total + soma[i];
            }
            
            

            fprintf(arquivo, "\nO total e: %.2f", total);
            
            fclose(arquivo);

            break;
        case 4:
            printf("Quantos itens serao no total? ");
            scanf("%d", &tamanho);
            cadastrar = realloc(cadastrar, tamanho*sizeof(desafio));
            break;

        case 5:
            arquivo = fopen("notafiscal.txt", "a+");

            printf("\nO valor total foi de: %.2f", total);
            printf("\nDinheiro: ");
            scanf(" %f", &dinheiro);
            troco = dinheiro - total;
            fprintf(arquivo, "\tDinheiro: %.2f \tTroco: %.2f", dinheiro, troco);
            fclose(arquivo);


            arquivo = fopen("notafiscal.txt", "r");
            char * linha = malloc(1000*sizeof(char));
            while (fgets(linha, sizeof(linha),arquivo) != NULL)
            {
                printf(" %s", linha);
            }
            
            fclose(arquivo);
            break;   
        }
    }
}
#include <stdio.h>

int main(void)
{
    int codigo[5];
    float preco[5];
    int estoque[5];
    int i, j;
    int repetido;
    int codigoCompra;
    int posicao;
    int quantidade;
    int continuar;
    int itensVendidos = 0;
    float subtotal;
    float total = 0.0f;

    /* Etapa 1: cadastro dos cinco produtos. */
    printf("===== CADASTRO DE PRODUTOS =====\n");
    printf("Digite os precos com ponto. Exemplo: 25.50\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nProduto %d\n", i + 1);

        do
        {
            repetido = 0;
            printf("Codigo: ");
            if (scanf("%d", &codigo[i]) != 1)
            {
                printf("Entrada invalida. O codigo deve ser um numero inteiro.\n");
                return 1;
            }

            for (j = 0; j < i; j++)
            {
                if (codigo[i] == codigo[j])
                {
                    repetido = 1;
                }
            }

            if (codigo[i] <= 0)
            {
                printf("O codigo deve ser maior que zero.\n");
            }
            else if (repetido == 1)
            {
                printf("Este codigo ja foi cadastrado. Digite outro.\n");
            }
        } while (codigo[i] <= 0 || repetido == 1);

        do
        {
            printf("Preco: R$ ");
            if (scanf("%f", &preco[i]) != 1)
            {
                printf("Entrada invalida. O preco deve ser um numero.\n");
                return 1;
            }

            if (preco[i] <= 0)
            {
                printf("O preco deve ser maior que zero.\n");
            }
        } while (preco[i] <= 0);

        do
        {
            printf("Quantidade em estoque: ");
            if (scanf("%d", &estoque[i]) != 1)
            {
                printf("Entrada invalida. O estoque deve ser um numero inteiro.\n");
                return 1;
            }

            if (estoque[i] < 0)
            {
                printf("O estoque nao pode ser negativo.\n");
            }
        } while (estoque[i] < 0);
    }

    /* Etapa 2: consulta do estoque antes das vendas. */
    printf("\n========================================\n");
    printf("            ESTOQUE DA LOJA\n");
    printf("========================================\n");
    printf("Codigo     Preco            Estoque\n");

    for (i = 0; i < 5; i++)
    {
        printf("%-10d R$ %-12.2f %d\n", codigo[i], preco[i], estoque[i]);
    }

    /* Etapa 7: repeticao para comprar varios produtos. */
    do
    {
        /* Etapa 3: procura do produto pelo codigo. */
        printf("\nDigite o codigo do produto: ");
        if (scanf("%d", &codigoCompra) != 1)
        {
            printf("Entrada invalida. O codigo deve ser um numero inteiro.\n");
            return 1;
        }

        posicao = -1;

        for (i = 0; i < 5; i++)
        {
            if (codigoCompra == codigo[i])
            {
                posicao = i;
            }
        }

        if (posicao == -1)
        {
            printf("Produto nao encontrado!\n");
        }
        else
        {
            printf("Produto encontrado!\n");
            printf("Codigo: %d\n", codigo[posicao]);
            printf("Preco: R$ %.2f\n", preco[posicao]);
            printf("Estoque disponivel: %d\n", estoque[posicao]);

            printf("Quantidade desejada: ");
            if (scanf("%d", &quantidade) != 1)
            {
                printf("Entrada invalida. A quantidade deve ser um numero inteiro.\n");
                return 1;
            }

            /* Bonus: impedir vendas com quantidade zero ou negativa. */
            if (quantidade <= 0)
            {
                printf("Quantidade invalida! Digite uma quantidade maior que zero.\n");
            }
            /* Etapa 4: verificar se o estoque e suficiente. */
            else if (quantidade > estoque[posicao])
            {
                printf("Estoque insuficiente!\n");
            }
            else
            {
                /* Etapas 5, 6 e 8: subtotal, estoque e acumuladores. */
                subtotal = preco[posicao] * quantidade;
                estoque[posicao] = estoque[posicao] - quantidade;
                total = total + subtotal;
                itensVendidos = itensVendidos + quantidade;

                printf("Venda realizada!\n");
                printf("Subtotal: R$ %.2f\n", subtotal);
                printf("Estoque restante: %d\n", estoque[posicao]);
            }
        }

        do
        {
            printf("\nDeseja comprar outro produto?\n");
            printf("1 - Sim\n");
            printf("0 - Nao\n");
            printf("Opcao: ");

            if (scanf("%d", &continuar) != 1)
            {
                printf("Entrada invalida. A opcao deve ser um numero inteiro.\n");
                return 1;
            }

            if (continuar != 0 && continuar != 1)
            {
                printf("Opcao invalida! Digite 1 ou 0.\n");
            }
        } while (continuar != 0 && continuar != 1);
    } while (continuar == 1);

    /* Etapa 9: nota fiscal simplificada. */
    printf("\n========================================\n");
    printf("        NOTA FISCAL SIMPLIFICADA\n");
    printf("========================================\n");
    printf("Quantidade de itens vendidos: %d\n", itensVendidos);
    printf("----------------------------------------\n");
    printf("TOTAL DA COMPRA: R$ %.2f\n", total);
    printf("----------------------------------------\n");
    printf("Obrigado pela compra!\n");

    /* Etapa 10: consulta do estoque depois das vendas. */
    printf("\n========================================\n");
    printf("          ESTOQUE ATUALIZADO\n");
    printf("========================================\n");
    printf("Codigo     Preco            Estoque\n");

    for (i = 0; i < 5; i++)
    {
        printf("%-10d R$ %-12.2f %d\n", codigo[i], preco[i], estoque[i]);
    }

    return 0;
}

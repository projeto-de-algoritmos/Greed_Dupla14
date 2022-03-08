#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{

    int dano[100], peso[100];
    int w[100][100];
    int casos, i, j, n, k, r, c;

    // Quantidade de casos de teste
    scanf("%d", &casos);
    for (i = 1; i <= casos; i++)
    {   
        // Leitura da quantidade de projéteis 
        scanf("%d", &n);
        for (j = 1; j <= n; j++)
        {
            // Leitura do dano do projétil e do peso dele
            scanf("%d %d", &dano[j], &peso[j]);
        }
        // Leitura da capacidade de carga do canhão e resistência total do castelo
        scanf("%d %d", &k, &r);

        // Iniciando algoritimo da mochila
        for (j = 0; j < k; j++)
        {
            w[0][j] = 0;
        }
        for (j = 1; j <= n; j++)
        {
            w[j][0] = 0;
            for (c = 1; c <= k; c++)
                if (peso[j] > c)
                {
                    w[j][c] = w[j - 1][c];
                }
                else
                {
                    w[j][c] = max(w[j - 1][c - peso[j]] + dano[j], w[j - 1][c]);
                }
        }
        // Se o dano total das cargas carregadas for maior ou igual à resistência do castelo
        if (w[n][k] >= r)
        {
            printf("Missao completada com sucesso\n");
        }
        // Caso contrário
        else
        {
            printf("Falha na missao\n");
        }
    }

    return 0;
}

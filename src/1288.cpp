#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{

    int dano[100], peso[100];
    int w[100][100];
    int casos, i, j, n, k, r, c;

    scanf("%d", &casos);
    for (i = 1; i <= casos; i++)
    {
        scanf("%d", &n);
        for (j = 1; j <= n; j++)
        {
            scanf("%d %d", &dano[j], &peso[j]);
        }
        scanf("%d %d", &k, &r);
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
        if (w[n][k] >= r)
        {
            printf("Missao completada com sucesso\n");
        }
        else
        {
            printf("Falha na missao\n");
        }
    }

    return 0;
}

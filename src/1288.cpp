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
        for (j = 1; j <= n; j++){
            scanf("%d %d", &dano[j], &peso[j]);
        }
        scanf("%d %d", &k, &r);
        for (j = 0; j < k; j++){
            w[0][j] = 0;
        }
        
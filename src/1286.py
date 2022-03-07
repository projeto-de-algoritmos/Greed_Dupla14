# Retorna o valor maximo que pode ser colocado
# em uma Mochila de capacidade W

# Funca que implementa o algoritmo da Mochila
def knapSack(W, wt, val, n):

    # Caso base
    if n == 0 or W == 0:
        return 0

    # Se o peso do enesimo item for mais que Mochila de capacidade W,
    # entao este item nao pode ser incluido na solucao otima
    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)

    # retorna o maximo de dois casos:
    # (1) enesimo item incluido
    # (2) nao incluido
    else:
        return max(
            val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1)
        )


# Inicializa a Mochila vazia
val = []
wt = []

while True:

    # N numero de pedidos
    n = input()
    n = int(n)

    if (not n):
        break

    # P numero maximo de pizzas
    p = input()
    p = int(p)

    # Adiciona os itens a Mochila
    for i in range(n):
        line = list(map(int, input().split()))
        val.append(line[0])
        wt.append(line[1])
    
    # Imprimi a saida
    print('\n {} min.'.format(knapSack(p, wt, val, len(val))))

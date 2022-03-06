def knapSack(W, wt, val, n):

    if n == 0 or W == 0:
        return 0

    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)

    else:
        return max(
            val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1)
        )


while True:
    val = []
    wt = []
    numberofOrders = int(input())

    if (not numberofOrders):
        break

    maxOrders = int(input())

    for i in range(numberofOrders):
        line = list(map(int, input().split()))
        val.append(line[0])
        wt.append(line[1])

    print("{} min.".format(knapSack(maxOrders, wt, val, len(val))))

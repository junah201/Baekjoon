import sys
from decimal import Decimal
from bisect import bisect_left

T = int(sys.stdin.readline())

root5 = Decimal(
    '2.236067977499789696409173668731276235440618359611525724270897')


def cul(a1, b1, a2, b2):
    an = 0
    bn = 0

    an += a1 * a2
    an += 5 * b1 * b2

    bn += a1 * b2 + a2 * b1

    return an, bn


TWO = [2 ** i for i in range(40)]

DP = [(-1, -1) for _ in range(41)]

DP[0] = (1, 0)
DP[1] = (14, 6)


def get(n: int):
    print("n", n)
    if n == 0:
        return 1, 0
    if n == 1:
        return 3, 1
    if n == 2:
        return 14, 6

    k = bisect_left(TWO, n)

    if TWO[k] == n:
        k = k
    elif TWO[k] < n:
        k = k
    elif TWO[k] > n:
        k = k - 1

    print("k", k, TWO[k])

    if DP[k] == (-1, -1):
        if k % 2 == 0:
            tan, tbn = get(TWO[k // 2])
            DP[k] = cul(tan, tbn, tan, tbn)
        else:
            tan1, tbn1 = get(TWO[(k - 1) // 2])
            tan2, tbn2 = cul(tan1, tbn1, tan1, tbn1)
            tan3, tbn3 = get(2)
            DP[k] = cul(tan2, tbn2, tan3, tbn3)

    an, bn = DP[k]

    if n - TWO[k] > 0:
        tan1, tbn1 = DP[k]
        tan2, tbn2 = get(n - TWO[k])
        an, bn = cul(tan1, tbn1, tan2, tbn2)

    return (an, bn)


for idx in range(T):
    N = int(sys.stdin.readline())

    an, bn = get(N)

    C = Decimal(str(an)) + Decimal(str(bn)) * root5

    C = int(C) % 1000

    print(f"Case #{idx + 1}: {C:03d}")

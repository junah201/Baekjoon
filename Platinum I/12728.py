import sys

MOD: int = 1000


def cul(a: tuple, b: tuple):
    """
    행렬곱셈
    """

    a1, b1, c1, d1 = a
    a2, b2, c2, d2 = b

    ra = (a1 * a2) + (b1 * c2)
    rb = (a1 * b2) + (b1 * d2)
    rc = (c1 * a2) + (d1 * c2)
    rd = (c1 * b2) + (d1 * d2)

    ra %= MOD
    rb %= MOD
    rc %= MOD
    rd %= MOD

    return (ra, rb, rc, rd)


def cul_n(n: int):
    """
    행렬 곱셈을 n번 수행
    """
    unit = (3, 5, 1, 3)
    ans = (1, 0, 0, 1)

    n2: int = n

    while n2 > 0:
        if n2 % 2 == 1:
            ans = cul(ans, unit)

        unit = cul(unit, unit)

        n2 //= 2
    return ans


for idx in range(int(sys.stdin.readline())):
    N = int(sys.stdin.readline())

    if N == 0:
        print(f"Case #{idx + 1}: 001")
        continue

    tmp = cul_n(N - 1)
    ra, rb, rc, rd = tmp

    ans = 2 * (ra * 3 + rb * 1) - 1

    if ans == -1:
        ans = 999

    ans %= MOD

    print(f"Case #{idx + 1}: {ans:03d}")

import sys

input = sys.stdin.readline

is_prime = [
    True for _ in range(10001)
]

is_prime[0] = False
is_prime[1] = False

for i in range(2, 10001):
    if is_prime[i] == False:
        continue

    for j in range(i + i, 10001, i):
        is_prime[j] = False


def get_sum(N: int) -> int:
    res = 0
    while N:
        res += (N % 10) ** 2
        N = N//10
    return res


def solve():
    case, N = map(int, input().split())

    if not is_prime[N]:
        print(case, N, "NO")
        return

    now = N
    s = set([N])
    while True:
        now = get_sum(now)
        if now == 1:
            print(case, N, "YES")
            return
        if now in s:
            print(case, N, "NO")
            return
        s.add(now)


for _ in range(int(input())):
    solve()

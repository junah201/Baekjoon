import sys
from itertools import product
input = sys.stdin.readline


def main():
    N = int(input())
    M = int(input())
    disabled_buttons = list(map(int, input().split()))
    buttons = [i for i in range(10) if i not in disabled_buttons]

    if N == 100:
        print(0)
        return

    DP = [
        -1 for _ in range(1000000)
    ]
    DP[100] = 0

    for i in range(1, 7):
        for j in product(buttons, repeat=i):
            num = int(''.join(map(str, j)))
            DP[num] = len(str(num))

    if DP[N] == 0:
        print(len(str(N)))
        return

    # + 버튼만 사용해서 가장 가까운 숫자
    ans = abs(N - 100)
    idx = N
    while idx >= 0:
        if DP[idx] != -1:
            # print(idx)
            ans = min(abs(N - idx) + DP[idx], ans)

        idx -= 1

    idx = N
    while idx < 1000000:
        if DP[idx] != -1:
            # print(idx)
            ans = min(abs(N - idx) + DP[idx], ans)

        idx += 1

    print(ans)


main()

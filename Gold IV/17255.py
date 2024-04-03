from collections import defaultdict


DP = defaultdict(int)


def solve(n: str):
    if len(n) == 1:
        return 1

    if DP[n] != 0:
        return DP[n]

    if n[1:] == n[:-1]:
        DP[n] = solve(n[1:])
    else:
        DP[n] = solve(n[1:]) + solve(n[:-1])

    return DP[n]


def main():
    N = input().strip()
    print(solve(N))


main()

import sys
input = sys.stdin.readline


def solve():
    S = input().rstrip()
    S = S[:-1]
    print(S)


N = int(input())
for _ in range(N):
    solve()

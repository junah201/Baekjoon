import sys
input = sys.stdin.readline


def solve():
    N = int(input())
    if N == 0:
        exit()

    N -= 1

    S = bin(N)
    S = S[2:]
    S = S[::-1]
    ans = []

    i = 1
    for s in list(S):
        if s == "1":
            ans.append(str(i))
        i *= 3

    if not ans:
        print("{ }")
    else:
        print("{ ", end="")
        print(", ".join(ans), end="")
        print(" }", end="\n")


while True:
    solve()

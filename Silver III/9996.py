import sys

input = sys.stdin.readline

N = int(input())
pattern = input().rstrip()
s, e = pattern.split("*")

for _ in range(N):
    S = input().rstrip()

    if S.startswith(s) and S.endswith(e) and len(S) >= len(s) + len(e):
        print("DA")
    else:
        print("NE")

import sys

N, K = map(int, sys.stdin.readline().split())

for i in range(2, K):
    if N % i == 0:
        print("BAD", i)
        sys.exit()

print("GOOD")
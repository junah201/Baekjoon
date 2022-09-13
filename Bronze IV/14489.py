A = sum(map(int, input().split()))
C = int(input())

if (A != 0 and C != 0 and A // C >= 2):
    A -= C + C

print(A)

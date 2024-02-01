import sys

input = sys.stdin.readline

N = int(input())

A = {
    "ChongChong": True
}

for _ in range(N):
    a, b = map(str, input().split())
    if A.get(a, False) or A.get(b, False):
        A[a] = True
        A[b] = True

ans = 0

for key, value in A.items():
    ans += int(value)

print(ans)

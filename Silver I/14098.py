import sys
input = sys.stdin.readline

N = int(input())

records = [
    -1 for _ in range(N)
]

cars = [
    "" for _ in range(N)
]

for i in range(N):
    name = input().rstrip()
    cars[i] = name

ans = 0

for i in range(N):
    name = input().rstrip()
    for j in range(N):
        if cars[j] == name:
            records[i] = j
            break

for i in range(N):
    for j in range(i + 1, N):
        if records[j] < records[i]:
            ans += 1
            break

print(ans)

X = int(input())

sum = 0

for _ in range(int(input())):
    N, M = map(int, input().split())
    sum += N * M

if X == sum:
    print("Yes")
else:
    print("No")

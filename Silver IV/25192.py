N = int(input())
A = []
ans = 0

for i in range(N):
    A.append(input())
    if A[-1] == "ENTER":
        ans += len(set(A)) - 1
        A = []

ans += len(set(A))

print(ans)

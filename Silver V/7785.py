N = int(input())

A = set()

for _ in range(N):
    name, info = input().split()
    if info == 'enter':
        A.add(name)
    else:
        A.remove(name)

A = sorted(A, reverse=True)

for i in A:
    print(i)

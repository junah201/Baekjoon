a = [False for i in range(0, 31)]
for i in range(28):
    b = int(input())
    a[b] = True

for i in range(1, 31):
    if not a[i]:
        print(i)

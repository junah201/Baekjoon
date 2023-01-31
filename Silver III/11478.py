a = input()
b = dict()

for i in range(len(a)):
    for j in range(i, len(a)):
        b[a[i:j+1]] = 1

print(len(b))

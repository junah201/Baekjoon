A = []

X = 0
Y = 5

for _ in range(5):
    tmp = list(input())
    X = max(X, len(tmp))
    A.append(tmp)

for i in range(X):
    for j in range(Y):
        try:
            print(A[j][i], end="")
        except:
            pass

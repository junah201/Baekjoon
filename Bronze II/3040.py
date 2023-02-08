A = []
for _ in range(9):
    A.append(int(input()))

for i in range(9):
    for j in range(9):
        if i == j:
            continue
        if sum(A[:i] + A[i+1:j] + A[j+1:]) == 100:
            for k in A[:i] + A[i+1:j] + A[j+1:]:
                print(k)
            exit()

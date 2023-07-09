A, B = map(str, input().split())

A = int(A[::-1])
B = int(B[::-1])

print(int(str(A + B)[::-1]))

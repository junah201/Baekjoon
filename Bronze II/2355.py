A, B = map(int, input().split())

A, B = min(A, B), max(A, B)

print(B*(B+1)//2-A*(A-1)//2)

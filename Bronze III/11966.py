# 11966 2의 제곱인가?

N = int(input())

while N % 2 == 0:
    N /= 2

if N == 1:
    print("1")
else:
    print("0")
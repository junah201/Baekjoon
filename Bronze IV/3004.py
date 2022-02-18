# 3004 체스판 조각
# https://www.acmicpc.net/source/39269714

x = 1
y = 1
sum = 1

N = int(input())

for _ in range(N):
    if x > y:
        y += 1
        sum = x * y
    else:
        x += 1
        sum = x * y

print(sum)
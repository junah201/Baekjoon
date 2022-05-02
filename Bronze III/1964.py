# 1964 오각형, 오각형, 오각형...

n = int(input())

dot = 5

inc = 7

for i in range(1, n):
    dot += inc
    inc += 3

print(dot % 45678)
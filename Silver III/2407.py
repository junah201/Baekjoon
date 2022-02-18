# 2407 조합
# https://www.acmicpc.net/source/39266304

a, b = map(int, input().split())

def get(n):
    if n <= 1:
        return 1
    else:
        return n * get (n - 1)

print(int(get(a) // (get(b) * get(a - b))))
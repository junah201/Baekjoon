import sys
input = sys.stdin.readline

n = int(input())
a = [input().strip() for _ in range(n)]


def check1(a):
    for i in range(1, n):
        if a[i-1] >= a[i]:
            return False
    return True


def check2(a):
    for i in range(1, n):
        if a[i-1] <= a[i]:
            return False
    return True


if check1(a):
    print("INCREASING")
elif check2(a):
    print("DECREASING")
else:
    print("NEITHER")

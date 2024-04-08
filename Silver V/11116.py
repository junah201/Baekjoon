from operator import le
import sys
input = sys.stdin.readline

T = int(input())


def solve():
    N = int(input())
    left = list(map(int, input().split()))
    right = list(map(int, input().split()))

    left = [
        (i, "l")
        for i in left
    ]
    right = [
        (i, "r")
        for i in right
    ]

    arr = left + right

    left_cnt = 0
    right_cnt = 0

    for _ in range(N * 2 // 4):
        tmp = []
        min_val = min(arr)
        if min_val[1] == "l":
            tmp = [
                (min_val[0], "l"),
                (min_val[0] + 500, "l"),
                (min_val[0] + 1000, "r"),
                (min_val[0] + 1500, "r"),
            ]
            left_cnt += 1
        else:
            right_cnt += 1
            tmp = [
                (min_val[0], "r"),
                (min_val[0] + 500, "r"),
                (min_val[0] + 1000, "l"),
                (min_val[0] + 1500, "l"),
            ]

        pop_list = []

        for idx, val in enumerate(arr):
            if val in tmp:
                pop_list.append(val)

        for idx in pop_list:
            arr.remove(idx)

    print(left_cnt)


for _ in range(T):
    solve()

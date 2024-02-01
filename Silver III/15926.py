import sys

input = sys.stdin.readline


N = int(input())
I = list(input().rstrip())


def solve(Input: list[str]) -> int:
    ans = 0
    cnt = 0

    S = 0

    for now in Input:
        cnt += 1
        if now == '(':
            S += 1
        elif now == ')':
            if S == 0:
                cnt = 0
            else:
                S -= 1
                if S == 0:
                    ans = max(ans, cnt)

    return ans


ans = 0
ans = max(ans, solve(I))
ans = max(ans, solve(
    [
        "(" if k == ')' else ')'
        for k in I[::-1]
    ]
))


print(ans)

import sys
input = sys.stdin.readline

N = int(input())
S = [
    input().rstrip() for _ in range(N)
]


def get_sum(s: str) -> int:
    return sum(
        int(i) for i in list(s) if i.isdigit() == True
    )


S = sorted(
    S, key=lambda x: (len(x), get_sum(x), x)
)
print("\n".join(S))

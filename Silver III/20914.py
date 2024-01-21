import sys
from collections import deque

input = sys.stdin.readline

keyboard = {
    "A": ["Q", "W", "S", "Z"],
    "B": ["V", "G", "H", "N"],
    "C": ["X", "D", "F", "V"],
    "D": ["S", "E", "R", "F", "C", "X"],
    "E": ["W", "S", "D", "R"],
    "F": ["D", "R", "T", "G", "V", "C"],
    "G": ["F", "T", "Y", "H", "B", "V"],
    "H": ["G", "Y", "U", "J", "N", "B"],
    "I": ["U", "J", "K", "O"],
    "J": ["H", "U", "I", "K", "M", "N"],
    "K": ["J", "I", "O", "L", "M"],
    "L": ["K", "O", "P"],
    "M": ["N", "J", "K"],
    "N": ["B", "H", "J", "M"],
    "O": ["I", "K", "L", "P"],
    "P": ["O", "L"],
    "Q": ["W", "A"],
    "R": ["E", "D", "F", "T"],
    "S": ["A", "W", "E", "D", "X", "Z"],
    "T": ["R", "F", "G", "Y"],
    "U": ["Y", "H", "J", "I"],
    "V": ["C", "F", "G", "B"],
    "W": ["Q", "A", "S", "E"],
    "X": ["Z", "S", "D", "C"],
    "Y": ["T", "G", "H", "U"],
    "Z": ["A", "S", "X"],
}


def get_next(start: str, end: str) -> int:
    if start == end:
        return 0

    q = deque([(start, 0)])

    visited = [
        False for _ in range(30)
    ]
    visited[ord(start) - ord("A")] = True

    while len(q):
        now, idx = q.popleft()

        for n in keyboard[now]:
            if n == end:
                return idx + 2

            if visited[ord(n) - ord("A")]:
                continue

            visited[ord(n) - ord("A")] = True
            q.append((n, idx + 2))

    return -1


def solve():
    S = list(input().rstrip())

    ans = len(S)

    for i in range(len(S) - 1):
        ans += get_next(S[i], S[i+1])

    print(ans)


for _ in range(int(input())):
    solve()

from functools import cmp_to_key
import sys

dic = {
    "0": "0",
    "1": "1",
    "2": "2",
    "5": "5",
    "8": "8",
    "6": "9",
    "9": "6"
}


def rev(a: str) -> str:
    result = ""
    for i in a:
        result += dic[i]

    return result[::-1]


def cmp(a: str, b: str):
    if a == "0":
        return 1
    if b == "0":
        return -1

    is_a = True
    is_b = True

    idx_a = 0
    idx_b = 0

    len_a = len(a)
    len_b = len(b)

    while idx_a != len_a + len_b:
        if idx_a == len_a:
            is_a = 0
        if idx_b == len_b:
            is_b = 0

        if is_a:
            temp_a = a[idx_a]
        else:
            temp_a = b[idx_a - len_a]
        idx_a += 1

        if is_b:
            temp_b = b[idx_b]
        else:
            temp_b = a[idx_b - len_b]
        idx_b += 1

        if temp_a > temp_b:
            return -1
        elif temp_a < temp_b:
            return 1

    return 0


N = int(sys.stdin.readline())
Arr = list(sys.stdin.readline().split())
Arr = [rev(i) for i in Arr]

maxArr = ""
for i in Arr:
    if len(i) > len(maxArr):
        maxArr = i
    elif len(i) == len(maxArr):
        maxArr = max(maxArr, i)
Arr.append(maxArr)

Arr.sort(key=cmp_to_key(cmp))
Arr = Arr[::-1]

for i in Arr:
    print(rev(i), end="")

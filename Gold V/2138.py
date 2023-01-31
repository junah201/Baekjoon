import copy

N = int(input())

start = [bool(int(i)) for i in list(input())]
start.append(False)
end = [bool(int(i)) for i in list(input())]

tmp = copy.deepcopy(start)


def solve(start: list, k: bool):
    tmp = copy.deepcopy(start)
    ans = 0
    # 첫칸 누르기
    if k:
        tmp[0] = not tmp[0]
        tmp[1] = not tmp[1]
        ans += 1

    for i in range(1, len(start) - 1):
        # 전칸이 바뀌어야하면
        if tmp[i - 1] != end[i - 1]:
            tmp[i-1] = not tmp[i-1]
            tmp[i] = not tmp[i]
            tmp[i+1] = not tmp[i+1]
            ans += 1
            continue

    if tmp[:-1] == end:
        return ans

    return -1


def solve2(start: list):
    tmp = copy.deepcopy(start)
    ans = 0

    # 두번째칸 누르기
    tmp[0] = not tmp[0]
    tmp[1] = not tmp[1]
    tmp[2] = not tmp[2]
    ans += 1

    for i in range(2, len(start) - 1):
        # 전칸이 바뀌어야하면
        if tmp[i - 1] != end[i - 1]:
            tmp[i-1] = not tmp[i-1]
            tmp[i] = not tmp[i]
            tmp[i+1] = not tmp[i+1]
            ans += 1
            continue

    if tmp[:-1] == end:
        return ans

    return -1


a = solve(start, True)
b = solve(start, False)
c = solve2(start)

ans = [a, b, c]
ans = [i for i in ans if i != -1]

if not ans:
    print(-1)
    exit()


print(min(ans))

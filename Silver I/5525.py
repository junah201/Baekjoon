N = int(input())
M = int(input())
S = input()

ans = 0
cnt = 0
i = 0

while i < (M - 1):
    if S[i: i+3] == 'IOI':
        cnt += 1
        i += 2
        if cnt == N:
            ans += 1
            cnt -= 1
    else:
        i += 1
        cnt = 0

print(ans)

N = int(input())
M = int(input())
S = input()

cursor, count, result = 0, 0, 0

while cursor < (M - 1):
    if S[cursor:cursor + 3] == 'IOI':
        count += 1
        cursor += 2
        if count == N:
            result += 1
            count -= 1
    else:
        cursor += 1
        count = 0

print(result)

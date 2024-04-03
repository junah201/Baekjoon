from collections import deque

A = list(input().rstrip())
T = list(input().rstrip())
RA = A[::-1]

stack = deque()
for i in T:
    stack.append(i)
    # print(stack)

    if len(stack) < len(A):
        continue

    tmp = deque()

    for j in RA:
        if stack[-1] == j:
            tmp.appendleft(stack.pop())
        else:
            break
    else:
        continue

    for j in tmp:
        stack.append(j)

print("".join(stack))

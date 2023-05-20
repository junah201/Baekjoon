import sys

N = int(sys.stdin.readline())

input_list = [N]
for _ in range(N):
    input_list.append(int(sys.stdin.readline()))

if input_list[0] == 0:
    exit()

input_list.append(0)
ret = 0
stack = [[0, 0]]
for i in range(1, N + 2):
    while stack[-1][1] > input_list[i]:
        tmp_list = stack.pop()
        tmp_area = 0
        while stack[-1][1] == tmp_list[1]:
            stack.pop()
        tmp_area = max((i - 1 - stack[-1][0]) *
                       tmp_list[1], (i - tmp_list[0]) * tmp_list[1])
        if tmp_area > ret:
            ret = tmp_area
    stack.append([i, input_list[i]])
print(ret)

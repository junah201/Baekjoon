# 9935 문자열 폭발
# https://www.acmicpc.net/source/39288697

string = input()
boom = input()
boom_len = len(boom)

stack = []
temp = ""

for i in string:    
    stack.append(i)

    if len(stack) >= boom_len:
        temp = "".join(stack[-boom_len:])
        if temp == boom:
            for _ in range(boom_len):
                stack.pop()

print("".join(stack) or "FRULA")
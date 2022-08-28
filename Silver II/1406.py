앞스택 = list(input())
뒤스택 = []

for _ in range(int(input())):
    입력값 = list(input().split())
    if 입력값[0] == "L":
        if 앞스택:
            뒤스택.append(앞스택.pop())
    elif 입력값[0] == "D":
        if 뒤스택:
            앞스택.append(뒤스택.pop())
    elif 입력값[0] == "B":
        if 앞스택:
            앞스택.pop()
    elif 입력값[0] == "P":
        앞스택.append(입력값[1])

앞스택.extend(reversed(뒤스택))
print("".join(앞스택))

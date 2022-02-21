# 11656 접미사 배열
# https://www.acmicpc.net/source/39333900

string = input()
suffix = []

for i in range(len(string)):
    suffix.append(string[i:])
suffix.sort()
print("\n".join(suffix))
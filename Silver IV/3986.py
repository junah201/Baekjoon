#3986  좋은 단어

def check(string):
    if len(string)%2==1:
        return 0
    while "AA" in string or "BB" in string:
        if "AA" in string:
            string = string.replace("AA","")
        if "BB" in string:
            string = string.replace("BB","")

    if len(string)!=0:
        return 0
    return 1

N = int(input())
cnt = 0

for i in range(N):
    cnt+=check(input())

print(cnt)
    
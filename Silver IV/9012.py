#9012  괄호

def check(string:str):
    while True:
        if "()" in string:
            string = string.replace("()","")
        elif string == "":
            print("YES")
            break
        else:
            print("NO")
            break
    return 0

N:int = int(input())
for i in range(N):
    string:str = input()
    check(string)
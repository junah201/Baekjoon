# 5430 AC
# https://www.acmicpc.net/source/39217929

T = 0
cmd = ""
temp = ""
deque = []

def conduct():
    cmd = ""
    temp = ""
    deque = []

    cmd = input()
    input()
    deque = input()[1:-1]
    idx = 1
    if deque == "":
        deque = []
    else:
        deque = deque.split(",")

    for i in list(cmd):
        if i == "R":
            idx = not idx
        elif i == "D":
            if(deque):
                if(idx):
                    deque.pop(0)
                else:
                    deque.pop()
            else:
                print("error")
                return

    if idx == 0:
        deque.reverse()

    print("["+",".join(deque)+"]")

T = int(input())

while(T):
    T -= 1
    conduct()
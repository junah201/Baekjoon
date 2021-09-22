#1259  팰린드롬수

while True:
    N = input()
    if N=="0":
        break
    check = 1
    for i in range(int(len(N)/2)):
        if N[i] != N[len(N)-i-1]:
            print("no")
            check = 0
            break
    if check==1:
        print("yes")
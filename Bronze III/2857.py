check = False
for i in range(1, 6):
    if "FBI" in input():
        print(i, end=" ")
        check = True

if not check:
    print("HE GOT AWAY!")

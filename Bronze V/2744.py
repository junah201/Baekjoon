A = input()
for i in list(A):
    if i.isupper():
        print(i.lower(), end='')
    else:
        print(i.upper(), end='')

def rever(s: str):
    return s[::-1]


S = input()

start = 0
is_tag_open = False

for i in range(len(S)):
    if is_tag_open and S[i] == '>':
        is_tag_open = False
        print(S[start:i+1], end='')
        start = i+1
    else:
        if S[i] == '<':
            print(rever(S[start:i]), end='')
            is_tag_open = True
            start = i
        elif S[i] == ' ' and not is_tag_open:
            print(rever(S[start:i]), end=' ')
            start = i+1

if S[-1] != '>':
    print(rever(S[start:len(S)]), end='')

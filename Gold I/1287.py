orgin = input().rstrip()
new = ''
check = ''
if orgin.count('(') != orgin.count(')'):
    print("ROCK")
    exit()
if orgin.count('()') != 0:
    print("ROCK")
    exit()
for i in orgin:
    if i == '/':
        new += '//'
    else:
        new += i
    if i not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '(', ')']:
        check += '&'
    else:
        check += i

try:
    eval(check)
    print(eval(new))
except:
    print("ROCK")

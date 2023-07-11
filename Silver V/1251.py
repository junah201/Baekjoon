S = input()


def get_new_word(word, start, end):
    a = word[:start]
    b = word[start:end+1]
    c = word[end+1:]

    if a == '':
        raise Exception('a is empty')

    if b == '':
        raise Exception('b is empty')

    if c == '':
        raise Exception('c is empty')

    return a[::-1] + b[::-1] + c[::-1]


words = []

for i in range(len(S)):
    for j in range(i, len(S)):
        try:
            words.append(get_new_word(S, i, j))
        except:
            pass

words.sort()

print(words[0])

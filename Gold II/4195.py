T = int(input())

def find(a : int, p : list):
    if p[a] == a:
        return a
    p[a] = find(p[a], p)
    return p[a]

def uni(a : int, b : int, p: list):
    p[find(a, p)] = find(b, p)

def size(a : int, p : list):
    result  = 0
    for i in range(len(p)):
        if p[find(a, p)] == p[find(i, p)]:
            result += 1
    return result


for _ in range(T):
    N = int(input())
    names = {}
    p = []
    idx = 0
    for _ in range(N):
        A, B = input().split()
        if A not in names:
            names[A] = idx
            p.append(idx)
            idx += 1
        if B not in names:
            names[B] = idx
            p.append(idx)
            idx += 1
        uni(names[A], names[B], p) 


        print(size(names[A], p))    


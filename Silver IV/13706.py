#13706  제곱근

N = int(input())

def search():
    low = 1
    high = N
    while low<=high:
        mid = (low+high)//2
        if mid*mid==N:
            return mid
        elif mid*mid>N:
            high = mid
        else: 
            low = mid
    return -1

print(search())
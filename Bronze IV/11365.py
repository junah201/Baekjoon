while True:
    n = input()
    if n == "END":
        break
    print("".join(reversed(list(n))))

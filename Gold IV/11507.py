S = input()

card = {
    "P": set(),
    "K": set(),
    "H": set(),
    "T": set()
}

for i in range(0, len(S), 3):
    if S[i:i+3] in card[S[i]]:
        print("GRESKA")
        exit()
    card[S[i]].add(S[i:i+3])

for i in card:
    print(13 - len(card[i]), end=" ")

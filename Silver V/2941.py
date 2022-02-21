#2941  크로아티아 알파벳

string = input()
cnt = 0

for cr in ["c=","dz=","c-","d-","lj","nj","s=","z="]:
    while cr in string:
        string = string.replace(cr," ")

print(len(string))
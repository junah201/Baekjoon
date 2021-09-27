#4949  균형잡힌 세상

import re

def check(string:str):
    while True:
        if "()" in string:
            string = string.replace("()","")
        elif "[]" in string:
            string = string.replace("[]","")
        elif string == "":
            print("yes")
            return 0
        else:
            print("no")
            return 0

while True:
    temp = input()
    if(temp=="."):
        break
    string = ""
    for i in range(len(temp)):
        if(temp[i]=="(" or temp[i]==")" or temp[i]=="[" or temp[i]=="]"):
            string += temp[i]
    check(string)

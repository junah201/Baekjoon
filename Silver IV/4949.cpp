// 4949 균형잡힌 세상
// https://www.acmicpc.net/source/39285942

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string input;

int check() {
    stack <int> s;
    int len = input.length();
    for(int i=0;i<len;i++) {
        if(input[i] == '(') s.push(1);
        else if(input[i] == ')') {
            if(s.empty()) return 0;
            if(s.top() != 1) return 0;
            else s.pop();
        }
        else if(input[i] == '[') s.push(2);
        else if(input[i] == ']') {
            if(s.empty()) return 0;
            if(s.top() != 2) return 0;
            else s.pop();
        }
    }
    if(!s.empty()) return 0;
    return 1;
}

int main() {
    while(1) {
        getline(cin, input);
        if(input[0] == '.' && input[1] == '\0') return 0;
        if(check() == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
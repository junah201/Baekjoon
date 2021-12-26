//1181  단어 정렬

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str[20000];
char ward[51];

bool cmp(string a, string b) {
    if(a.size()==b.size()) return a<b;
    else return a.size()<b.size();
    return false;
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",ward);
        str[i] = ward;
    }
    sort(str, str+N, cmp);
    for(int i=0;i<N;i++) {
        if(str[i]!=str[i+1]) printf("%s\n",str[i].c_str());
    }
    return 0;
}
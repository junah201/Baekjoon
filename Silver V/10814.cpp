//10814  나이순 정렬

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

struct person
{
    int age;
    int idx;
    string name;
};

person people[100000];
int N;
char temp[101];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d %s",&people[i].age,temp);
        people[i].name = temp;
        people[i].idx = i;
    }

    sort(people, people+N, [](person a, person b) {
        if(a.age==b.age) return a.idx<b.idx;
        return a.age<b.age;
    });

    //출력
    for(int i=0;i<N;i++) {
        printf("%d %s\n",people[i].age,people[i].name.c_str());
    }
    return 0;
}
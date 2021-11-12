//10814  나이순 정렬

#include <stdio.h>
#include <string>

using namespace std;

int N;
string name[100000];
int age[100000];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d %s",&age[i],name[i].c_str());
    }

    for(int i=0;i<N-1;i++) {
        for(int j=0;j<N-1-i;j++) {
            if(age[j]>age[j+1]) {
                int temp=age[j];
                age[j]=age[j+1];
                age[j+1]=temp;

                string temp2=name[j];
                name[j]=name[j+1];
                name[j+1]=temp2;
            }
        }
    }

    //출력
    for(int i=0;i<N;i++) {
        printf("%d %s\n",age[i],name[i]);
    }
    return 0;
}
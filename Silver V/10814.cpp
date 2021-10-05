#include <stdio.h>
#include <string>

using namespace std;

int N;
int age[100000];
string name[100000];
int temp_age;
string temp_name[1];

int main() {
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d %s",&age[i],&name[i]);
    printf("111%d %s\n",age[1],name[1]);
    for(int i=N-1;i>0;i--) {
        for(int j=0;j<i;j++) {
            if(age[j]>age[j+1]) {
                temp_age=age[j];
                age[j]=age[j+i];
                age[j+1]=temp_age;
                temp_name[1]=name[j];
                name[j]=name[j+1];
                name[j+1]=temp_name[1];
            }
        }
    }
    
    for(int i=0;i<N;i++) printf("%d %s\n",age[i],name[i]);
    return 0;
}
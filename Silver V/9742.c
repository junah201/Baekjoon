//9742  순열

#include <stdio.h>
#include <string.h>

int N;
int count=0;
char str[11];
int check[11] = {0,};
char result[11];
int check2=1;

int get(int idx) {
	if(idx==strlen(str)) {
		count+=1;
		if(count==N) {
			printf("%s %d = %s\n",str, N, result);
			check2=0;
			return 1;
		}
		return 0;
	}
	for(int i=0;i<strlen(str);i++) {
		if(check[i]==0) {
			check[i]=1;
			result[idx]=str[i];
			get(idx+1);
			check[i]=0;
		}   
	}
	return 0;
}

int main() {
	while(scanf("%s %d",str,&N)!=EOF){
		count=0;
		check2=1;
		get(0);
		if(check2) {
			printf("%s %d = No permutation\n",str,N);
		};
	}
	return 0;
}

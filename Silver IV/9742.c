//9742  순열

#include <stdio.h>
#include <string.h>

char n[11]; //input
char r[11]; //result
int c[11]; //check
int i_cnt,r_cnt,len; //input, result, len
int fac[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};

int f(int idx) {
	if(idx==len) {
		r_cnt++;
		if(r_cnt==i_cnt) {
			printf("%s %d = %s\n",n,r_cnt,r);
		}
		return 0;
	}
	for(int i=0;i<len;i++) {
		if(c[i]==0) {
			r[idx] = n[i];
			c[i] = 1;
			f(idx+1);
			c[i] = 0;
		}
	}
	return 0;
}

int main() {
	while (scanf("%s %d", &n, &i_cnt) != EOF) {
		len = strlen(n);
		if(fac[len]<i_cnt) {
			printf("%s %d = No permutation\n",n,i_cnt);
			continue;
		}
		else {
			r_cnt = 0;
			f(0);
		}
		for(int i=0;i<len;i++) {
			n[i] = 0;
			r[i] = 0;
		}
		
	}
	return 0;
}
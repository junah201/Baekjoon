//9742  순열

#include <stdio.h>
#include <string.h>

char n[11]; //input
char r[11]; //result
int c[11]; //check
int i_cnt,r_cnt; //input, result
int len,not_print;

int f(int idx) {
	if(!not_print) return 0;
	if(idx==len) {
		r_cnt++;
		if(r_cnt==i_cnt) {
			printf("%s %d = %s\n",n,r_cnt,r);
			not_print = 0;
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
		r_cnt = 0;
		not_print=1;
		f(0);
		if(not_print) printf("%s %d = No permutation\n",n,r_cnt);
	}
	return 0;
}
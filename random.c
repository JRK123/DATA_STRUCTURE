#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int n, max;
	time_t tt;
	scanf("%d%d", &n, &max);
	srandom(time(&tt));
	int z = n, t;
	while(n) {
		t = z;
		while(t) {  
			printf("%ld ", random() % max);
			t--;
		}
		printf("\n");
		n--;
	}
	return 0;
}

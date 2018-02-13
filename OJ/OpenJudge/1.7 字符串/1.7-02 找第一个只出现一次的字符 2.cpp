#include <stdio.h>
#include <string.h>
char a[100000 + 10];
int main()
{
	int i = 0, j = 0, sum = 0;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		sum = 0;
		for (j = 0; j < strlen(a); j++) {
			if (a[i] == a[j]) {
				sum++;
			}
		}
		if (sum == 1) {
			printf("%c", a[i]);
			return 0;
		}
	}
	printf("no");
}

#include <cstdio>
#include <cstring>
int main()
{
	int n, i = 1, x, y;
	char S1[20], S2[20];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s ", S1);
		scanf("%s", S2);
		x = strlen(S1);
		y = strlen(S2);
		if (x == y) printf("Tie\n");
		else if (x - y == -4 || x - y == 3 || x - y == 1) printf("Player1\n");
		else printf("Player2\n");
	}
	return 0;
}
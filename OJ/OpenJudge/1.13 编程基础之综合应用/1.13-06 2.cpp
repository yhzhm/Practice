#include<bits/stdc++.h>
int main() {
	int num[1001], t = 1, other[1001], b[1001], OK = 0;
	char ch;
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
		num[t] = ch - 48;
		t++;
	}
	t -= 2;
	for (int i = 1; i <= t; i++)
	{
		memset(b, false, sizeof(b));
		memset(other, 0, sizeof(other));
		for (int j = t; j >= 1; j--)
		{
			other[j] += num[j] * i;
			other[j - 1] = other[j] / 10;
			other[j] %= 10;
		}
		for (int x = 1; x <= t; x++)
			for (int y = 1; y <= t; y++)
				if (other[(y + x) % t + 1] != num[y])
					b[x] = true;
		for (int x = 1; x <= t; x++)
			if (b[x] == false)
			{
				OK++;//成功一次累加1
				break;
			}
	}
	if (OK == t)//判断是否t次都成功
		printf("1");
	else
		printf("0");
}
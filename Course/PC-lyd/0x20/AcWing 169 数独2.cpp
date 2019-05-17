// Created by Hz Yang on 2019.05
#include <iostream>
#include <cstring>
using namespace std;

char map[16][16];
int table[16][16], cnt;

void change(int x, int y, int a)
{
	cnt++;
	map[x][y] = a;
	int d = 1 << (a - 1);
	for (int i = 0; i < 16; ++i)
		table[x][i] |= d, table[i][y] |= d;
	int r = x / 4 * 4, c = y / 4 * 4;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			table[r + i][c + j] |= d;
}

bool dfs()
{
	char t_map[16][16];
	int t_table[16][16], t_cnt;
	int r, flag, t0, t, r1, r2;

	if (cnt == 256) return true;

	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j) {
			if (map[i][j]) continue;
			r = -1;
			for (int k = 0; k < 16; ++k) {
				bool state = table[i][j] & (1 << k);
				if ( !state  && r == -1) r = k;
				else if (!state && r != -1) {r = -2; break;}
			}
			if (r == -1) return false;
			else if (r != -2) change(i, j, r + 1);
		}

	for (int i = 0; i < 16; ++i)
		for (int k = 0; k < 16; ++k) {
			r = -1;
			for (int j = 0; j < 16; ++j) {
				if (map[i][j] == k + 1) {r = -2; break;}
				if (map[i][j]) continue;
				bool state = table[i][j] & (1 << k);
				if (!state && r == -1) r = j;
				else if (!state && r != -1) {r = -2; break;}
			}
			if (r == -1) return 0;
			else if (r != -2) change(i, r, k + 1);
		}

	for (int j = 0; j < 16; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			r = -1;
			for (int i = 0; i < 16; i++)
			{
				if (map[i][j] == k + 1) { r = -2; break; }
				if (map[i][j]) continue;
				if (((table[i][j] & (1 << k)) == 0) && r == -1) r = i;
				else if (((table[i][j] & (1 << k)) == 0) && r != -1) { r = -2; break; }
			}
			if (r == -1) return 0;
			else if (r != -2) change(r, j, k + 1);
		}
	}

	for (int r = 0; r < 16; r += 4)
		for (int c = 0; c < 16; c += 4)
			for (int k = 0; k < 16; k++) {
				r1 = -1, r2 = -1;
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
					{
						if (map[r + i][c + j] == k + 1) {
							r1 = r2 = -2;
							if (r1 == -1) return 0;
							else if (r1 != -2) change(r1, r2, k + 1);
						}
						if (map[r + i][c + j]) continue;
						if (((table[r + i][c + j] & (1 << k)) == 0) && r1 == -1) r1 = r + i, r2 = c + j;
						else if (((table[r + i][c + j] & (1 << k)) == 0) && r1 != -1)
						{	r1 = r2 = -2;
							if (r1 == -1) return 0;
							else if (r1 != -2) change(r1, r2, k + 1);
						}
					}

			}

	if (cnt == 256) return 1;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			t_map[i][j] = map[i][j];
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			t_table[i][j] = table[i][j];
	}
	t_cnt = cnt;

	t0 = 256;
	for (int i = 15; i >= 0; i--)
	{
		for (int j = 15; j >= 0; j--)
		{
			if (map[i][j]) continue;
			t = 0;
			for (int k = 0; k < 16; k++)
			{
				if ((table[i][j] & (1 << k)) == 0) t++;
				if (t >= t0) break;
			}
			if (t < t0)
			{
				t0 = t;
				r1 = i, r2 = j;
			}
			break;
		}
	}

	for (int m = 0; m < 16; m++)
	{
		if ((table[r1][r2] & (1 << m)) == 0)
		{
			change(r1, r2, m + 1);
			flag = dfs();
			if (flag == 1) return 1;
			else
			{
				for (int i = 0; i < 16; i++)
				{
					for (int j = 0; j < 16; j++)
						map[i][j] = t_map[i][j];
				}
				for (int i = 0; i < 16; i++)
				{
					for (int j = 0; j < 16; j++)
						table[i][j] = t_table[i][j];
				}
				cnt = t_cnt;
			}
		}
	}

	return 0;

}




int main()
{
	char str[20];
	while (true) {
		memset(map, 0, sizeof map);
		memset(table, 0, sizeof table);
		cnt = 0;

		for (int i = 0; i < 16; ++i) {
			if (scanf("%s", str) != 1) goto end;
			for (int j = 0; j < 16; ++j) {
				char a = str[j];
				if (a == '-') continue;
				else change(i, j, a - 64);
			}
		}

		dfs();
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
				printf("%c", map[i][j] + 64);
			printf("\n");
		} printf("\n");
	}
end:
	return 0;
}
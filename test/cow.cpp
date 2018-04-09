// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

char a[ 160 ][ 160 ];
int m, n, x1, y1, flag;

void dfs( int dep, int x, int y )
{
	// cout << x << ' ' << y << endl;
	if ( a[x][y] == 'H' ) {flag = 1; cout << dep; return;}
	a[x][y] = '*';
	for ( int i = 0; i < 8; i ++ )
		if ( !flag && a[ x + dx[i]][ y + dy[i] ] != '*' )
			dfs( dep + 1, x + dx[ i ], y + dy[ i ] );
}

int main( void )
{
	cin >> m >> n;
	memset(a, 42, sizeof(a));//初始化为'*'
	for ( int i = 1 + 1; i <= n + 1; i ++ ) {
		for ( int j = 1 + 1; j <= m + 1; j ++ ) {
			cin >> a[i][j];
			if ( a[ i ][ j ] == 'K' ) {x1 = i; y1 = j;}
		}
	}
	dfs( 0, x1, y1);
	return 0;
}
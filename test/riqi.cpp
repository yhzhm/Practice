#include<bits/stdc++.h>
using namespace std;
int a[12]= {31,28,31,30,31,30,31,31,30,31,30,31},ans[10];
int main () {
//	freopen("riqi.in","r",stdin);
//	freopen("riqi.out","w",stdout);
	int ne=6;
	int n,end,i,j;
	scanf ("%d",&n);
	end=1900+n;
	for (i=1900; i<end; i++) {
		if (i%4==0&&(i%100!=0||i%400==0)) {
			a[1]=29;
		} else {
			a[1]=28;
		}
		for (j=0; j<12; j++) {
			ans[ne-1]++;
			ne=(ne+a[j])%7;
			if (ne==0) {
				ne=7;
			}
		}
	}
	for (i=0; i<7; i++) {
		printf ("%d ",ans[i]);
	}
	return 0;
}

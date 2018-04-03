#include <bits/stdc++.h>
using namespace std;
int a[10010],l,r,mid;
int n,k;
int check(int x)
{
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=a[i]/x;
	}
	return sum;
}
int main()
{
	cin>>n>>k;
	int maxn=0;
	double x;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x*100;
		maxn=max(maxn,a[i]);
	}
	l=0;r=maxn+1;//maxn的值需加1 
	while(r-l>1){
		mid=(l+r)/2;
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		if(check(mid)>=k)l=mid;
		else r=mid;
	}
	printf("%.2f\n",l/100.00);
	return 0;
}


#include<stdio.h>
int main(){
	int a[505];
	int n,i,j,k=1,t,first=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		if(t%2==1) a[k++]=t;
	}
	k--;
	for(i=1;i<=k-1;i++){
		for(j=i+1;j<=k;j++){
			if(a[i]>a[j]){
				t=a[i];a[i]=a[j];a[j]=t;
			}
		}
	}
	for(i=1;i<=k;i++){
		if(first) first=0;else printf(",");
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
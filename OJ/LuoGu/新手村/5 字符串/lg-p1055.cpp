#include <stdio.h>
int check(int a[])
{
	int sum=0;
	for(int i=0;i<10-1;i++){
		sum+=(i+1)*a[i];
	}
	return sum%11;
}

int main()
{
	char a[13],z;
	int b[10],j=0,y;
	scanf("%s",a);
	for(int i=0;i<13-1;i++)
		if(a[i]!='-') b[j++]=a[i]-'0';
	y=check(b);
	z=(y==10)?'X':y+'0';
	if(z==a[12]) printf("Right\n");
	else{
		a[12]=z;
		printf("%s\n",a);
	}
	return 0;	
}

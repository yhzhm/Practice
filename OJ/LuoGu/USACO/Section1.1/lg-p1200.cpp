#include <cstdio>
int check(char a[])
{
	int sum=1;
	for(int i=0;a[i]!='\0';i++){
		sum*=a[i]-'A'+1;
	}
	return sum;
}
int main()
{
	char a1[7],a2[7];
	scanf("%s %s",a1,a2);
	if(check(a1)%47==check(a2)%47) printf("GO");
	else printf("STAY");
	return 0;
}

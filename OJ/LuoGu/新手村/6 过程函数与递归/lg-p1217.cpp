#include <cstdio>
#include <cstring>
#include <cmath>
bool hw(int n)//�ж��Ƿ��ǻ����� 
{
	int s=0,d=n;
	while(d!=0){
		s=s*10+d%10;
		d/=10;
	}
	return (s==n)?true:false;
}
bool palindrome(int n)//������ת�����ַ����ж��Ƿ������ 
{
	char c[10],j=0,k=0;
	sprintf(c,"%d",n);
	k=strlen(c)-1;
	while(j<k){
		if(c[j++]!=c[k--]) return false;
	}
	return true;
}
bool prime(int n)
{
	if(n<2) return false;
	else if(n==2) return true;
	for(int div=2;div<=sqrt(n);div++){
		if(n%div==0) return false;
	}
	return true;
}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	a+=!(a%2);//a��ż��+1��a������+0��ͦ����˼��д�� 
	b=(b>9999999)?9999999:b;//��֦7λ���ϵ����֣���Ϊż��λ��������11�ı������϶���������������8λ�����������ж� 
	for(int i=a;i<=b;i+=2){
//		if((i>=1001&&i<=9999)||(i>=100001&&i<=999999)) continue;
//		if(i==1001) i=10001;
//		if(i==100001) i=1000001; 
//		if(i>9999999) break;//������֦�Ż�����Ч�����һ�����Ե� 
		if(hw(i) && prime(i)) printf("%d\n",i);//�Ȼ��ģ������� 
//		if(palindrome(i) && prime(i)) printf("%d\n",i);
	}	
	return 0;
}



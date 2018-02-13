#include <cstdio>
#include <cstring>
#include <cmath>
bool hw(int n)//判断是否是回文数 
{
	int s=0,d=n;
	while(d!=0){
		s=s*10+d%10;
		d/=10;
	}
	return (s==n)?true:false;
}
bool palindrome(int n)//将数字转换成字符，判断是否回文数 
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
	a+=!(a%2);//a是偶数+1，a是奇数+0，挺有意思的写法 
	b=(b>9999999)?9999999:b;//剪枝7位以上的数字，因为偶数位回文数是11的倍数，肯定不是质数，所以8位回文数不用判断 
	for(int i=a;i<=b;i+=2){
//		if((i>=1001&&i<=9999)||(i>=100001&&i<=999999)) continue;
//		if(i==1001) i=10001;
//		if(i==100001) i=1000001; 
//		if(i>9999999) break;//这条剪枝优化最有效，最后一个测试点 
		if(hw(i) && prime(i)) printf("%d\n",i);//先回文，再质数 
//		if(palindrome(i) && prime(i)) printf("%d\n",i);
	}	
	return 0;
}



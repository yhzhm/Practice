#include<bits/stdc++.h>
int m[25][25][25];//���仯��������ά����
int w(long long a,long long b,long long c) { //��ֹ���ȫ����long long
	if(a<=0||b<=0||c<=0) return 1;  //���ܵ�������Խ�磬�������ų� 
	if(a>20||b>20||c>20) return w(20,20,20);
	if(m[a][b][c]) 	return m[a][b][c]; //��ȡ�������Ƿ�����Ѿ���¼�õ���ֵ��ֱ�ӷ���
	else if(a<b&&b<c) m[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else m[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return m[a][b][c];
}
int main() {
	while(1) {
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)break;
		memset(m,0,sizeof(m));
		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w(a,b,c));
	}
}

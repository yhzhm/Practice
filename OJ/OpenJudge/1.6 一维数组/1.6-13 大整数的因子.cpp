/*
13:������������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪������k����2<=k<=9���ָ����������Ϊ30λ��ʮ���ƷǸ�����c��������������c��k��

����
һ���Ǹ�����c��c��λ��<=30��
���
���������� c%k == 0 ��k����С�����������������k������������֮���õ����ո��������û��������k�������"none"��
��������
30
�������
2 3 5 6
*/

#include<cstdio>
#include<cstring>
int main()
{
	int a[35],lenc,i,j,x,flag=0;
	char c[35];
	gets(c);
	lenc=strlen(c);
	for(i=0;i<lenc;i++) a[lenc-i]=c[i]-'0';
	for(i=2;i<=9;i++){
		x=0;
		for(j=lenc;j>=1;j--)
			x=(x*10+a[j])%i;
		if(x==0){
			flag=1;
			printf("%d ",i);
		}
	}
	if(flag==0) printf("none");
	return 0;	
}

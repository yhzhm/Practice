/*
10:�������ӷ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
������������200λ�ķǸ������ĺ͡�

����
�����У�ÿ����һ��������200λ�ķǸ������������ж����ǰ��0��
���
һ�У�����Ӻ�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��
��������
22222222222222222222
33333333333333333333
�������
55555555555555555555
*/

#include <cstdio>
#include <cstring> 
int main()
{
	const int MAX=200+5; 
	char a1[MAX],b1[MAX];
	int a[MAX],b[MAX],c[MAX],lena,lenb,lenc,i,x;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(i=0;i<lena;i++) a[lena-i]=a1[i]-'0';
	for(i=0;i<lenb;i++) b[lenb-i]=b1[i]-'0';
	lenc=1;x=0;
	while(lenc<=lena || lenc<=lenb){
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	while(c[lenc]==0 && lenc>1) lenc--;
	for(i=lenc;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}

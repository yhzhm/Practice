/*
12:����2��N�η�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�������һ��������N(N<=100)������2��n�η���ֵ��
����
����һ��������N��
���
���2��N�η���ֵ��
��������
5
�������
32
��ʾ
�߾��ȼ���
*/

#include<cstdio>
#include<cstring>
int main()
{
	int a[205],len,i,j,n;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	a[1]=1;len=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=len;j++)
			a[j]*=2;
		for(j=1;j<=len;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		if(a[len+1]>0) len++;
	}
	for(i=len;i>=1;i--)
		printf("%d",a[i]);
	return 0;	
}


/*
44:��nС������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ��������n�����nС��������

����
һ��������10000��������n��
���
��nС��������
��������
10
�������
29
*/


#include <stdio.h>
#include <math.h>
int main()
{
	long long i,j,a;
	int n,f,c,sum=0; 
	scanf("%d",&n);
	for(i=2;;i++){
		f=1;
		for(j=2;j<=(long long)sqrt(i);j++){
			if(i%j==0) {f=0;break;}	
		}
		if(f) {
		c=i;
		sum++;
		}
		if(sum==n) break;
	}
	printf("%d",c);		
	return 0;
}


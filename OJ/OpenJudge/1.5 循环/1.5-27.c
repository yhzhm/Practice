/*
27:�������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪��Sn= 1��1��2��1��3������1��n����Ȼ��������һ������K����n�㹻���ʱ��Sn����K��

�ָ���һ������K��1<=k<=15����Ҫ������һ����С��n��ʹ��Sn��K��

����
һ������K��
���
һ������n��
��������
1
�������
2
*/

#include <stdio.h>
int main()
{
	int i=0,k,n;
	double sn=0;
	scanf("%d",&k);
	while(sn<=k){
		sn+=1.0/++i;
	}
	printf("%d",i);
	return 0;
}

#include <stdio.h>
int main()
{
	int i,k,n;
	double sn=0;
	scanf("%d",&k);
	for (i=1;;i++){
		sn+=1.0/i;
		if (sn>k) {
		printf("%d",i);
		break;
		}
	}
	return 0;
}

/*
01:�ж�������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ������N���ж���������



����
һ������N(-109 <= N <= 109)
���
���N > 0, ���positive;
���N = 0, ���zero;
���N < 0, ���negative
��������
1
�������
positive
*/

#include <stdio.h>
int main()
{
	long long a;
	scanf("%lld", &a);
	if (a>0) printf("positive");
	else if (a==0) printf("zero");
	else printf("negative");		
	return 0;
}

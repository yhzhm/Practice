/*
20:����2����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�����Ǹ�����n����2n��

����
һ������n��0 <= n < 31��
���
һ����������2��n�η���
��������
3
�������
8
*/

#include <stdio.h>
#include <math.h>
int main()
{
	long long n, a;
	scanf("%lld", &n);
	a = pow(2,n);
	printf("%lld", a);
	return 0;
}

/*
04:��żASCIIֵ�ж�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��������һ���ַ����ж���ASCII�Ƿ������������ǣ����YES���������NO 
���磬�ַ�A��ASCIIֵ��65�������YES���������ַ�B(ASCIIֵ��66)�������NO

����
����һ���ַ�
���
�����ASCIIֵΪ�����������YES���������NO
��������
A
�������
YES
*/

#include <stdio.h>
int main()
{
	char c;
	int a;
	scanf("%c", &c);
	a=c;
	if (a%2==1) printf("YES");
	else printf("NO");		
	return 0;
}

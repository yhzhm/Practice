/*
01:ͳ�������ַ�����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ���ͳ�Ƴ����������ַ��ĸ�����

����
һ���ַ������ܳ��Ȳ�����255��
���
���Ϊ1�У�����ַ������������ַ��ĸ�����
��������
Peking University is set up at 1898.
�������
4
*/

#include <cstdio>
#include <cstring>
int main()
{
	char c[255 + 5]; int sum = 0;
	gets(c);
	int len = strlen(c);
	for (int i = 0; i < len; ++i)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}

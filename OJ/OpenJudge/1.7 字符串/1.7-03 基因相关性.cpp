/*
03:���������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
Ϊ�˻�֪���������ڹ��ܺͽṹ�ϵ������ԣ�������Ҫ��������ͬ���е�DNA���бȶԣ����жϸñȶԵ�DNA�Ƿ��������ԡ�

�ֱȶ�����������ͬ��DNA���С����ȶ�������DNA������ͬλ�õļ��Ϊһ������ԣ����һ��������е����������ͬ�Ļ������Ϊ��ͬ����ԡ����ż�����ͬ�����ռ�ܼ���������ı���������ñ������ڵ��ڸ�����ֵʱ���ж�������DNA��������صģ�������ء�

����
�����У���һ���������ж�������DNA�����Ƿ���ص���ֵ�����2��������DNA���У����Ȳ�����500����
���
������DNA������أ��������yes�������������no����
��������
0.85
ATCGCCGTAAGTAACGGTTTTAAATAGGCC
ATCGCCGGAAGTAACGGTCTTAAATAGGCC
�������
yes
*/

#include <cstdio>
#include <cstring>
int main()
{
	int sum = 0, i = 0, len;
	double n;
	char a[500 + 10], b[500 + 10];
	scanf("%lf\n", &n);
	gets(a);
	gets(b);
	len = strlen(a);
	for (i = 0; i < len; i++) {
		if (a[i] == b[i]) sum++;
	}
	if ((double)sum / len >= n) printf("yes");
	else printf("no");
	return 0;
}

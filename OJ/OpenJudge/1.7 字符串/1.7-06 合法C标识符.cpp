/*
06:�Ϸ� C ��ʶ��
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���������հ׷����ַ��������ж��Ƿ���C���ԺϷ��ı�ʶ���ţ�ע����Ŀ��֤��Щ�ַ���һ������C���Եı����֣���

C���Ա�ʶ��Ҫ��

1. �Ǳ����֣�

2. ֻ������ĸ�����ּ��»��ߣ���_������

3. �������ֿ�ͷ��

����
һ�У�����һ���ַ������ַ����в������κοհ��ַ����ҳ��Ȳ�����20��
���
һ�У��������C���ԵĺϷ���ʶ���������yes���������no��
��������
RKPEGX9R;TWyYcp
�������
no
*/


// Created by Hz Yang on 2017.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[25];
	gets(s);
	int len = strlen(s), flag = 1;
	if (isdigit(s[0])) flag = 0;
	else
		for (int i = 0; i < len; ++i)
		{
			if (isalnum(s[i]) || s[i] == '_')
				continue;
			flag = 0;
			break;
		}
	if (flag) printf("yes");
	else printf("no");
	return 0;
}

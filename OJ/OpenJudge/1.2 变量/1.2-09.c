/*
08:��ӡ�ַ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ��ASCII�룬�����Ӧ���ַ���

����
һ�����������ַ���ASCII�룬��֤���ڶ�Ӧ�Ŀɼ��ַ���
���
һ�У�������Ӧ���ַ���
��������
65
�������
A
*/

//#include <stdio.h>
//int main()
//{
//	_Bool a;
//	int b;
//	scanf("%d",&b);
//	a = b;
//	b = a;
//	printf("%d",b);
//	return 0;
//}


#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",(int)(_Bool)a);
	return 0;
}

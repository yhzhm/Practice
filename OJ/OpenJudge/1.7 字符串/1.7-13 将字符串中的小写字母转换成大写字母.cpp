/*
13:���ַ����е�Сд��ĸת���ɴ�д��ĸ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ��������������е�Сд��ĸת���ɴ�д��ĸ��

����
����һ�У�����һ���ַ��������Ȳ�����100�����ܰ����ո񣩡�
���
���ת������ַ�����
��������
helloworld123Ha
�������
HELLOWORLD123HA
*/

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
int main()
{
	int i=0;
	char a[100+10];
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(islower(a[i])) a[i]=toupper(a[i]);
	}
	printf("%s",a);
	return 0;
}

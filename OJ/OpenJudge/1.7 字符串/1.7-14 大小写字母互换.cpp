/* 
14:��Сд��ĸ����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��һ���ַ��������г��ֵĴ�д��ĸ���滻��Сд��ĸ��ͬʱ��Сд��ĸ�滻�ɴ�д��ĸ��

����
����һ�У����������ַ�����
���
���һ�У���ɻ������ַ������ַ�������С��80����
��������
If so, you already have a Google Account. You can sign in on the right. 
�������
iF SO, YOU ALREADY HAVE A gOOGLE aCCOUNT. yOU CAN SIGN IN ON THE RIGHT.
*/

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
int main()
{
	int i=0;
	char a[80+10];
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(islower(a[i])) a[i]=toupper(a[i]);
		else if(isupper(a[i])) a[i]=tolower(a[i]);
	}
	printf("%s",a);
	return 0;
}

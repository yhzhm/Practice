/*
10:������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
Julius Caesar����ʹ�ù�һ�ֺܼ򵥵����롣���������е�ÿ���ַ�������������ĸ���к�5λ��Ӧ���ַ������棬�����͵õ������ġ������ַ�A��F�����档���������ĺ��������ַ��Ķ�Ӧ��ϵ��

����
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

����
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

��������ǶԸ��������Ľ��н��ܵõ����ġ�

����Ҫע����ǣ������г��ֵ���ĸ���Ǵ�д��ĸ��������Ҳ��������ĸ���ַ�������Щ�ַ����ý��н��롣

����
һ�У��������ģ����Ĳ�Ϊ�գ��������е��ַ���������200��
���
���һ�У������Ķ�Ӧ�����ġ�
��������
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
�������
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char a[200 + 10];
	int i = 1;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (isalpha(a[i]))
			if (a[i] - 'A' - 5 >= 0) a[i] -= 5;
			else a[i] += 21;
	}
	printf("%s", a);
	return 0;
}

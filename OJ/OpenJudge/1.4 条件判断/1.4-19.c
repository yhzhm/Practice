/*
19:�򵥼�����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
һ����򵥵ļ�������֧��+, -, *, / �������㡣���迼���������Ϊ��������������ݺ����������ᳬ��int��ʾ�ķ�Χ��

����
����ֻ��һ�У������������������е�1��2������Ϊ��������3������Ϊ��������+,-,*,/����
���
���ֻ��һ�У�һ��������Ϊ��������Ȼ����
1. ������ֳ���Ϊ0��������������Divided by zero!
2. ���������Ч�Ĳ�����(����Ϊ +, -, *, / ֮һ�����������Invalid operator!
��������
1 2 +
�������
3
*/


//#include <stdio.h>
//int main()
//{
//	int a,b;
//	char c;
//	scanf("%d %d %c",&a,&b,&c);
//	switch (c){
//		case '+' : printf("%d",a+b);
//				   break;
//		case '-' : printf("%d",a-b);
//				   break;
//		case '*' : printf("%d",a*b);
//				   break;
//		case '/' : if (b==0) printf("Divided by zero!");
//				   else printf("%d",a/b);
//				   break;
//		default  : printf("Invalid operator!");		 
//				   break;
//				 
//	}
//	
//	return 0;
//}


#include <stdio.h>
int main()
{
	int a,b;
	char c;
	scanf("%d %d %c",&a,&b,&c);
	if (c=='+') printf("%d",a+b);
	else if (c=='-') printf("%d",a-b);
	else if (c=='*') printf("%d",a*b);
	else if (c=='/') {
			if (b==0) printf("Divided by zero!");
			else printf("%d",a/b);
			}
	else printf("Invalid operator!");		 
	return 0;
}

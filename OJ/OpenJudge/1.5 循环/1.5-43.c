/*
43:�������ֽ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪������ n ��������ͬ�������ĳ˻���������ϴ���Ǹ�������

����
����ֻ��һ�У�����һ�������� n��

����60%�����ݣ�6 �� n �� 1000��
����100%�����ݣ�6 �� n �� 2*10^9��
���
���ֻ��һ�У�����һ�������� p�����ϴ���Ǹ�������
��������
21
�������
7
=================
��Ϊ��Ŀ�Ѿ�����n�����������Ļ���
�����жϳ�һ��ָ���󣬵ڶ��������жϣ���Ȼ��ʱ 
*/


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	long long n,i,j,k,a,b,max=0;
//	_Bool f;
//	scanf("%lld",&n);
//	a=(long long)sqrt(n);
////	printf("%lld\n",a);
//	for (i=2;i<=a;i++){
//		if(n%i==0){
//			f=1;
//			for(j=2;j<=i-1;j++){
//				if(i%j==0) {f=0;break;}
//			}
//			if(f){
//				b=n/i;
//				for(k=2;k<=b-1;k++){
//					if(b%k==0){f=0;break;}
//				}
//			}
//			if(f) {
//				i=(i>b)?i:b;
//				max=(max>i)?max:i;
//			}
//		}
//		
//	}
//	printf("%lld",max);
//	return 0;
//}


#include <stdio.h>
#include <math.h>
int main()
{
	long long n,i,j,a,max=0;
	_Bool f;
	scanf("%lld",&n);
	a=sqrt(n);
	for (i=2;i<=a;i++){
		if(n%i==0){
			f=1;
			for(j=2;j<=i-1;j++){
				if(i%j==0) {f=0;break;}
			}
			if(f) {	
				i=(i>n/i)?i:n/i;
				max=(max>i)?max:i;
			}
		}
		
	}
	printf("%lld",max);
	return 0;
}


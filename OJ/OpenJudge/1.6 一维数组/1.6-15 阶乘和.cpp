/*
15:�׳˺�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�ø߾��ȼ����S=1!+2!+3!+��+n!��n��50��

���С�!����ʾ�׳ˣ����磺5!=5*4*3*2*1��

����������N�����������S��

����
һ��������N��
���
������S��
��������
5
�������
153
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,a[10005],b[10005],lena,lenb,i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n;
	a[1]=1;lena=1;b[1]=0;lenb=1;
	for (i=1;i<=n;++i){
		for (j=1;j<=lena;++j){
			a[j]*=i;b[j]+=a[j];
		}
		for (j=1;j<=lena;++j){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		for (j=1;j<=lenb;++j){
			b[j+1]+=b[j]/10;
			b[j]%=10;
		}
		while (a[lena+1]>0) {
			++lena;
			a[lena+1]+=a[lena]/10;
			a[lena]%=10;
		}
		while (b[lenb+1]>0) {
			++lenb;
			b[lenb+1]+=b[lenb]/10;
			b[lenb]%=10;
		}		
	}
	for (i=lenb;i>=1;i--)
	  cout<<b[i];
	cout<<endl;
	return 0;
}

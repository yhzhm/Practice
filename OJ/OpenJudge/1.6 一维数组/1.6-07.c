/*
07:��Ȥ����Ծ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
һ������Ϊn��n>0���������д��ڡ���Ȥ����Ծ����ǰ��������Ԫ�صĲ�ľ���ֵ��������������Ǵ�1��(n-1)�����磬1 4 2 3���ڡ���Ȥ����Ծ������Ϊ��ľ���ֵ�ֱ�Ϊ3,2,1����Ȼ���κ�ֻ��������Ԫ�ص�����һ�����ڡ���Ȥ����Ծ��������Ҫдһ�������ж����������Ƿ���ڡ���Ȥ����Ծ����

����
һ�У���һ������n��0 < n < 3000����Ϊ���г��ȣ���������n������������Ϊ�����и�Ԫ�أ���Ԫ�صľ���ֵ��������1,000,000,000��
���
һ�У��������д��ڡ���Ȥ����Ծ�������"Jolly"���������"Not jolly"��
��������
4 1 4 2 3
�������
Jolly
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,k,i,a[10005],b[10005],sum=0;
	cin>>n;
	memset(b,0,sizeof(b));//b�ĳ�ֵΪ0��
	for (i=1;i<=n;++i) cin>>a[i];
	for (i=2;i<=n;++i) {
		k=abs(a[i]-a[i-1]);// �þ���ֵ���ǰһ���Ĳ�
		if (k<n)b[k]=1;
	}
	for (i=1;i<=n-1;++i) sum+=b[i];//ͳ��1�ĸ�����1��ʾ���Ǹ��
	if (sum==n-1) cout<<"Jolly";
	 else cout<<"Not jolly";
	return 0;
}

////
//// Created by haizhong on 17/2/7.
////
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int n,x;
//    vector<int> v;
//    cin>>n;
//    if(n==1) {cout<<"Jolly";return 0;}
//    for(int i=0;i<n;++i){
//        cin>>x;
//        v.push_back(x);
//    }
//    for(vector<int>::iterator i=v.begin();i!=v.end();++i){
//        *i=abs(*(i+1)-*i);
//    }
////    for(vector<int>::size_type i=0;i!=v.size();++i){
////        v[i]=abs(v[i+1]-v[i]);
////    }
//    v.pop_back();
//    if(v.size()==1) {cout<<"Jolly";return 0;}
//    else{
//        sort(v.begin(),v.end());
////        for(vector<int>::iterator i=v.begin()+1;i!=v.end();++i){
////            if(*i-*(i-1)!=1) {cout<<"Not jolly";return 0;}
////        }
//        for(vector<int>::size_type i=0;i!=v.size();++i){
//            if(v[i]!=i+1) {cout<<"Not jolly";return 0;}
//        }
//        cout<<"Jolly";
//    }
//    return 0;
//}
//
//
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int n,x;
//    vector<int> v;
//    cin>>n;
//    if(n==1) {cout<<"Jolly";return 0;}
//    for(int i=0;i<n;++i){
//        cin>>x;
//        v.push_back(x);
//    }
//    for(vector<int>::iterator i=v.begin();i!=v.end();++i){
//        *i=abs(*(i+1)-*i);
//    }
//    v.pop_back();
//    if(v.size()==1) {cout<<"Jolly";return 0;}
//    else{
//        sort(v.begin(),v.end());
//        for(vector<int>::iterator i=v.begin()+1;i!=v.end();++i){
//            if(*i-*(i-1)!=1) {cout<<"Not jolly";return 0;}
//        }
//        cout<<"Jolly";
//    }
//    return 0;
//}

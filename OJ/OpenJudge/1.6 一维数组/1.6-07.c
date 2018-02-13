/*
07:有趣的跳跃
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一个长度为n（n>0）的序列中存在“有趣的跳跃”当前仅当相邻元素的差的绝对值经过排序后正好是从1到(n-1)。例如，1 4 2 3存在“有趣的跳跃”，因为差的绝对值分别为3,2,1。当然，任何只包含单个元素的序列一定存在“有趣的跳跃”。你需要写一个程序判定给定序列是否存在“有趣的跳跃”。

输入
一行，第一个数是n（0 < n < 3000），为序列长度，接下来有n个整数，依次为序列中各元素，各元素的绝对值均不超过1,000,000,000。
输出
一行，若该序列存在“有趣的跳跃”，输出"Jolly"，否则输出"Not jolly"。
样例输入
4 1 4 2 3
样例输出
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
	memset(b,0,sizeof(b));//b的初值为0。
	for (i=1;i<=n;++i) cin>>a[i];
	for (i=2;i<=n;++i) {
		k=abs(a[i]-a[i-1]);// 用绝对值求和前一数的差
		if (k<n)b[k]=1;
	}
	for (i=1;i<=n-1;++i) sum+=b[i];//统计1的个数。1表示有那个差，
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

//
// Created by Yhz on 2017/5/22.
//
#include <iostream>
using namespace std;
//对角线的个数与行数(n)的关系：2*n-1
int a[1005][1005],c1[2010],c2[2010],c3[2010],c4[2010],d,n,m;

int my_max(int c1,int c2,int c3,int c4)
{
    int x=max(max(c1,c2),max(c3,c4));
    return max(x,d);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)//数组输入
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
//既然a[i][j]逆时针旋转得到b[m-j+1][i]，因此可以根据对应下标直接统计b中的“/”对角线
    for (int i = 0; i <= n+1; ++i) {//扩大循环范围，可以在数组(全局数组)周围多一圈0，触发else中的统计条件
        for (int j = 0; j <= m+1; ++j) {
            if(a[i][j]){//累加四个方向的统计值
                c1[i]++;c2[j]++;c3[i+j]++;c4[m-j+1+i]++;
            }else{//多了一圈0，保证能触发统计语句，统计后重新初始化各个方向的初始值
                d=my_max(c1[i],c2[j],c3[i+j],c4[m-j+1+i]);
                c1[i]=c2[j]=c3[i+j]=c4[m-j+1+i]=0;
            }
        }
    }

    if(d==1 || d==0 ) cout<<'0'<<endl;
    else cout<<d<<endl;

    return 0;
}

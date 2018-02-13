//
// Created by Hz Yang on 2017/6/7.
// 未考虑sum-n=1的情况，此时需去掉2，最后一个数+1
#include <iostream>
#include <cstring>

using namespace std;
int jc(long long  n,long long  x)//高精度乘法（阶乘）
{
    long long i,j,a[100005],lena,sum=0;
    memset(a,0,sizeof(a)) ;
    a[1]=1;lena=1;
    for(i=1;i<=n;i++){
        if(i==x) continue;
        for(j=1;j<=lena;j++)
            a[j]*=i;
        for(j=1;j<=lena;j++){
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        while(a[lena+1]>0){
            lena++;
            a[lena+1]+=a[lena]/10;
            a[lena]%=10;
        }
    }
    for(i=lena;i>=1;i--)
        sum+=a[i];
    return sum;
}

int main() {
    long long  n,i,j,sum=0,x=0;
    cin >> n;
    for ( i = 2; i < n; ++i ) {
        sum+=i;
        if(sum>=n) break;
    }

    if(sum>n) x=sum-n;
    cout << jc(i,x);
    return 0;
}

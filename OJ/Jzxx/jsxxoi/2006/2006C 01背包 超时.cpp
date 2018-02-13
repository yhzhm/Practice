/*就是经典的背包问题
先算出所有模型的制作总时间
然后除以二
得到的数值就是背包的容积
然后将模型的时间当成物品的体积
将物品放入背包
使得背包剩余体积最小
此时背包里的物品的体积之和
就是，做得少的那个人用的时间
用总时间减去这个时间
就是做得多的那个人所耗时间
也就是左后答案*/

//
// Created by Hz Yang on 2017/6/16.
// 01背包 超时40%
#include <cstdio>
#include <iostream>
using namespace std;
int n,a[105],sum,minv;
void dfs(int p,int v)
{
    if(p>n) {
        if(v>=0){
            minv=min(v,minv);
            return ;
        }
        return;
    }
    dfs(p+1,v);
    if(v-a[p]>=0)
        dfs(p+1,v-a[p]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum+=a[i];
    }
    int v=sum/2;
    minv=v;
    dfs(1,v);
    cout<<sum-v+minv;
    return 0;
}



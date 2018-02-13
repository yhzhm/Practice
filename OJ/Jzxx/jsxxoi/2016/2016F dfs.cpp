//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;
int n, k, a[300];
int maxi = ~((unsigned) (-1) >> 1);
//int mini = 0x7fffffff;
//int maxi = 0x80000000;

//判断一个数是否是质数
bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

//dep搜索深度，sum当前和，count当前质数个数
void dfs(int dep, int sum, int count) {
    if (dep > k) {
        if (sum == n) maxi = maxi > count ? maxi : count;
    } else {
        dfs(dep + 1, sum, count);
        if (sum < n)
            dfs(dep + 1, sum + a[dep], count + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i)//构造质数表
        if (isprime(i)) a[++k] = i;
    dfs(1, 0, 0);
    cout << maxi << endl;
    return 0;
}

//    clock_t startTime=clock();
//    clock_t endTime=clock();
//    cout<<"Time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

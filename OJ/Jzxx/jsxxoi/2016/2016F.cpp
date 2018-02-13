/*2884: 【提高】素数分解
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 165解决 : 55
题目描述
素数，又称质数，是指除 1 和其自身之外，没有其他约数的正整数。例如 2、3、5、13 都是质 数，而 4、9、12、18 则不是。
虽然素数不能分解成除 1 和其自身之外整数的乘积，但却可以分解成更多素数的和。
你需要编程 求出一个正整数最多能分解成多少个互不相同的素数的和。
例如，21 = 2 + 19是21的合法分解方法。21 = 2 + 3 + 5 + 11则是分解为最多素数的方法。
输入
n (10≤n≤200)。
输出
n 最多能分解成多少个不同的素数的和。
 
样例输入
样例1: [复制]
21
样例2: [复制]
128
样例输出
样例1: [复制]
4
样例2: [复制]
9*/
//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;
int n, a[300];
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

//n当前拆解的数；x可能的质数；当前深度（拆解到的质数个数）
void work(int n, int x, int dep) {
    //拆解完成，保留质数最大个数
    if (n == 0) {
        maxi = maxi > dep ? maxi : dep;
    } else if (x <= n) {
        for (int i = x; i <= n; ++i) {
            if (a[i] == 0 && isprime(i)) {
                a[i] = 1;
                work(n - i, i, dep + 1);
                a[i] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    work(n, 2, 0);//拆解数n，从2开始判断，当前深度（质数个数）0
    cout << maxi << endl;
    return 0;
}

//    clock_t startTime=clock();
//    clock_t endTime=clock();
//    cout<<"Time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
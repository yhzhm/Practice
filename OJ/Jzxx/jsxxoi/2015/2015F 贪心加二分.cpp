/*2876: 【提高】拴奶牛
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 117解决 : 56
题目描述
有n头奶牛（2≤n≤100），有k个木桩（n≤k≤100），每个木桩有一个位置，一个木桩上只能拴一头奶牛。由于奶牛好斗，所以在拴奶牛的时候要求距离最近的奶牛的距离尽可能大。
例如n=4,k=6，木桩的位置为0，3，4，7，8，9

此时，有许多拴牛方案，例如
0，3，4，9      此时最近距离为1（3，4之间）
0，3，7，9      此时最近距离为2
 
输入
1行：n,k,p_1三个整数（0≤p_1≤100），其中p_1为第1个木桩的位置，其他木桩p_i (i≥2)的位置由下面公式给出：
p_i=p_(i-1)+((p_(i-1)×2357+137)  mod 10)+1
 
输出
一个整数，即奶牛最近距离的最大值。
 
样例输入 [复制]
25 70 99
样例输出 [复制]
12
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2015江苏省青少年信息学奥林匹克小学组竞赛复赛*/


//
// Created by Hz Yang on 2017/5/13.
//
#include <iostream>
using namespace std;
int n, k, a[105];//n头牛，k个桩，n<=k
bool check(int d) {
    int last = 0;
    //为n头牛安排位置
    for (int i = 1; i < n; ++i) {
        int crt = last + 1;
        while (crt < k && a[crt] - a[last] < d)//桩未安排完，并且距离小于最短距离，往后继续找下一个桩
            crt++;
        if (crt == k) return false;//如果桩用完，返回false
        last = crt;//桩未用完，以crt为起点继续找
    }
    return true;//n头牛都安排完，也未用完桩，说明这个最小距离d可以安排
}

int main() {
    cin >> n >> k >> a[0];
    for (int i = 1; i < k; ++i) {
        a[i] = a[i - 1] + ((a[i - 1] * 2357 + 137) % 10) + 1;
    }
    int lb = 0, ub = a[k-1];//初始化解的存在范围
    //二分查找
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (check(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
    return 0;
}

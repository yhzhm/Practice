/*就是经典的背包问题，先算出所有模型的制作总时间，然后除以二，得到的数值就是背包的容积。
然后将模型的时间当成物品的体积，将物品放入背包，使得背包剩余体积最小。
此时背包里的物品的体积之和，就是做得少的那个人用的时间，用总时间减去这个时间，
就是做得多的那个人所耗时间，也就是最后答案*/
//
// Created by Hz Yang on 2017/6/17.
// 动态规划

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    //a[]存放物品的体积，s[i]={0,1}表示容量i,能否正好放满
    //sum表示n个物品的总体积,v是总体积的一半，maxv是能装满的最大空间
    int n, i, j, a[105], s[20005], sum = 0, maxv = 0;
    cin >> n;
    s[0] = 1;//s[i]=1表示可以装i体积
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int v = sum / 2;
    for (i = 0; i < n; ++i) {
        for (j = v; j >= a[i]; --j) {//j为装了a[i]后的剩余背包容量
            if (s[v]) { //如果已满，则剩余空间为0，最大可装空间为v，无需继续判断
                maxv = v;
                break;
            }
            if (s[j - a[i]]) s[j] = 1;//只有s[j-a[i]]为1时，s[j]才能为1
        }
    }
    for (i = v; i >= 0; --i) {//因为要求最小剩余体积，即装的最多，所以倒着开始判断
        if (s[i]) {
            maxv = i;
            break;
        }
    }
    cout << sum - maxv;
    return 0;
}




/*2244: 【提高】二叉树的深度和宽度
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 223解决 : 117
题目描述
有一颗二叉树，如下图：
此二叉树共有7个结点①②③④⑤⑥⑦，并约定结点①为根结点，处在第一层。根结点①有2个孩子，左孩子为②，右孩子为③，并约定二叉树的一个结点最多有2个孩子。
二叉树可以用三元式表示，（结点    左孩子    右孩子）
对于上图的二叉树可以表示为：
1 2 3
2 4 5
3 6 0
4 0 0
5 0 0
6 0 7
7 0 0
上面二叉树的深度为4(即最大层次数)，宽度为3(即，同一层上最多结点数)。
 
输入
第一行一个整数(1≤n≤30)，即结点个数。
接下来 n行，每行三个数，即结点三元式。
 
输出
一行，含二个整数，即二叉树深度和宽度
 
样例输入 [复制]
4
1 2 3
2 4 0
3 0 0
4 0 0
样例输出 [复制]
3 2
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2012江苏省青少年信息学奥林匹克小学组竞赛复赛*/
//
// Created by Hz Yang on 2017/6/5.
//
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
int n,a[35][3],maxd=0,b[35];

int maxw()
{
    int x=0;
    for (int i = 0; i <35 ; ++i) {
        x=max(b[i],x);
    }
    return x;
}
void dfs(int step,int d)
{
    maxd=max(step,maxd);
    int i;
    for (i = 1; i <=n ; ++i) {
        if(a[i][0]==d) break;
    }
    if(a[i][1]) {b[step+1]++;dfs(step+1,a[i][1]);}
    if(a[i][2]) {b[step+1]++;dfs(step+1,a[i][2]);}
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n ; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    b[1]=1;
    dfs(1,1);
    cout<< maxd<<' '<<maxw();
    return 0;
}
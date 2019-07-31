#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];

void out()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j)
            printf("%10.2lf", a[i][j]);
        puts("");
    }
    puts("");

}

int gauss()
{
    int c, r;//c列，r行
    for (c = 0, r = 0; c < n; ++c) { //枚举处理每一列
        int t = r;
        for (int i = r; i < n; ++i)//找当前列绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        if (fabs(a[t][c]) < eps) continue;
        for (int i = c; i <= n; ++i) swap(a[t][i], a[r][i]);//将该行换至最上面
        for (int i = n; i >= c; --i) a[r][i] /= a[r][c]; //将第一项系数变成1
        for (int i = r + 1; i < n; ++i)//消元
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; --j)
                    a[i][j] -= a[r][j] * a[i][c];
        // out();
        r ++;
    }
    if (r < n) {
        for (int i = r; i < n; ++i)
            if (fabs(a[i][n]) > eps) return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; --i)//求解
        for (int j = i + 1; j < n; ++j)
            a[i][n] -=  a[j][n] * a[i][j] ;
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            cin >> a[i][j];

    int t = gauss();
    if (t == 0)
        for (int i = 0; i < n; ++i) printf("%.2lf\n", a[i][n]);
    else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");
    return 0;
}

/*
高斯消元
O(n^3)复杂度
初等行列变换：
1.把某一行乘一个非零的数
2.交换某2行
3.把某行的若干倍加到另一行上
解的情况：
1.完美阶梯型--唯一解
2.0=非零      --无解
3.0=0           --无穷多组解
步骤：
枚举每一列c
①找到绝对值最大的那一行
②将该行换到最上面（未固定行的最上面）
③将该行第一个数变成1
④将其余行的第c列削成0
当前最上面的行固定，继续处理下一列

 */
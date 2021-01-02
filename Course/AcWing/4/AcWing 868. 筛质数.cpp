//线性筛法
#include <iostream>
using namespace std;
const int N = 1000010;
int primes[N], cnt;
bool st[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    cout << cnt << endl;

    return 0;
}
/*
//埃氏筛法 O(nloglogn)
#include <iostream>
using namespace std;
const int N = 1000010;
bool st[N];

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i){
        if(!st[i]){
            cnt ++;
            for (int j = i; j <= n; j += i) st[j] = true;
        }
    }
    cout << cnt << endl;
    return 0;
}
*/


/*
线性筛法
把每一个合数，用它的最小质因子筛掉（保证唯一性，从而做到线性）
从小到大枚举每一个质数（已经筛出来的质数）

核心：
1.合数n，只会被它的最小质因子筛掉
① i % pj == 0 : pj一定是i的最小质因子（pj是从小到大枚举的），pj一定是pj * i的最小质因子。
primes[j]是i的最小质因子，下一轮primes[j + 1] * i 这个数的最小质因子还是primes[j],primes[j] < primes[j + 1],
所以不能保证每个合数都是被它的最小质因子筛掉，故这里要break终止掉
② i % pj != 0 : pj一定小于i的所有质因子，pj也一定是pj * i的最小质因子。
2.合数一定会被筛掉
对于一个合数x，假设pj是x的最小质因子，当i枚举到x/pj时（i枚举到x之前），pj一定会被枚举到

每个数只会被筛一次，所以它是线性的。
每个合数只会被最小质因子筛掉，每个合数一定会被它的最小质因子筛掉，所以它是线性的

primes[j] <= n / i; 不需要 j < cnt &&，因为：
如果i是合数，循环会在i的第一个最小质因子处break掉；
如果i是质数，循环也会在primes[j] == i时，break掉；（当前primes[]中的最后一个质数）；
所以循环一定会在j大于等于cnt之前停下来。

 */
//
// Created by Hz Yang on 2017/6/2.
// 其实也用到了尺取法的思想，用公式计算“梯形”面积
#include <iostream>

using namespace std;

int main() {
    long long n, i,j, sum, count = 0;
    cin >> n;
    i=n/2+1;
    j=i-1;
    for ( ; i > 0; --i) {
        for ( ; j > 0; --j) {
            sum = (i+j)*(i-j+1)/2;
            if(sum<n) continue;
            else if (sum > n) break;
            else  {
                count++;
                break;
            }
        }
        if(j==1||j==0) break;
    }
    cout << count << endl;
    return 0;
}


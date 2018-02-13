/*
 * 有1元、5元、10元、50元、100元的硬币各C1,C5,C10,C50,C100,C500枚。
 * 现在要用这些硬币来支付A元，最少需要多少枚硬币？假定本题至少存在一种支付方案。
 * 样例输入：c1=3 c5=2 c10=1 c50=3 c100=0 c500=2,a=620;
 * 样例输出：6 （500 1枚 50 2枚 10 1枚 5 2枚 合计6枚）
 */

//
// Created by Hz Yang on 2017/5/9.
//硬币问题
#include <iostream>
using namespace std;

int main() {
    const int v[6]={1,5,10,50,100,500};
    int c[6],A,ans=0;
    for (int i = 0; i < 6 ; ++i) {
        cin >> c[i];
    }
    cin >> A;
    for (int i = 5; i >=0 ; --i) {
        int t=min(A/v[i],c[i]);
        A-=t*v[i];
        ans+=t;
    }
    cout << ans <<endl;
    return 0;
}

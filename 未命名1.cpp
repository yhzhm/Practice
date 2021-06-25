#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void mirror(vector<string>& s){
    for (int i = 0; i < n; ++i)
        for (int j = 0, k = n - 1; j < k; ++j, --k)
            swap(s[i][j], s[i][k]);
}

void rotate(vector<string>& s)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            swap(s[i][j], s[j][i]);
    mirror(s);
}

int check(vector<string>& a, vector<string>& b)
{
    auto c = a;
    for (int i = 1; i <= 3; ++i){
        rotate(c);
        if (c == b) return i;
    }
    c = a;
    mirror(c);
    if (c == b) return 4;
    for (int i = 1; i <= 3; ++i){
        rotate(c);
        if (c == b) return 5;
    }
    if (a == b) return 6;
    return 7;
}

int main()
{
    vector<string> a, b;
    string x;
    
    cin >> x;
    for (int i = 0; i < n; ++i) cin >> x, a.push_back(x);
    for (int i = 0; i < n; ++i) cin >> x, b.push_back(x);
    cout << check(a, b) << endl;
    
    return 0;
}

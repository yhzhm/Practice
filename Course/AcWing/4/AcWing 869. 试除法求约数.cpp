#include <iostream>
#include <set>
using namespace std;

void work(int x)
{
    set<int> s;
    for (int i = 1; i <= x / i; ++i)
        if (x % i == 0) s.insert(i), s.insert(x / i);

    for (auto i = s.begin(); i != s.end(); ++i)
        cout << *i << ' ';
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int x;
        cin >> x;
        work(x);
    }
    return 0;
}

/*
O(sqrt(n))
*/
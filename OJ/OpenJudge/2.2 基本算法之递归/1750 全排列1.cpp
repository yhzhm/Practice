#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n, book[10];
char a[10], b[10];

void fun(int step) {
    if (step == n) {
        for (int i = 0; i < n; ++i) {
            cout << b[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!book[i]) {
            b[step] = a[i];
            book[i] = 1;
            fun(step + 1);
            book[i] = 0;
        }
    }
}

int main() {
    scanf("%s", a);
    n = strlen(a);
    fun(0);
    return 0;
}
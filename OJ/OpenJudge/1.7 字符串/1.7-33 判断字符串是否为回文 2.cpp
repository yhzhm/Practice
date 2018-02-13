//
// Created by Hz Yang on 2017/4/6.
//
#include <iostream>
using namespace std;
bool palindrome(string s)
{
    string::size_type i;
    for (i = 0; i < s.size() >> 1; ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}
int main() {
    string s;
    getline(cin, s);
    if (palindrome(s)) cout << "yes";
    else cout << "no";
    return 0;
}

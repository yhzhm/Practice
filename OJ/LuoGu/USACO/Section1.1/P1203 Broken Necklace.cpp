//
// Created by Hz Yang on 2017/8/24.
//
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n,maxn=0;
    string s;
    cin >> n >> s;
    string sa=s+s;
    for (int i = 0; i < s.size(); ++i) {
        int sum=0,suml=0,sumr=0;
        char al='0',ar='0';
        for (int j = 1; j <= n; ++j) {
//            cout<<sa[i+j];
            if (sa[i+j]=='w') {sumr++;continue;}
            else if(ar=='0') {sumr++;ar=sa[i+j];continue;}
            if (ar==sa[i+j]) sumr++;
            else break;
        }
//        cout<<':';
        for (int j = 0; j < n; ++j) {
//            cout<<sa[i+n-j];
            if (sa[i+n-j]=='w') {suml++;continue;}
            else if(al=='0') {suml++;al=sa[i+n-j];continue;}
            if (al==sa[i+n-j]) suml++;
            else break;
        }
//        cout<<' ';
//        cout<<sumr<<':'<<suml<<endl;
        sum=min(sumr+suml,n);
        maxn=max(sum,maxn);
    }
    cout<<maxn;
    return 0;
}



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    string s;
    while(cin.peek()!='\n'){
        cin>>s;
        v.push_back(s);
    }
    vector<string>::reverse_iterator i;
    for (i = v.rbegin(); i != v.rend(); ++i) {
        cout<<*i<<' ';
    }
    return 0;
}
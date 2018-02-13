//
// Created by hmtyxx1 on 17/2/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,s,a,b,x,y,sum=0;
    cin>>n>>s;
    cin>>a>>b;
    vector<int> t;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(a+b>=x) t.push_back(y);
    }
    sort(t.begin(),t.end());
    for(vector<int>::iterator i=t.begin();i!=t.end();++i){
        if((s-=*i)>=0) sum++;
        else break;
    }
    cout<<sum<<endl;
    return 0;
}


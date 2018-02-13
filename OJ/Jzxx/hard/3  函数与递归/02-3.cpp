#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;
//埃拉托色尼筛选法 
bool p[1000010];
void erators(int n) 
{
	int j;
	for(int i=0;i<=n;i++)
		p[i]=true;
	p[0]=p[1]=false;
	for(int i=2;i*i<=n;i++){
		if(p[i]){
			j=i+i;
			while(j<=n){
				p[j]=false;
				j=j+i;
			}
		}
	}
}
int main()
{
	freopen("02-03.out","w",stdout);
	int n;
	cin >> n;
    clock_t startTime=clock();
	erators(n); 
	for(int i=2;i<=n-2;i++){
		if(p[i] && p[i+2])
		cout<<i<<' '<<i+2<<endl;
	}
    clock_t endTime=clock();
    cout<<"Time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	fclose(stdout);
	return 0;
}


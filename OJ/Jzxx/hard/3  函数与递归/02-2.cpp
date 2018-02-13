#include <iostream>
#include <ctime>

using namespace std;
bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	freopen("02-02.out","w",stdout);
	clock_t startTime=clock();
	for(int i=2;i<=n-2;i++){
		if(isPrime(i) && isPrime(i+2))
		cout<< i <<' '<< i+2 <<endl;
	}
	clock_t endTime=clock();
    cout<<"Time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	fclose(stdout);
	return 0;
}



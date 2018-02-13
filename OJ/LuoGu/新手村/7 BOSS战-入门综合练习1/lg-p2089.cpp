//设f[i][j]是把i分解成j份的方案总数，显然有f[i][j]=∑f[i-k][j-1], 1<=k<=3，
//看转移式的定义，其实就是i分解成j份，每份不大于k，可以进一步优化。
#include <stdio.h>
int main()
{
	int f[10010][11],n;
	f[0][0]=1;
    for(int i=1;i<=10000;i++)
        for(int j=1;j<=10;j++)
            for(int k=1;k<=3;k++)
                if(i>=k)
                    f[i][j]+=f[i-k][j-1];
    scanf("%d",&n);
    printf("%d\n",f[n][10]);
	return 0;
}
    

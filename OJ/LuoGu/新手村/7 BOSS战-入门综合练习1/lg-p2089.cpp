//��f[i][j]�ǰ�i�ֽ��j�ݵķ�����������Ȼ��f[i][j]=��f[i-k][j-1], 1<=k<=3��
//��ת��ʽ�Ķ��壬��ʵ����i�ֽ��j�ݣ�ÿ�ݲ�����k�����Խ�һ���Ż���
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
    

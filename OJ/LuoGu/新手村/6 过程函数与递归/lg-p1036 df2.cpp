#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int a[30];
int b[30];
bool vis[30];//����
int sum=0;//��
bool judge(long long x)//�ж�x�Ƿ�������
{
    for(int i=2;i<=sqrt(x);i++)//ֻ��ö�ٵ�������x��Ҳ��һ����֦��
    if(x%i==0) return false;//����һ���������������x��һ������
    return true;
}
void dfs(int x,int now,long long ans)//�ֱ��ʾ��ǰѡ���˵�xλ��nowһ��ѡ�˶�������ansѡ�����ڵĺ�
{
    if(now==k)//�Ѿ�ѡ����k���������Ѿ�����һ�ַ���
    {
        if(judge(ans)) sum++;//�жϵ�ǰ�����Ƿ������⣬���Ծͽ��𰸼�һ
        /*for(int i=0;i<now;i++)
        printf("%d ",b[i]);
        printf("\n");*///�˴������ڹ۲�ÿ�ζ�ѡȡ����Щ��
    } 
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&i>x)
            {
                vis[i]=true;//����Ƿ��Ѿ�ѡȡ
                //b[now]=a[i]; //����ֻ�����ڼ�飬�����Ҽ��ÿ��ѡ��Щ����ʹ�ã��뱾���޹�
                dfs(i,now+1,ans+a[i]);//�ݹ�����һ����
                vis[i]=false;//���ݣ�����Ҫ����������
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    dfs(0,0,0);//����һ�µ�һ��0Ҳ����dfs�е�x���������صģ��������Խ�Լʱ�䣨��Ϊһ������ѡ��һ�ڶ���������
//ѡ��һ�����ڶ�����������һ����,��1 5 3 2 4��ѡ1 3 2��ѡ1 2 3��һ���ģ�
    printf("%d",sum);
    return 0;
}
//������в��ף�����ָ�̡�

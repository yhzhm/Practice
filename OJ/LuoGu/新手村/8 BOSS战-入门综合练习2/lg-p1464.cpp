#include<cstdio>
long long m[25][25][25];//���仯��������ά����
long long w(long long a,long long b,long long c){//��ֹ���ȫ����long long
    if(a<25&&b<25&&c<25&&a>0&&b>0&&c>0&&m[a][b][c])
        return m[a][b][c]; //��ȡ�������Ƿ�����Ѿ���¼�õ���ֵ��ֱ�ӷ���
    int result;
    if(a<=0||b<=0||c<=0)result=1;
    else if(a>20||b>20||c>20)result=w(20,20,20);
    else if(a<b&&b<c)result=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else result=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    if(a<25&&b<25&&c<25&&a>0&&b>0&&c>0){
        m[a][b][c]=result;//��������ڣ�������Ϻ�洢����
    }
    return result;
}
int main(){
    while(1){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1)break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
    }
}

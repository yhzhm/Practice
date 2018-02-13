#include<cstdio>
long long m[25][25][25];//记忆化搜索的三维数组
long long w(long long a,long long b,long long c){//防止溢出全部用long long
    if(a<25&&b<25&&c<25&&a>0&&b>0&&c>0&&m[a][b][c])
        return m[a][b][c]; //读取数组中是否存在已经记录好的数值，直接返回
    int result;
    if(a<=0||b<=0||c<=0)result=1;
    else if(a>20||b>20||c>20)result=w(20,20,20);
    else if(a<b&&b<c)result=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else result=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    if(a<25&&b<25&&c<25&&a>0&&b>0&&c>0){
        m[a][b][c]=result;//如果不存在，计算完毕后存储起来
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

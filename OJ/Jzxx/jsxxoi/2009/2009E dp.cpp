/*1767: 【提高】建学校
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 145解决 : 41
题目描述
汶川大地震发生已经有一年了。地震灾区的重建工作有许多工作要做，其中学校的重建被放在了重要的议事日程上：在一条新建的公路两旁，有n个村庄，编号为1，2……n（3≤n≤100），每个村庄有一定数量的小学生，村庄之间的距离也已知。例如n=3时，下图给出了三个村庄的相关情况：村庄1的学生数24,村庄2的学生数18,村庄3的学生数31. 村庄1和村庄2之间距离为10, 村庄2和村庄3之间的距离为8。
　 10 　　8
①————②————③
24　  18　  31
现在要在村庄中建k个学校（1≤k≤10）,比如上图中k=2时，建二个学校，此时有三种方案：
村庄1　村庄2　村庄3学生走到村庄2, 学生走的距离和为31×8＝248
村庄1　村庄3　村庄2学生走到村庄3（就近入学），学生走的距离和为18×8＝144
村庄2　村庄3　此时村庄1的学生走到村庄2的距离和为24×10＝240 显然，方案2最好。
问题：当给出村庄数n，每个村庄的学生数、村庄之间的距离以及要建的学校数k之后，求出合理的建学校的方案，使学生走的距离和为最少。
 
输入
第一行2个整数，表示村庄数n，学校数k
第二行n个整数，表示每个村庄学生数（0＜每个村庄学生数≤100 )
第三行n-1个数，分别表示村庄i到村庄i+1之间距离（1≤距离≤100，1≤i≤n-1）
 
输出
一个整数，即学生走的距离和的最小值
 
样例输入 [复制]
3 2
24 18 31
10 8
样例输出 [复制]
144
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2009年江苏省小学生信息学（计算机）奥赛*/

/*动态规划思想：
因为是100，所以就可以用n^3的方法。
那么怎么定义数组，又怎么写方程式呢？
思路1：
f[i][j][k]，i表示当前算到的村庄，j表示上一所学校的位置且i<=j，k表示已建学校总数。这样便可以建一个动规。但是此方法思路乱，速度慢，难以实现。
思路2：
f[i][k]，i表示当前算到的村庄且此村庄建了学校，k表示已建学校总数。此方法需要一个n^2的简单预处理。
创建dis、beh和aft数组，dis[i][j]表示从i到j的距离，beh[i][j]表示假如i建学校从i+1到j村庄所有学生走的路的总合，
aft[i][j]反一反，j建学校i到j-1学生走路总合。以上数组i均小于j，有了此优化便可以进行了。
dp式是：f[i][k]=max(f[j][k-1]+beh[j][p]+aft[p+1][i])
i，j，k，p分别为1，2，3，4重循环。
问题就解决了。这题目理论上时间长可是由于循环变量的控制，时间效率还是可观的。*/

//
// Created by Hz Yang on 2017/6/19.
//
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    long n,l,i,j,k,p,stu[101],beh[101][101],aft[101][101],f[101][11],dis[101][101],d,leas;
    cin>>n>>l;
    for (i=1;i<=n;i++) cin>>stu[i];
    memset(dis,0,sizeof dis); memset(beh,0,sizeof beh);
    memset(aft,0,sizeof aft); memset(f,1,sizeof f);//赋大值
    for (i=1;i<n;i++)
    {
        cin>>d;//读入并处理dis
        dis[i][i+1]=d; dis[1][i+1]=dis[i][i+1]+dis[1][i];
        for (j=1;j<i;j++) dis[j][i+1]=dis[1][i+1]-dis[1][j];
    }
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
            beh[i][j]=beh[i][j-1]+dis[i][j]*stu[j];
        for (j=i-1;j>=1;j--)
            aft[j][i]=aft[j+1][i]+dis[j][i]*stu[j];
    }//二维预处理aft与beh
    f[1][1]=0;//初值
    for (i=2;i<=n;i++)
    {
        f[i][1]=aft[1][i];//1所学校要特殊处理
        for (j=1;j<=i;j++)//所说的dp
            for (k=2;k<=l;k++)
                for (p=j;p<=i-1;p++)
                    if (f[j][k-1]+beh[j][p]+aft[p+1][i]<f[i][k])
                        f[i][k]=f[j][k-1]+beh[j][p]+aft[p+1][i];
    }
    leas=2147483647;//最小值，初始值取个大数字
    for (i=2;i<=n;i++)
        if (f[i][l]+beh[i][n]<leas) leas=f[i][l]+beh[i][n];//最后处理，寻找最小情况
    cout<<leas<<endl;//输出
}
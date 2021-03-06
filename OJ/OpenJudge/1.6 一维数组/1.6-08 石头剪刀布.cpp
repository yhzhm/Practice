/*
08:石头剪刀布
石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。
一天，小A和小B正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。请问，小A和小B比了N轮之后，谁赢的轮数多？
输入包含三行。
第一行包含三个整数：N，NA，NB，分别表示比了N轮，小A出拳的周期长度，小B出拳的周期长度。0 < N,NA,NB < 100。
第二行包含NA个整数，表示小A出拳的规律。
第三行包含NB个整数，表示小B出拳的规律。
其中，0表示“石头”，2表示“剪刀”，5表示“布”。相邻两个整数之间用单个空格隔开。
输出一行，如果小A赢的轮数多，输出A；如果小B赢的轮数多，输出B；如果两人打平，输出draw。
样例输入
10 3 4
0 2 5
0 5 0 2
样例输出
A
*/

#include <cstdio>
int main()
{
	int n,na,nb,a[100+10],b[100+10],judge=0;
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<nb;++i){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;++i){
		int x=i%na,y=i%nb;
		if(a[x] != b[y]){
			if(a[x]==0&&b[y]==2 || a[x]==2&&b[y]==5 || a[x]==5&&b[y]==0) judge++;
			else judge--;
		}
	}
	if(judge>0) printf("A");
	else if(judge<0) printf("B");
	else printf("draw");
	return 0;
}

// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int n, tot, ans;
int ver[M * 2], edge[M * 2], Next[M * 2], head[M];//ver[]:当前边的目标点，edge[]:边的权值，Next[]：下一条边编号，head[]：与节点相关的边编号
int used[M], val[M * 32], trie[M * 32][2], f[M];//used[]：标识点是否遍历过，val[]：记录trie中一条路径所表示的数的值，便于查询时返回该值，
//trie[][]:字符数组，f[i]点i到根的路径中所有边的异或和

void add(int x, int y, int w)
{
	ver[++tot] = y;//当前边的目标点
	edge[tot] = w;//当前边的权值
	Next[tot] = head[x];//与当前节点x相关的下一条边（另一条，严格说是上一条）编号
	head[x] = tot;//与当前节点x相关的边编号
}

void dfs(int x)//从x点开始搜
{
	used[x] = 1;//标记为已使用
	for (int i = head[x]; i; i = Next[i]) {//枚举x点所有的路径
		if (!used[ver[i]]) {//若目标点没有遍历过
			f[ver[i]] = f[x] ^ edge[i];//计算目标点f[]
			dfs(ver[i]);//从目标点开始继续搜
		}
	}
}

void insert(int x, int y, int temp)//x：根节点 y：二进制位 temp:要插入的数
{
	if (y < 0) {val[x] = temp; return;}//二进制位遍历完后，插入成功，将temp赋值给val[x]，便于搜索时返回该数值
	int z = temp >> y & 1;//temp的第y位
	if (!trie[x][z]) trie[x][z] = ++tot;
	insert(trie[x][z], y - 1, temp);//继续在trie[x][z]位置插入temp的第y-1位
}

int search(int x, int y, int temp)//x：根节点 y：二进制位 temp:要查询的数
{
	if (y < 0) return val[x];//二进制位遍历完后，查询完毕，返回该边的数值val[x]
	int z = temp >> y & 1;//temp的第y位
	if (trie[x][z ^ 1]) return search(trie[x][z ^ 1], y - 1, temp);//若存在异或位路径，尽量从异或位那条边走
	else return search(trie[x][z], y - 1, temp);//若不存在异或位，从相同位那条边走
}

int main()
{
	cin >> n; int x, y, w;//节点x和节点y之间有一条边权重为w
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &w);
		x++, y++;
		add(x, y, w); add(y, x, w);//无向图，两个方向都要add
	}
	dfs(1);//通过深搜，计算每个点到根节点的路径上所有边权重的异或和
	tot = 1;
	insert(1, 30, 0);//将整数的二进制表示插入Trie
	for (int i = 1; i <= n; ++i) {//枚举所有点f[i]，在trie中（已经插入i-1个数）查询得到最大异或值
		ans = max(ans, f[i] ^ search(1, 30, f[i]));//更新答案
		insert(1, 30, f[i]);//将f[i]插入Trie。1：根节点，30：二进制最高位，f[i]:要插入的数
	}
	cout << ans << endl;
	return 0;
}

/*
1.树结构内任意两点u,v u,vu,v间的路径权值异或和f(u,v) f(u,v)f(u,v)，具有如下性质
f(u,v)=f(root,u)xorf(root,v)
其中，root是根结点。
2.找到所有节点与root的路径权值异或和f(root,i),i∈V,V表示节点集合。将异或和(32位整形int)存入到Trie树。
3.遍历2中所有异或和，力求在Trie树中寻找到与其异或结果最大的值。

补充知识点：
1. 树的表示方法
除了矩阵和链表法（这里指使用指针或者vector容器的方法）外，可以使用数组表示，名称是链式前向星。
好处是多次运算时，不需要为了建立树，重复开辟和收回空间。因此，时间开销也会降低。
2.固定规模的问题，可以事先开辟好足够空间，以减少操作(new,delete)等带来的时间开销。
 */
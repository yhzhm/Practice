/*
04:ʯͷ���Ӳ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
ʯͷ���Ӳ�����һ�ֲ�ȭ��Ϸ����Դ���й���Ȼ�󴫵��ձ������ʵȵأ�������ŷó�׵Ĳ��Ϸ�չ��������ŷ�ޣ����˽��ִ��𽥷������硣�����˵Ĺ���ʹ��ʯͷ���Ӳ�û���κι���©�����꣬�����淨��ƴ��������غ��淨��ƴ�����ģ�ʹ��ʯͷ���Ӳ�������ϵ���Ϸͬʱ���ڡ����⡱�롰�������������ԣ�������������ϲ���� 

��Ϸ����ʯͷ�����������ʯͷ������������ 

���ڣ���Ҫ��дһ���������ж�ʯͷ���Ӳ���Ϸ�Ľ����

����
�������N+1�У�
��һ����һ������N����ʾһ��������N����Ϸ��1 <= N <= 100��
������N�е�ÿһ�а��������ַ�������ʾ��Ϸ������Player1��Player2��ѡ��ʯͷ�����ӻ����ǲ�����
S1 S2
�ַ���֮���Կո����S1,S2ֻ����ȡֵ��{"Rock", "Scissors", "Paper"}����Сд���У��С�
���
�������N�У�ÿһ�ж�Ӧһ��ʤ���ߣ�Player1����Player2����������Ϸ����ƽ�֣������Tie��
��������
3
Rock Scissors
Paper Paper
Rock Paper
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int n, i = 1;
	string S1, S2;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		cin >> S1 >> S2;
		if (S1 == S2) printf("Tie\n");
		if (S1 == "Rock" 	 && S2 == "Scissors") printf("Player1\n");
		if (S1 == "Rock" 	 && S2 == "Paper"   ) printf("Player2\n");
		if (S1 == "Scissors" && S2 == "Paper"   ) printf("Player1\n");
		if (S1 == "Scissors" && S2 == "Rock"    ) printf("Player2\n");
		if (S1 == "Paper"	 && S2 == "Rock"    ) printf("Player1\n");
		if (S1 == "Paper"    && S2 == "Scissors") printf("Player2\n");
	}
	return 0;
}

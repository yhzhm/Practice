#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, i = 1;
	string S1, S2;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> S1 >> S2;
		if (S1 == S2) printf("Tie\n");
		else if (S1 == "Rock" && S2 == "Scissors" ||
		         S1 == "Scissors" && S2 == "Paper" ||
		         S1 == "Paper" && S2 == "Rock")
			printf("Player1\n");
		else
			printf("Player2\n");
	}
	return 0;
}
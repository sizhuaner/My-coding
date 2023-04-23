
//爬楼梯
#include <iostream>
using namespace std;


int climb(int n) {
	if (n <= 1) return n;
	int dp[3];//dp数组表示到达这一层的方法数
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		int sum = dp[1] + dp[2];
		dp[1] = dp[2];
		dp[2] = sum;
	}
	return dp[2];
}

int main() {

	int x;
	cin >> x;
	cout << climb(x) << endl;
	return 0;
}
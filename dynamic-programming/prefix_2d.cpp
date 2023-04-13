
vector<vector<int>> M;
vector<vector<ll>> dp;

void prefix2D() {
	dp[0][0] = M[0][0];

	for (int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + M[i][0];
	for (int j = 1; j < m; j++) dp[0][j] = dp[0][j-1] + M[0][j];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + M[i][j];
		}
	}
}


ll query(int i1, int j1, int i2, int j2) {
	ll res = dp[i2][j2];

	if (i1 >= 1) res -= dp[i1-1][j2];
	if (j1 >= 1) res -= dp[i2][j1-1];
	if (i1 >= 1 && j1 >= 1) res += dp[i1-1][j1-1];
	return res;
}


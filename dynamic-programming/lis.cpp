// O (nlogn)
int lis(int n) {
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(ans.begin(), ans.end(), v[i]);

		if (it == ans.end()) ans.pb(v[i]);
		else *it = v[i];
	}	

	return ans.size();
}
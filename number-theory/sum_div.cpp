const int LIM = 1e6 + 5;
vector<ll> sum_div(LIM);

void sieve() {
	for (int i = 1; i < LIM; i++) {
		for (int j = i; j < LIM; j += i) {
			sum_div[j] += i;
		}
	}
}
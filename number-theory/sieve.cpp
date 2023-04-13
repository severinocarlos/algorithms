const int LIM = 1e6 + 5;
bool isPrime[LIM];

vector<int> sieve() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	vector<int> primes;
	for (int i = 2; i < LIM; i++) {
		if (isPrime[i]) {
			primes.pb(i);
			for (int j = i*2; j < LIM; j += i) {
				isPrime[j] = false;
			}
		}
	}

	return primes;
}
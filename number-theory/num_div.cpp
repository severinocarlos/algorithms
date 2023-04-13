vector<int> num_div;
void sieve() {
  for(int i = 1; i < LIM; ++i) {
    for(int j = i; j < LIM; j += i) {
      num_div[j]++;
    }
  }
}
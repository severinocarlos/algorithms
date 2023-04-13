int get_divisors(int n) {
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      cnt++;
      if(n / i != i) cnt++;
    }
  }

  return cnt;
}
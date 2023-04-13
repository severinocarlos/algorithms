const int ms = 2e5 + 5;
vector<ll> seg(4*ms);
vector<ll> lazy(4*ms, 0);
int n;

void build(vector<int>& v, int l, int r, int idx) {
	if (l == r) {
		seg[idx] = v[l];
		return;
	}

	int m = (l+r) / 2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;

	build(v, l, m, left), build(v, m+1, r, right);
	seg[idx] = seg[left] + seg[right];
}

void propagate(int idx, int l, int r) {
	// progate with (merge => sum)
	seg[idx] += lazy[idx] * (r - l + 1);
	if(l != r) {
		lazy[idx*2 + 1] += lazy[idx];
      lazy[idx*2 + 2] += lazy[idx];
	}
	lazy[idx] = 0;
}

ll query(int idx, int l, int r, int a, int b) {
	propagate(idx, l, r);
	if (b < l || a > r) return 0;
	if (a <= l && r <= b) {
		return seg[idx];
	}	
	int m = (l+r) / 2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	return query(left, l, m, a, b) + query(right, m+1, r, a, b);
}

void update(int idx, int l, int r, int a, int b, ll val) {
	propagate(idx, l, r);
	if (b < l || a > r) return;
	if (a <= l && r <= b) {
		lazy[idx] = val;
		propagate(idx, l, r);
		return;
	}

	int m = (l+r) / 2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;

	update(left, l, m, a, b, val); update(right, m+1, r, a, b, val);
	seg[idx] = seg[left] + seg[right];
}
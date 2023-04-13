vector<int> parent(MAXN);
vector<int> size(MAXN);

void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
}

int findSet(int x) {
	return x == parent[x] ? x : (parent[x] = findSet(parent[x]));
}

bool isSameSet(int a, int b) {
	return findSet(a) == findSet(b);
}

void uniteSet(int a, int b) {
	a = findSet(a); b = findSet(b);
	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	parent[b] = a;
}
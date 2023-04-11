vector<int> parent(MAXN);
vector<int> size(MAXN);
vector<pair<int, pii>> ways; // {weight, {u, v}}


// O (E log V)
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

ll kruskal() {
	ll mst_cost = 0;

	sort(ways.begin(), ways.end());
	for (int i = 0; i < ways.size(); i++) {
		pair<int, pii> vtx = ways[i];

		if(!isSameSet(vtx.se.fi, vtx.se.se)) {
			mst_cost += vtx.fi;
			uniteSet(vtx.se.fi, vtx.se.se);
		}
	}
	return mst_cost;
}
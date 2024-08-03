#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define vpi vector<pi> 
#define si set<int>
#define vsi vector<si>
#define rep(i,a,b) for(int i=a; i<b; i++)

class _dsu {
	vi parent;
	vi size, rank;

public:
	vsi v_sets;

	_dsu(int n) {
		parent.resize(n);
		rank = vi(n, 0); size = vi(n, 1);
		v_sets.resize(n);

		_make_set(n);
	}

	void _make_set(int n) {
		for (int i=0; i<n; i++)
			parent[i] = i;
	}

	int _find_parent(int a) {
		if (parent[a] == a) return parent[a];
		return parent[a] = _find_parent(parent[a]);
	}

	bool _union_rank(int a, int b) {
		a = _find_parent(a);
		b = _find_parent(b);

		if (a == b) return false;

		if (rank[a] >= rank[b]) {
			parent[b] = a;
			rank[a]++;
		} else {
			parent[a] = b;
			rank[b]++;
		}

		return true;
	}

	bool _union_size(int a, int b) {
		a = _find_parent(a);
		b = _find_parent(b);

		if (a == b) return false;

		if (rank[a] >= rank[b]) {
			parent[b] = a;
			rank[a]++;
		} else {
			parent[a] = b;
			rank[b]++;
		}

		return true;
	}

	bool _same_components(int a, int b) {
		return _find_parent(a) == _find_parent(b);
	}
};

int countGoodEdges(int n, vi &a, vi &p) {
	_dsu dsu(n);

	vpi edges; int root = -1;

	for (int i=0; i<n; i++) {	
		dsu.v_sets[i].insert(a[i]);
		if (p[i] == 0) {
			root = i;
		} else {
			edges.push_back({p[i], i});
		}
	}

	int good_edges = 0;

	for (auto &[a, b] : edges) {
		if (!dsu._same_components(a, b)) {
			int par_a = dsu._find_parent(a);
			int par_b = dsu._find_parent(b);

			const set<int>& comp_a = dsu.v_sets[par_a];
			const set<int>& comp_b = dsu.v_sets[par_b];

			set<int> un;
			set_union(comp_a.begin(), comp_a.end(), comp_b.begin(), comp_b.end(), inserter(un, un.begin()));

			if (un.size() == comp_a.size() + comp_b.size())
				good_edges += 1;

			if (dsu._union_size(a, b)) {
				int par = dsu._find_parent(a);

				dsu.v_sets[par].insert(comp_b.begin(), comp_b.end());
			}
		}
	}

	return good_edges;
}

main() {
	int n, te; cin >> n;

	vi a(n), p(n);
	for (int i=0; i<n; i++) {
		cin >> te; a.push_back(te);
	}

	for (int i=0; i<n; i++) {
		cin >> te; p.push_back(te);
	}


	cout << countGoodEdges(n, a, p) << endl;

}
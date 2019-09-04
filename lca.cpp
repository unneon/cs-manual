/// Name: LCA
/// Description: Lowest Common Ancestor
/// Detail:
/// Guarantee: LCA<l> preprocessLCA(
/// Dependencies: graph, dfs
/// Parent: graph
template <int l> struct LCA {
	vector<array<int, l>> jump;
	vector<int> depth;
	LCA(int n):jump(n),depth(n,-1){}
	int operator()(int a, int b) const {
		if (depth[a] > depth[b])
			swap(a, b);
		for (auto e=l-1; e>=0; --e)
			if (depth[b] - (1 << e) >= depth[a])
				b = jump[b][e];
		if (a == b)
			return a;
		for (auto e=l-1; e>=0; --e)
			if (jump[a][e] != jump[b][e])
				a = jump[a][e], b = jump[b][e];
		return jump[a][0];
	}
	int dist(int a, int b) const {
		return depth[a] + depth[b] - 2*depth[(*this)(a, b)];
	}
	void recompute(int v, int u) {
		jump[v][0] = u;
		for (auto e=1; e<l; ++e)
			jump[v][e] = jump[jump[v][e-1]][e-1];
		depth[v] = depth[u] + 1;
	}
};
template <int l> LCA<l> preprocessLCA(int root) const {
	auto lca = LCA<l>(size());
	lca.recompute(root, root);
	DFS(root, {}, {}, [&](int v, int u){ lca.recompute(u, v); }, {}, {});
	return lca;
}

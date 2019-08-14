/// Name: LCA
/// Description: Lowest Common Ancestor
/// Detail:
/// Guarantee: LCA<l> preprocessLCA(
/// Dependencies: graph, dfs
/// Parent: graph
template <int l> struct LCA {
	vector<array<int, l>> jump;
	vector<int> depth;
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
};
template <int l> LCA<l> preprocessLCA(int root) const {
	auto jump = vector<array<int, l>>(size());
	auto depth = vector<int>(size(), 0);
	fill(jump[root].begin(), jump[root].end(), root);
	DFS(root, {}, {}, [&](int v, int u){
		depth[u] = depth[v] + 1;
		jump[u][0] = v;
		for (auto e=1; e<l; ++e)
			jump[u][e] = jump[jump[u][e-1]][e-1];
	}, {}, {});
	return LCA<l>{move(jump),move(depth)};
}

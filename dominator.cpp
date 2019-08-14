/// Name: Dominator tree
/// Description:
/// Detail:
/// Guarantee: Graph dominatorTree(
/// Dependencies: graph, dfs
/// Parent: graph
Graph dominatorTree(int source) const {
	static auto iota = [](int n) { auto xs = vector<int>(n); std::iota(xs.begin(), xs.end(), 0); return xs; };
	struct SpecialFU {
		SpecialFU(int n, const vector<int>& sdom):up(n,-1),label(iota(n)),sdom(sdom){}
		int eval(int v) {
			if (up[v] != -1 and up[up[v]] != -1) {
				eval(up[v]);
				if (sdom[label[up[v]]] < sdom[label[v]])
					label[v] = label[up[v]];
				up[v] = up[up[v]];
			}
			return label[v];
		}
		void link(int v, int w) { up[w] = v; }
		vector<int> up, label;
		const vector<int>& sdom;
	};
	auto n = size();
	auto tree = Graph(n);
	auto reverse = Graph(n);
	auto bucket = vector<vector<int>>(n);
	auto sdom = iota(n);
	auto parent = vector<int>(n, -1);
	auto dom = iota(n);
	auto disjoint = SpecialFU(n, sdom);
	auto enter = vector<int>(n, -1);
	auto preorder = vector<int>(n, -1);
	auto t = 0;
	DFS(source, [&](int v){
		enter[v] = t;
		preorder[t] = v;
		++t;
	}, {}, {}, [&](int v, int u){
		parent[enter[u]] = enter[v];
		reverse.addEdge1(enter[u], enter[v]);
	}, [&](int v, int u){
		reverse.addEdge1(enter[u], enter[v]);
	});
	for (auto i=t-1; i>=0; --i) {
		for (auto j : reverse.edges[i])
			sdom[i] = min(sdom[i], sdom[disjoint.eval(j)]);
		if (i > 0)
			bucket[sdom[i]].push_back(i);
		for (auto w : bucket[i]) {
			auto v = disjoint.eval(w);
			if (sdom[v] == sdom[w])
				dom[w] = sdom[w];
			else
				dom[w] = v;
		}
		if (i > 0)
			disjoint.link(parent[i], i);
	}
	for (auto i=1; i<t; ++i) {
		if (dom[i] != sdom[i])
			dom[i] = dom[dom[i]];
		tree.addEdge2(preorder[i], preorder[dom[i]]);
	}
	return tree;
}

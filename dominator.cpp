/// Name: Dominator tree
/// Description:
/// Detail:
/// Guarantee: LCA<l> dominatorTree(
/// Dependencies: graph, lca, transpose-graph, toposort
/// Parent: graph
template <int l> LCA<l> dominatorTree(int source) const {
	auto trans = transposed();
	auto lca = LCA<l>(size());
	lca.recompute(source, source);
	for (auto v : toposort())
		if (v != source) {
			auto parent = trans.edges[v][0];
			for (auto i=1; i<(int)trans.edges[v].size(); ++i)
				parent = lca(parent, trans.edges[v][i]);
			lca.recompute(v, parent);
		}
	return lca;
}

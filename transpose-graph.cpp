/// Name: Transposed graph
/// Description:
/// Detail:
/// Request: transposed
/// Guarantee: Graph transposed(
/// Dependencies: graph
/// Parent: graph
Graph transposed() const {
	auto tg = Graph(size());
	for (auto v=0; v<size(); ++v)
		for (auto u : edges[v])
			tg.addEdge1(u, v);
	return tg;
}

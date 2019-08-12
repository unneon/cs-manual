/// Name: DFS (impl)
/// Description: Depth-First Search
/// Detail:
/// Request: implDFS
/// Guarantee: void implDFS(
/// Dependencies: graph, dummyf
/// Parent: graph
template <typename Pre=Dummyf, typename Post=Dummyf, typename PreE=Dummyf, typename PostE=Dummyf, typename FailE=Dummyf> void implDFS(int v, vector<bool>& visit, Pre pre, Post post, PreE pree, PostE poste, FailE faile) const {
	visit[v] = true;
	pre(v);
	for (auto u : edges[v])
		if (not visit[u])
			pree(v, u), implDFS(u, visit, pre, post, pree, poste, faile), poste(v, u);
		else
			faile(v, u);
	post(v);
}

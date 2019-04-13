/// Name: DFS (all)
/// Description:
/// Detail:
/// Request: allDFS
/// Guarantee: void allDFS(
/// Dependencies: graph, dummyf, dfs-impl
/// Parent: graph
template <typename Pre=Dummyf, typename Post=Dummyf, typename PreE=Dummyf, typename PostE=Dummyf, typename FailE=Dummyf> void allDFS(Pre pre, Post post, PreE pree, PostE poste, FailE faile) const {
	auto visit = vector<bool>(size(), false);
	for (auto v=0; v<size(); ++v)
		if (not visit[v])
			implDFS(v, visit, pre, post, pree, poste, faile);
}
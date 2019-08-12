/// Name: DFS
/// Description: Depth-First Search
/// Detail:
/// Request: DFS
/// Guarantee: void DFS(
/// Dependencies: graph, dummyf, dfs-impl
/// Parent: graph
template <typename Pre=Dummyf, typename Post=Dummyf, typename PreE=Dummyf, typename PostE=Dummyf, typename FailE=Dummyf> void DFS(int source, Pre pre, Post post, PreE pree, PostE poste, FailE faile) const {
	auto visit = vector<bool>(size(), false);
	implDFS(source, visit, pre, post, pree, poste, faile);
}

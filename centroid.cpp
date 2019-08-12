/// Name: Centroid
/// Description: decomposition
/// Detail:
/// Request: centroid
/// Guarantee: void centroid(
/// Dependencies: graph, dfs-impl
/// Parent: graph
template <typename F> void centroid(F f) const {
	auto visit = vector<bool>(size(), false);
	auto subsize = vector<int>(size());
	implCentroid(0, -1, visit, subsize, f);
}
template <typename F> void implCentroid(int root, int parent, vector<bool>& visit, vector<int>& subsize, F f) const {
	implDFS(root, visit, [&](int v){
		subsize[v] = 1;
	}, [&](int v){
		visit[v] = false;
	}, {}, [&](int v, int u){
		subsize[v] += subsize[u];
	}, {});
	auto c = findCentroid(root, root, visit, subsize);
	f(c, parent, visit);
	visit[c] = true;
	for (auto u : edges[c])
		if (not visit[u])
			implCentroid(u, c, visit, subsize, f);
}
int findCentroid(int v, int root, vector<bool>& visit, const vector<int>& subsize) const {
	for (auto u : edges[v])
		if (subsize[u] < subsize[v] and 2*subsize[u] >= subsize[root] and not visit[u])
			return findCentroid(u, root, visit, subsize);
	return v;
}

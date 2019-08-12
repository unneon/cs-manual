/// Name: Toposort
/// Description:
/// Detail:
/// Request: toposort
/// Guarantee: vector<int> toposort(
/// Dependencies: graph
/// Parent: graph
vector<int> toposort() const {
	auto deg = vector<int>(size(), 0);
	auto que = vector<int>();
	for (auto v=0; v<size(); ++v)
		for (auto u : edges[v])
			++deg[u];
	for (auto v=0; v<size(); ++v)
		if (deg[v] == 0)
			que.push_back(v);
	for (auto i=0; i<(int)que.size(); ++i)
		for (auto u : edges[que[i]])
			if (--deg[u] == 0)
				que.push_back(u);
	return que;
}

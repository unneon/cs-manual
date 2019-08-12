/// Name: Bridges
/// Description:
/// Detail:
/// Request: bridges
/// Guarantee: vector<bool> bridges(
/// Dependencies: graph, dfs-all
/// Parent: graph
vector<bool> bridges() const {
	auto t = 0;
	auto enter = vector<int>(n, -1);
	auto bridge = vector<bool>(n, false);
	auto parent = vector<int>(n, -1);
	auto low = vector<int>(n, -1);
	auto backburn = vector<bool>(n, false);
	graph.allDFS([&](int v){
		enter[v] = t++;
		low[v] = enter[v];
	}, {}, [&](int v, int u){
		parent[u] = v;
	}, [&](int v, int u){
		low[v] = min(low[v], low[u]);
		if (low[u] == enter[u])
			bridge[u] = true;
	}, [&](int v, int u){
		if (u != parent[v] or backburn[v])
			low[v] = min(low[v], enter[u]);
		else
			backburn[v] = true;
	});
	return bridge;
}

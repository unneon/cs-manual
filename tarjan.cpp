/// Name: Tarjan
/// Description: Strongly connected components
/// Detail:
/// Request: tarjan
/// Guarantee: void tarjan(
/// Dependencies: graph, dfs-all
/// Parent: graph
template <typename F1> void tarjan(F1 f1) const {
	auto enter = vector<int>(size(), -1);
	auto low = vector<int>(size(), -1);
	auto t = 0;
	auto stack = vector<int>();
	auto active = vector<bool>(size(), false);
	allDFS([&](int v){
		enter[v] = low[v] = t++;
		stack.push_back(v);
		active[v] = true;
	}, [&](int v){
		if (enter[v] == low[v]) {
			auto f2 = f1(v);
			while (active[v]) {
				auto u = stack.back();
				stack.pop_back();
				active[u] = false;
				f2(u);
			}
		}
	}, {}, [&](int v, int u){
		low[v] = min(low[v], low[u]);
	}, [&](int v, int u){
		if (active[u])
			low[v] = min(low[v], enter[u]);
	});
}

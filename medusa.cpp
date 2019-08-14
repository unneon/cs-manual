/// Name: Medusa
/// Description: Graph with only one outgoing edge
/// Detail:
/// Guarantee: struct Medusa {
/// Dependencies:
/// Parent:
struct Medusa {
	template <typename E> Medusa(int n, E edges):n(n),link(n,-1),rep(n,-1){
		for (auto v=0; v<n; ++v)
			link[v] = edges(v);
		auto visit = vector<bool>(n, false);
		auto slowFindRep = [&](int v){
			while (rep[v] == -1 and visit[v] == false)
				visit[v] = true, v = link[v];
			return rep[v] == -1 ? v : rep[v];
		};
		auto fillRep = [&](int v, int r){
			while (rep[v] == -1)
				rep[v] = r, v = link[v];
		};
		for (auto v=0; v<n; ++v)
			fillRep(v, slowFindRep(v));
	}
	template <typename T, typename F> vector<T> computeCycleProperty(F f) const {
		auto visit = vector<bool>(n, false);
		auto answer = vector<T>(n);
		for (auto v=0; v<n; ++v) {
			if (not visit[rep[v]])
				answer[rep[v]] = f(rep[v]), visit[rep[v]] = true;
			answer[v] = answer[rep[v]];
		}
		return answer;
	}
	template <typename F> void iterateCycle(int v, F f) const {
		f(v);
		for (auto u=link[v]; u!=v; u=link[u])
			f(u);
	}
	int n;
	vector<int> link, rep;
};

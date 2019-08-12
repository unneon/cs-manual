# Dinic

## Code

```cpp
template <typename T, T oo> struct FlowGraph {
	struct Edge {
		int dest;
		unique_ptr<T> cap;
		T* revCap;
	};
	FlowGraph(int n):edges(n){}
	T* addEdge(int v, int u, T capacity) {
		edges[v].push_back(Edge{u, unique_ptr<T>(new T(capacity)), nullptr});
		edges[u].push_back(Edge{v, unique_ptr<T>(new T(0)), edges[v].back().cap.get()});
		edges[v].back().revCap = edges[u].back().cap.get();
		return edges[v].back().cap.get();
	}
	void dinic(int source, int sink) {
		while (true) {
			auto dist = dinicBFS(source);
			if (dist[sink] == -1)
				break;
			auto next = vector<int>(edges.size(), 0); 
			dinicPush(source, +oo, sink, next, dist);
		}
	}
	vector<int> dinicBFS(int source) {
		auto dist = vector<int>(edges.size(), -1);
		dist[source] = 0;
		auto que = vector<int>({source});
		for (auto i=0; i<(int)que.size(); ++i) {
			for (auto& edge : edges[que[i]]) {
				if (*edge.cap == 0) continue;
				if (dist[edge.dest] != -1) continue;
				dist[edge.dest] = dist[que[i]] + 1;
				que.push_back(edge.dest);
			}
		}
		return dist;
	}
	int dinicPush(int v, int wave, int sink, vector<int>& next, const vector<int>& dist) {
		if (wave == 0 or v == sink) return wave;
		auto total = 0;
		for (auto& i=next[v]; i<(int)edges[v].size(); ++i) {
			auto& edge = edges[v][i];
			if (dist[v] + 1 != dist[edge.dest]) continue;
			auto piped = dinicPush(edge.dest, min(wave, *edge.cap), sink, next, dist);
			wave -= piped;
			*edge.cap -= piped;
			*edge.revCap += piped;
			total += piped;
			if (wave == 0) break;
		}
		return total;
	}
	template <typename F> void onCut(int source, F f) {
		auto que = vector<int>({source});
		auto visit = vector<bool>(edges.size(), false);
		visit[source] = true;
		for (auto i=0; i<(int)que.size(); ++i)
			for (auto& edge : edges[que[i]])
				if (*edge.cap != 0 and not visit[edge.dest])
					que.push_back(edge.dest), visit[edge.dest] = true;
		for (auto v : que)
			for (auto& edge : edges[v])
				if (*edge.cap == 0 and not visit[edge.dest])
					f(edge.cap.get());
	}
	vector<vector<Edge>> edges;
};
```

## Problems

- [Petya and Graph](https://codeforces.com/contest/1082/problem/G)

## Sources

- After-school lecture

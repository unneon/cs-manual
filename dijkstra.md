# Dijkstra

## Code

```cpp
auto dist = vector<long long>(size(), numeric_limits<long long>::max() / 2);
dist[source] = 0ll;
auto comp = [&](int v1, int v2){ return tie(dist[v1], v1) < tie(dist[v2], v2); };
auto que = set<int, decltype(comp)>({source}, comp);
while (not que.empty()) {
	auto v = *que.begin();
	que.erase(que.begin());
	for (auto e : edges[v])
		if (dist[e.to] > dist[v] + e.weight) {
			if (que.count(e.to))
				que.erase(que.find(e.to));
			dist[e.to] = dist[v] + e.weight;
			que.insert(e.to);
		}
}
```

## Problems

## Sources

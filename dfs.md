# DFS

## Code

```cpp
template <typename Pre=Dummyf, typename Post=Dummyf, typename PreE=Dummyf, typename PostE=Dummyf, typename FailE=Dummyf> void DFS(int source, Pre pre, Post post, PreE pree, PostE poste, FailE faile) const {
	auto visit = vector<bool>(size(), false);
	implDFS(source, visit, pre, post, pree, poste, faile);
}
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
```

### `Dummyf` convenience wrapper
```cpp
struct Dummyf { template <typename... Ts> void operator()(Ts&&...) {} };
```

### DFS over all connected components
```cpp
template <typename Pre=Dummyf, typename Post=Dummyf, typename PreE=Dummyf, typename PostE=Dummyf, typename FailE=Dummyf> void allDFS(Pre pre, Post post, PreE pree, PostE poste, FailE faile) const {
	auto visit = vector<bool>(size(), false);
	for (auto v=0; v<size(); ++v)
		if (not visit[v])
			implDFS(v, visit, pre, post, pree, poste, faile);
}
```

### Example usage

#### Counting subtree sizes

```cpp
auto subsize = vector<int>(size(), 1);
DFS(0, {}, {}, {}, [&](int v, int u){
	subsize[v] += subsize[u];
}, {});
```

## Problems

## Sources

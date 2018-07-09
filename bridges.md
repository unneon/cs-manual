# Bridges

## Code

```cpp
auto t = 0;
auto enter = vector<int>(n, -1);
auto bridge = vector<bool>(n, false);
auto parent = vector<int>(n, -1);
auto low = vector<int>(n, 0);
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
```

## Problems

- [One-Way Streets (CEOI 2017)](https://ceoi2017.acm.si/files/ceoi2017-statements-day1.zip)
- [Tourist Reform](http://codeforces.com/contest/732/problem/F)
- [Break Up](http://codeforces.com/contest/700/problem/C)
- [Critical Edges](https://www.spoj.com/problems/EC_P/)
- [Submerging Islands](https://www.spoj.com/problems/SUBMERGE/)
- [King Graffs Defense](https://www.spoj.com/problems/GRAFFDEF/)

## Sources

- http://codeforces.com/blog/entry/55219

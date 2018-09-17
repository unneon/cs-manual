# Weighted graph

## Code

```cpp
struct Graph {
	struct Edge { int to, weight; };
	Graph(int n):edges(n){}
	void addEdge1(int a, int b, int w) { edges[a].push_back(Edge{b, w}); }
	void addEdge2(int a, int b, int w) { addEdge1(a, b, w); addEdge1(b, a, w); }
	int size() const { return (int)edges.size(); }
	vector<vector<Edge>> edges;
};
```

## Problems

## Sources

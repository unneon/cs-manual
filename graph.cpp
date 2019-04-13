/// Name: Graph
/// Description:
/// Detail:
/// Request: Graph
/// Guarantee: struct Graph {
/// Dependencies:
/// Parent:
struct Graph {
	Graph(int n):edges(n){}
	void addEdge1(int a, int b) { edges[a].push_back(b); }
	void addEdge2(int a, int b) { addEdge1(a, b); addEdge1(b, a); }
	int size() const { return (int)edges.size(); }
	vector<vector<int>> edges;
};
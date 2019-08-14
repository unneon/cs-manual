/// Name: FU
/// Description: Find & Union on disjoint sets
/// Detail:
/// Guarantee: struct FU {
/// Dependencies:
/// Parent:
struct FU {
	FU(int n):link(n,-1),rank(n,0){}
	int find(int i) const { return link[i] == -1 ? i : (link[i] = find(link[i])); }
	bool tryUnion(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (rank[a] < rank[b]) swap(a, b);
		if (rank[a] == rank[b]) ++rank[a];
		link[b] = a;
		return true;
	}
	mutable vector<int> link;
	vector<int> rank;
};

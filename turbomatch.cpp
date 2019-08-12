/// Name: Turbomatching
/// Description: Maximal bipartite matching
/// Detail:
/// Request: turbomatch
/// Guarantee: vector<int> turbomatch(
/// Dependencies: graph
/// Parent: graph
vector<int> turbomatch() const {
	auto match = vector<int>(size(), -1);
	auto visit = vector<bool>(size(), false);
	auto changed = true;
	while (changed) {
		changed = false;
		for (auto v=0; v<size(); ++v)
			if (match[v] == -1)
				changed |= implTM(v, match, visit);
		fill(visit.begin(), visit.end(), false);
	}
	return match;
}
bool implTM(int v, vector<int>& match, vector<bool>& visit) const {
	visit[v] = true;
	for (auto u : edges[v]) {
		if (match[u] == -1 or (not visit[match[u]] and implTM(match[u], match, visit))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

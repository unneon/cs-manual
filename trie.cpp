/// Name: Trie
/// Description:
/// Detail:
/// Guarantee: struct Trie {
/// Dependencies:
/// Parent:
template <typename Node> struct Trie {
	template <typename A, A _a0, int alpha> struct BaseNode {
		static const A a0 = _a0;
		explicit BaseNode(Node* parent):parent(parent){}
		Node* extend(int ic) { return not kids[ic] and parent ? suflink->extend(ic) : kids[ic] ? kids[ic] : (Node*)this; }
		void buildSuflink() { suflink = parent and parent->parent ? parent->suflink->extend(lastIC()) : parent ? parent : (Node*)this; }
		int lastIC() { return (int)(find(parent->kids.begin(), parent->kids.end(), (Node*)this) - parent->kids.begin()); }
		Node* parent, *suflink = nullptr;
		array<Node*, alpha> kids{};
	};
	Trie():root(new Node(nullptr)){}
	template <typename S> Node* addPattern(S&& pattern) {
		auto v = root;
		for (auto c : pattern)
			v = v->kids[c-Node::a0] = v->kids[c-Node::a0] ? v->kids[c-Node::a0] : new Node(v);
		return v;
	}
	vector<Node*> BFS() {
		auto que = vector<Node*>({root});
		for (auto i=0; i<(int)que.size(); ++i)
			for (auto kid : que[i]->kids)
				if (kid)
					que.push_back(kid);
		return que;
	}
	void buildSuflinks() { for (auto v : BFS()) v->buildSuflink(); }
	Node* root;
};

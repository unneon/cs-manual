/// Name: Li Chao
/// Description: tree
/// Detail:
/// Request: LiChao
/// Guarantee: struct LiChao {
/// Dependencies:
/// Parent:
template <typename T> struct LiChao {
	struct Linf {
		T a, b;
		T operator()(int x) const { return a*x+b; }
	};
	LiChao(int n):base(1){
		while (base<n) base *= 2;
		nodes.resize(base*2, Linf{0, numeric_limits<T>::max()});
	}
	T min(int x) const {
		auto r = numeric_limits<T>::max();
		for (auto v=base+x; v>0; v/=2)
			r = std::min(r, nodes[v](x));
		return r;
	}
	void insert(T a, T b) { implInsert({a, b}, 0, base, 1); }
	void implInsert(Linf f, int i, int e, int v) {
		auto& g = nodes[v];
		auto m = (i+e)/2;
		if (f(m) < g(m)) swap(f, g);
		if (e - i == 1) return;
		if ((f(i) < g(i)) == (f(m) < g(m))) implInsert(f, m, e, v*2+1);
		else implInsert(f, i, m, v*2);
	}
	int base;
	vector<Linf> nodes;
};

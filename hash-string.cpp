/// Name: String hashing
/// Description:
/// Detail:
/// Guarantee: struct Hashes {
/// Dependencies: modulo
/// Parent:
template <typename M> struct Hashes {
	struct Base {
		Base(M p, int n):exp(n+1),inv(n+1){
			exp[0] = 1;
			for (auto i=1; i<=n; ++i)
				exp[i] = exp[i-1] * p;
			inv[n] = 1 / exp[n];
			for (auto i=n-1; i>=0; --i)
				inv[i] = inv[i+1] * p;
		}
		Hashes compute(const string& text) { return Hashes<M>(text, *this); }
		vector<M> exp, inv;
	};
	Hashes(const string& text, const Base& base):sums(text.size()+1),base(base){
		for (auto i=0; i<(int)text.size(); ++i)
			sums[i+1] = sums[i] + text[i] * base.exp[i];
	}
	M slice(int i, int j) const {
		return (sums[j] - sums[i]) * base.inv[i];
	}
	vector<M> sums;
	const Base& base;
};

/// Name: Scaler
/// Description:
/// Detail:
/// Guarantee: struct Scaler {
/// Dependencies:
/// Parent:
template <typename T> struct Scaler {
	struct Build {
		vector<T> xs;
		void notice(T x) { xs.push_back(x); }
		Scaler<T> prepare() {
			sort(xs.begin(), xs.end());
			xs.erase(unique(xs.begin(), xs.end()), xs.end());
			return Scaler<T>{move(xs)};
		}
	};
	int scale(const T& x) { return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin()); }
	typename vector<T>::const_reference unscale(int i) { return xs[i]; }
	int size() const { return (int)xs.size(); }
	vector<T> xs;
};

/// Name: Binary search
/// Description:
/// Detail:
/// Request: binsearch
/// Guarantee: T binsearch(
/// Dependencies:
/// Parent:
template <typename T, typename F> T binsearch(T a, T b, F f) {
	if (b - a == 0) return a;
	auto m = (a + b) / 2;
	return f(m) ? binsearch(a, m, f) : binsearch(m+1, b, f);
}

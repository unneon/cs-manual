/// Name: Binary search (float)
/// Description:
/// Detail:
/// Guarantee: T binsearchf(
/// Dependencies:
/// Parent:
template <typename T, typename F> T binsearchf(T a, T b, int iters, F f) {
	if (iters <= 0) return a;
	auto m = (a + b) / 2;
	return f(m) ? binsearchf(a, m, iters-1, f) : binsearchf(m, b, iters-1, f);
}

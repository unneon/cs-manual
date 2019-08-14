/// Name: Matrix: Loading
/// Description:
/// Detail:
/// Guarantee: static auto load(int w, int h, F F) -> Matrix
/// Dependencies: matrix, load
/// Parent: matrix
template <typename F> static Matrix load(int w, int h) { return load(w, h, [&](T x){ return move(x); }); }
template <typename F> static auto load(int w, int h, F f) -> Matrix<decltype(f(declval<T>()))> {
	auto rs = Matrix<decltype(f(declval<T>()))>(w, h, {});
	for (auto y=0; y<h; ++y)
		for (auto x=0; x<w; ++x)
			rs[x][y] = f(::load<T>());
	return rs;
}

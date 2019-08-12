/// Name: FFT
/// Description: Fast Fourier Transform
/// Detail:
/// Request: FFT
/// Guarantee: struct FFT {
/// Dependencies:
/// Parent:
template <typename R> struct FFT {
	struct C {
		C(R a = 0, R b = 0):a(a),b(b){}
		friend C operator+(const C& x, const C& y) { return C(x.a + y.a, x.b + y.b); }
		friend C operator-(const C& x, const C& y) { return C(x.a - y.a, x.b - y.b); }
		friend C operator*(const C& x, const C& y) { return C(x.a * y.a - x.b * y.b, x.a * y.b + x.b * y.a); }
		friend C operator/(const C& x, const R& y) { return C(x.a / y, x.b / y); }
		friend C& operator*=(C& x, const C& y) { return x = x * y; }
		friend C& operator/=(C& x, const R& y) { return x = x / y; }
		const R& real() const { return a; }
		R a, b;
	};
	FFT(int n1, int n2):n(1){
		while (n < n1+n2-1)
			n *= 2;
	}
	template <bool invert> void dft(vector<C>& a) {
		a.resize(n, 0);
		for (auto i=1, j=0; i<n; ++i) {
			auto bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;
			if (i < j)
				swap(a[i], a[j]);
		}
		auto pi = acos(R(-1));
		for (auto l=2; l<=n; l<<=1) {
			auto angle = (invert ? -1 : 1) * 2 * pi / l;
			auto wl = C(cos(angle), sin(angle));
			for (auto i=0; i<n; i+=l) {
				auto w = C(1);
				for (auto j=0; j<l/2; ++j) {
					auto y0 = a[i+j];
					auto y1 = a[i+j+l/2] * w;
					a[i+j] = y0 + y1;
					a[i+j+l/2] = y0 - y1;
					w *= wl;
				}
			}
		}
		if (invert)
			for (auto& ai : a)
				ai /= n;
	}
	void fft(vector<C>& a, vector<C>& b) {
		dft<false>(a);
		dft<false>(b);
		hadamard(a, b);
		dft<true>(a);
	}
	void hadamard(vector<C>& a, const vector<C>& b) {
		for (auto i=0; i<n; ++i)
			a[i] *= b[i];
	}
	int n;
};

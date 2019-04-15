/// Name: FFT
/// Description: Fast Fourier Transform
/// Detail:
/// Request: fft
/// Guarantee: vector<C> fft(
/// Dependencies:
/// Parent:
template <typename C, bool invert> vector<C> dft(vector<C> a) {
    auto n = (int)a.size();
    for (auto i=1, j=0; i<n; ++i) {
        auto bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    auto pi = acos((typename C::value_type)-1);
    for (auto l=2; l<=n; l<<=1) {
        auto angle = (invert ? -1 : 1) * 2 * pi / l;
        auto wl = C(cos(angle), sin(angle));
        for (auto i=0; i<n; i+=l) {
            auto w = C(1, 0);
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
    return a;
}
template <typename C> vector<C> fft(vector<C> a, vector<C> b) {
    auto n = 1;
    while (n < (int)a.size() + (int)b.size() - 1)
        n *= 2;
    a.resize(n, 0);
    b.resize(n, 0);
    a = dft<C, false>(move(a));
    b = dft<C, false>(move(b));
    for (auto i=0; i<n; ++i)
        a[i] *= b[i];
    a = dft<C, true>(move(a));
    return a;
}

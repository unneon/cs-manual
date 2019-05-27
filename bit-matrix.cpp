/// Name: Bit matrix
/// Description: Vectorized Matrix<bool>
/// Detail:
/// Request: BitMatrix
/// Guarantee: struct BitMatrix {
/// Dependencies:
/// Parent:
struct BitMatrix {
    BitMatrix(unsigned h, unsigned w):h(h),w(w),rm2(h*pcols(),0){}
    bool get(unsigned y, unsigned x) const {
        auto chunk = rm2[y*pcols()+(x / 32)];
        return (chunk & (1 << (x % 32)));
    }
    void set(unsigned y, unsigned x, bool val) {
        auto& chunk = rm2[y*pcols()+(x / 32)];
        auto bit = 1 << (x % 32);
        if (val)
            chunk |= bit;
        else
            chunk &= ~bit;
    }
    unsigned pcols() const { return (w + 31) / 32; }
    BitMatrix transpose() const {
        auto t = BitMatrix(w, h);
        for (auto y=0u; y<h; ++y)
            for (auto x=0u; x<w; ++x)
                t.set(x, y, get(y, x));
        return t;
    }
    friend BitMatrix operator|(const BitMatrix& a, const BitMatrix& b) {
        assert(a.h == b.h);
        assert(a.w == b.w);
        auto c = BitMatrix(a.h, a.w);
        for (auto i=0u; i<c.rm2.size(); ++i)
            c.rm2[i] = a.rm2[i] | b.rm2[i];
        return c;
    }
    friend BitMatrix operator&(const BitMatrix& a, const BitMatrix& b) {
        assert(a.h == b.h);
        assert(a.w == b.w);
        auto c = BitMatrix(a.h, a.w);
        for (auto i=0u; i<c.rm2.size(); ++i)
            c.rm2[i] = a.rm2[i] & b.rm2[i];
        return c;
    }
    friend BitMatrix operator*(const BitMatrix& a, const BitMatrix& b) {
        assert(a.w == b.h);
        auto bt = b.transpose();
        auto c = BitMatrix(a.h, b.w);
        for (auto y=0u; y<a.h; ++y)
            for (auto x=0u; x<b.w; ++x) {
                auto s = false;
                for (auto i=0u; i*32<a.w and not s; ++i)
                    s = s or (a.rm2[y*a.pcols()+i] & bt.rm2[x*b.pcols()+i]) != 0;
                c.set(y, x, s);
            }
        return c;
    }
    static BitMatrix identity(unsigned n) {
        auto m = BitMatrix(n, n);
        for (auto i=0u; i<n; ++i)
            m.set(i, i, true);
        return m;
    }
    unsigned h, w;
    vector<unsigned> rm2;
};

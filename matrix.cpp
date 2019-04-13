/// Name: Matrix
/// Description:
/// Detail:
/// Request: Matrix
/// Guarantee: struct Matrix {
/// Dependencies:
/// Parent:
template <typename T> struct Matrix {
    Matrix(int w, int h, const T& x):w(w),h(h),data(w*h,x){}
    T sum() const { return accumulate(data.begin(), data.end(), (T)0); }
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        auto c = Matrix(b.w, a.h, 0);
        for (auto x=0; x<c.w; ++x)
            for (auto y=0; y<c.h; ++y)
                for (auto i=0; i<a.w; ++i)
                    c[x][y] += a[i][y] * b[x][i];
        return c;
    }
    template <typename E> Matrix exp(E e) const {
        if (e == 0) return identity(w);
        if (e % 2 == 0) return (*this**this).exp(e/2);
        return *this*(*this**this).exp(e/2);
    }
    static Matrix<T> identity(int n) {
        auto mat = Matrix<T>(n, n, 0);
        for (auto i=0; i<n; ++i)
            mat[i][i] = 1;
        return mat;
    }
    struct Col { int x; Matrix& m; T& operator[](int y) { return m.data[y*m.w+x]; } };
    struct CCol { int x; const Matrix& m; const T& operator[](int y) { return m.data[y*m.w+x]; } };
    Col operator[](int x) { return {x,*this}; }
    CCol operator[](int x) const { return {x,*this}; }
    int w, h;
    vector<T> data;
};

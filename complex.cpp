/// Name: Complex
/// Description: arithmetic
/// Detail:
/// Request: Complex
/// Guarantee: struct Complex {
/// Dependencies:
/// Parent:
template <typename R> struct Complex {
    using value_type = R;
    Complex(R a = 0, R b = 0):a(a),b(b){}
    friend Complex operator+(const Complex& a, const Complex& b) { return Complex<R>(a.a + b.a, a.b + b.b); }
    friend Complex operator-(const Complex& a, const Complex& b) { return Complex<R>(a.a - b.a, a.b - b.b); }
    friend Complex operator*(const Complex& a, const Complex& b) { return Complex<R>(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a); }
    friend Complex operator/(const Complex& a, const R& b) { return Complex<R>(a.a / b, a.b / b); }
    friend Complex& operator*=(Complex& a, const Complex& b) { return a = a * b; }
    friend Complex& operator/=(Complex& a, const R& b) { return a = a / b; }
    const R& real() const { return a; }
    R a, b;
};
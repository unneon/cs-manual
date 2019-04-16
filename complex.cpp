/// Name: Complex
/// Description: arithmetic
/// Detail:
/// Request: Complex
/// Guarantee: struct Complex {
/// Dependencies:
/// Parent:
template <typename R> struct Complex {
    Complex(R a = 0, R b = 0):a(a),b(b){}
    friend Complex operator+(const Complex& x, const Complex& y) { return Complex(x.a + y.a, x.b + y.b); }
    friend Complex operator-(const Complex& x, const Complex& y) { return Complex(x.a - y.a, x.b - y.b); }
    friend Complex operator*(const Complex& x, const Complex& y) { return Complex(x.a * y.a - x.b * y.b, x.a * y.b + x.b * y.a); }
    friend Complex operator/(const Complex& x, const R& y) { return Complex(x.a / y, x.b / y); }
    friend Complex& operator*=(Complex& x, const Complex& y) { return x = x * y; }
    friend Complex& operator/=(Complex& x, const R& y) { return x = x / y; }
    const R& real() const { return a; }
    R a, b;
};
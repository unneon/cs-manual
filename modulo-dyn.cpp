/// Name: Modulo (dynamic)
/// Description: Modular arithmetic with dynamic m
/// Detail:
/// Request: Dmint
/// Guarantee: struct Dmint {
/// Dependencies: qpow
/// Parent:
template <unsigned* m> struct Dmint {
    Dmint():val(0){}
    Dmint(int raw):val((raw%*m+*m)%*m){}
    Dmint(long long raw):val((raw%*m+*m)%*m){}
    Dmint(unsigned raw):val(raw%*m){}
    Dmint(unsigned long long raw):val(raw%*m){}
    friend Dmint operator+(Dmint a, Dmint b) { return a.val + b.val; }
    friend Dmint operator-(Dmint a, Dmint b) { return m + a.val - b.val; }
    friend Dmint operator*(Dmint a, Dmint b) { return 1ull * a.val * b.val; }
    friend Dmint operator/(Dmint a, Dmint b) { return a * qpow(b, *m-2); }
    friend Dmint& operator+=(Dmint& a, Dmint b) { return a = a + b; }
    friend Dmint& operator-=(Dmint& a, Dmint b) { return a = a - b; }
    friend Dmint& operator*=(Dmint& a, Dmint b) { return a = a * b; }
    friend Dmint& operator/=(Dmint& a, Dmint b) { return a = a / b; }
    friend bool operator==(Dmint a, Dmint b) { return a.val == b.val; }
    friend bool operator!=(Dmint a, Dmint b) { return a.val != b.val; }
    friend ostream& operator<<(ostream& out, Dmint x) { return out << x.val; }
    unsigned val;
};
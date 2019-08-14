/// Name: Modulo (dynamic)
/// Description: arithmetic
/// Detail:
/// Guarantee: struct Dmint {
/// Dependencies: qpow
/// Parent:
template <unsigned* m> struct Dmint {
	Dmint():val(0){}
	Dmint(int raw):val((raw%(int)*m+(int)*m)%(int)*m){}
	Dmint(long long raw):val((raw%(long long)*m+(long long)*m)%(long long)*m){}
	Dmint(unsigned raw):val(raw%*m){}
	Dmint(unsigned long long raw):val(raw%(unsigned long long)*m){}
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

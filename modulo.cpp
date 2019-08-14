/// Name: Modulo
/// Description: arithmetic
/// Detail:
/// Guarantee: struct Mint {
/// Dependencies: qpow
/// Parent:
template <unsigned m> struct Mint {
	Mint():val(0){}
	Mint(int raw):val((raw%(int)m+(int)m)%(int)m){}
	Mint(long long raw):val((raw%(long long)m+(long long)m)%(long long)m){}
	Mint(unsigned raw):val(raw%m){}
	Mint(unsigned long long raw):val(raw%(unsigned long long)m){}
	friend Mint operator+(Mint a, Mint b) { return a.val + b.val; }
	friend Mint operator-(Mint a, Mint b) { return m + a.val - b.val; }
	friend Mint operator*(Mint a, Mint b) { return 1ull * a.val * b.val; }
	friend Mint operator/(Mint a, Mint b) { return a * qpow(b, m-2); }
	friend Mint& operator+=(Mint& a, Mint b) { return a = a + b; }
	friend Mint& operator-=(Mint& a, Mint b) { return a = a - b; }
	friend Mint& operator*=(Mint& a, Mint b) { return a = a * b; }
	friend Mint& operator/=(Mint& a, Mint b) { return a = a / b; }
	friend bool operator==(Mint a, Mint b) { return a.val == b.val; }
	friend bool operator!=(Mint a, Mint b) { return a.val != b.val; }
	friend ostream& operator<<(ostream& out, Mint x) { return out << x.val; }
	unsigned val;
};

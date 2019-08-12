/// Name: Modulo (multiple)
/// Description: arithmetic
/// Detail:
/// Request: MultiMint
/// Guarantee: struct MultiMint {
/// Dependencies: modulo
/// Parent:
template <typename T1, typename T2> struct MultiMint {
	MultiMint():x(),y(){}
	MultiMint(int raw):x(raw),y(raw){}
	MultiMint(long long raw):x(raw),y(raw){}
	MultiMint(unsigned raw):x(raw),y(raw){}
	MultiMint(unsigned long long raw):x(raw),y(raw){}
	MultiMint(T1 x, T2 y):x(x),y(y){}
	friend MultiMint operator+(MultiMint a, MultiMint b) { return MultiMint(a.x + b.x, a.y + b.y); }
	friend MultiMint operator-(MultiMint a, MultiMint b) { return MultiMint(a.x - b.x, a.y - b.y); }
	friend MultiMint operator*(MultiMint a, MultiMint b) { return MultiMint(a.x * b.x, a.y * b.y); }
	friend MultiMint operator/(MultiMint a, MultiMint b) { return MultiMint(a.x / b.x, a.y / b.y); }
	friend MultiMint& operator+=(MultiMint& a, MultiMint b) { return a = a + b; }
	friend MultiMint& operator-=(MultiMint& a, MultiMint b) { return a = a - b; }
	friend MultiMint& operator*=(MultiMint& a, MultiMint b) { return a = a * b; }
	friend MultiMint& operator/=(MultiMint& a, MultiMint b) { return a = a / b; }
	friend bool operator==(MultiMint a, MultiMint b) { return a.x == b.x and a.y == b.y; }
	friend bool operator!=(MultiMint a, MultiMint b) { return not (a == b); }
	T1 x;
	T2 y;
};

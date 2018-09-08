# Convex Hull Optimisation

## Code

```cpp
template <typename T> struct Linehull {
	Linehull():bst(Comp(*this)){}
	Linehull(Linehull&&) = delete;
	void add(T a, T b) {
		auto y = bst.insert(Line{a, b, {}});
		if (bad(y)) {
			bst.erase(y);
			return;
		}
		while (next(y) != bst.end() and bad(next(y)))
			bst.erase(next(y));
		while (y != bst.begin() and bad(prev(y)))
			bst.erase(prev(y));
		if (y != bst.begin())
			prev(y)->succ = y;
		y->succ = next(y);
	}
	bool empty() const { return bst.empty(); }
	T max(T x) const {
		auto l = *bst.lower_bound(Line{ x, queryMark, {} });
		return l.a * x + l.b;
	}
private:
	struct Line;
	struct Comp {
		Comp(const Linehull& lh):lh(lh){}
		bool operator()(const Line& l1, const Line& l2) const {
			assert(l1.b != queryMark);
			if (l2.b != queryMark)
				return l1.a < l2.a;
			auto s = l1.succ;
			if (s == lh.bst.end())
				return false;
			return l1.b - s->b < (s->a - l1.a) * l2.a;
		}
		const Linehull<T>& lh;
	};
	struct Line {
		T a, b;
		Line operator-(Line l2) const { return Line{ a - l2.a, b - l2.b, {} }; }
		mutable typename multiset<Line, Comp>::const_iterator succ;
	};
	T cross(Line a, Line b) { return a.a * b.b - a.b * b.a; }
	bool bad(typename multiset<Line, Comp>::iterator y) {
		auto z = next(y);
		if (y == bst.begin()) {
			if (z == bst.end())
				return false;
			return y->a == z->a and y->b <= z->b;
		}
		auto x = prev(y);
		if (z == bst.end())
			return y->a == x->a and y->b <= x->b;
		return cross(*z - *y, *x - *y) >= 0;
	}
	static const T queryMark = numeric_limits<T>::max();
	multiset<Line, Comp> bst;
};
```

### Minimum adapter

```cpp
template <typename T> struct LowerLinehull {
	void add(T a, T b) { upper.add(-a, -b); }
	bool empty() const { return upper.empty(); }
	T min(T x) const { return -upper.max(x); }
private:
	Linehull<T> upper;
};
```

## Problems

- [Building Bridges (CEOI 2017)](https://ceoi2017.acm.si/files/ceoi2017-statements-day2.zip)
- [Lodziarnia (ONTAK 2018)](https://sio2.mimuw.edu.pl/c/wiekuisty_ontak2018/p/lod/)
- [Nadajniki (ONTAK 2018)](https://sio2.mimuw.edu.pl/c/wiekuisty_ontak2018/p/nad/)
- Heroldzi (CEOI 2009)

## Sources

- https://codeforces.com/blog/entry/51275
- https://pastebin.com/P2pDKePr

# Splay

## Code
```cpp
template <typename Node> struct BaseNode {
	BaseNode():left(nullptr),right(nullptr),parent(nullptr){}
	~BaseNode() { delete left; delete right; }
	Node* cutLeft() { auto r = left; if (left) left = left->parent = nullptr; return r; }
	Node* cutRight() { auto r = right; if (right) right = right->parent = nullptr; return r; }
	void tieLeft(Node* c) { if (c) c->parent = (Node*)this, left = c; }
	void tieRight(Node* c) { if (c) c->parent = (Node*)this, right = c; }
	void replaceChild(Node* c1, Node* c2) {
		(left == c1 ? left : right) = c2;
		if (c2)
			c2->parent = (Node*)this;
		c1->parent = nullptr;
	}
	bool isLeft() const { return parent->left == (Node*)this; }
	bool isRight() const { return parent->right == (Node*)this; }
	Node* left;
	Node* right;
	Node* parent;
};

template <typename Node> struct Splay {

	Splay():root(nullptr){}
	Splay(Node* root):root(root){}
	~Splay() { delete root; }
	Node* intoPointer() { auto v = root; root = nullptr; return v; }

	void insert(Node* position, Node* node) {
		auto t2 = split(position);
		merge(Splay(node));
		merge(move(t2));
	}
	void erase(Node* v1, Node* v2) {
		auto t2 = split(v1);
		auto t3 = t2.split(v2);
		merge(move(t3));
	}
	Splay split(Node* position) {
		if (not position)
			return {};
		splay(position);
		root = position->cutLeft();
		position->update();
		return Splay(position);
	}
	void merge(Splay&& other) {
		findRightmost();
		if (root)
			root->tieRight(other.intoPointer()), root->update();
		else
			root = other.intoPointer();
	}

	Node* findRightmost() { return traverse([&](Node* v){ return v->right ? v->right : v; }); }
	template <typename F> Node* findBinsearch(F f) {
		auto best = (Node*)nullptr;
		traverse([&](Node* v){ return f(v) ? ((best = v), v->left) : v->right; });
		if (best)
			splay(best);
		return best;
	}

	template <typename F> Node* traverse(F f) {
		auto v = root;
		while (v) {
			v->touch();
			auto u = f(v);
			if (not u)
				splay(v);
			else if (v == u)
				break;
			v = u;
		}
		if (v)
			splay(v);
		return v;
	}

	void splay(Node* x) {
		while (x->parent and x->parent->parent)
			if (x->isLeft() == x->parent->isLeft())
				rotate(x->parent), rotate(x);
			else
				rotate(x), rotate(x);
		if (x->parent)
			rotate(x);
		root = x;
		x->update();
	}
	void rotateRight(Node* x) {
		auto y = x->parent;
		auto b = x->cutRight();
		y->cutLeft();
		if (y->parent)
			y->parent->replaceChild(y, x);
		y->tieLeft(b);
		x->tieRight(y);
		y->update();
	}
	void rotateLeft(Node* x) {
		auto y = x->parent;
		auto b = x->cutLeft();
		y->cutRight();
		if (y->parent)
			y->parent->replaceChild(y, x);
		y->tieRight(b);
		x->tieLeft(y);
		y->update();
	}
	void rotate(Node* x) { x->isLeft() ? rotateRight(x) : rotateLeft(x); }

	Node* root;

};
```

## Problems
- [Orderset](https://www.spoj.com/problems/ORDERSET/) SPOJ
- [Bal](https://sio2.mimuw.edu.pl/c/wiekuisty_ontak2017/p/bal/) ONTAK 2017

## Sources

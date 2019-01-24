# Li Chao

## Code

```cpp
template <typename T> struct LiChao {
    struct Linf {
        T a, b;
        T operator()(int x) const { return a*x+b; }
    };
    LiChao(int n):base(1){
        while (base<n) base *= 2;
        nodes.resize(base*2, Linf{0, numeric_limits<T>::max()});
    }
    T min(int x) const {
        auto r = numeric_limits<T>::max();
        for (auto v=base+x; v>0; v/=2)
            r = std::min(r, nodes[v](x));
        return r;
    }
    void insert(T a, T b) { implInsert({a, b}, 0, base, 1); }
    void implInsert(Linf f, int i, int e, int v) {
        auto& g = nodes[v];
        auto m = (i+e)/2;
        if (f(m) < g(m)) swap(f, g);
        if (e - i == 1) return;
        if ((f(i) < g(i)) == (f(m) < g(m))) implInsert(f, m, e, v*2+1);
        else implInsert(f, i, m, v*2);
    }
    int base;
    vector<Linf> nodes;
};
```

### Pointer-based version which does not use O(n) memory

```cpp
template <typename T, typename I> struct LiChaoPtr {
    struct Linf {
        T a, b;
        T operator()(I x) { return a*x+b; }
    };
    struct Node {
        Node* left;
        Node* right;
        Linf val;
    };
    LiChaoPtr(I n):l(0),root(nullptr){
        while (1<<l<n) ++l;
    }
    T min(I x) const {
        auto v = root;
        auto r = numeric_limits<T>::max();
        for (auto e=l-1; e>=0 and v; --e) {
            r = std::min(r, v->val(x));
            v = x & (1 << e) ? v->right : v->left;
        }
        return r;
    }
    void insert(T a, T b) { implInsert({a, b}, 0, 1<<l, root); }
    void implInsert(Linf f, int i, int e, Node*& v) {
        if (not v) { v = new Node{nullptr, nullptr, f}; return; }
        auto& g = v->val;
        auto m = (i+e)/2;
        if (f(m) < g(m)) swap(f, g);
        if (e - i == 1) return;
        if ((f(i) < g(i)) == (f(m) < g(m))) implInsert(f, m, e, v->right);
        else implInsert(f, i, m, v->left);
    }
    I l;
    Node* root;
};
```

## Problems

- [Building Bridge](https://csacademy.com/contest/ceoi-2017-day-2/task/building-bridges/)
- [Dwa tartaki](https://szkopul.edu.pl/problemset/problem/mWwVFGON289ljyx-JpM0JdoG/site/?key=statement)

## Sources

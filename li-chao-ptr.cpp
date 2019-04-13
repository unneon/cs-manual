/// Name: Li Chao (ptr)
/// Description:
/// Detail:
/// Request: LiChaoPtr
/// Guarantee: struct LiChaoPtr {
/// Dependencies:
/// Parent:
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
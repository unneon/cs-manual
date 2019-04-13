/// Name: Segment tree
/// Description:
/// Detail:
/// Request: Segtree
/// Guarantee: struct Segtree {
/// Dependencies:
/// Parent:
template <typename T> struct Segtree {
    Segtree(int n):base(1){
        while (base < n) base *= 2;
        nodes.resize(base*2, T::empty());
    }
    void setLeaf(int i, T x) {
        nodes[base+i] = x;
        for (auto v=(base+i)/2; v>0; v/=2)
            nodes[v] = T::merge(nodes[v*2], nodes[v*2+1]);
    }
    T readRange(int left, int right) const { return implRR(left, right, 0, base, 1); }
    T implRR(int left, int right, int i, int e, int v) const {
        if (left >= e or right <= i) return T::empty();
        if (left <= i and right >= e) return nodes[v];
        return T::merge(implRR(left, right, i, (i+e)/2, v*2), implRR(left, right, (i+e)/2, e, v*2+1));
    }
    int base;
    vector<T> nodes;
};
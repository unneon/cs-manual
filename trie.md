# Trie

## Code

```cpp
template <typename Node, typename A, A _a0, int alpha> struct BaseNode {
    static const A a0 = _a0;
    explicit BaseNode(Node* parent):parent(parent){}
    Node* extend(int ic) { return not kids[ic] and parent ? suflink->extend(ic) : kids[ic] ? kids[ic] : (Node*)this; }
    void buildSuflink() { suflink = parent and parent->parent ? parent->suflink->extend(lastIC()) : parent ? parent : (Node*)this; }
    int lastIC() { return (int)(find(parent->kids.begin(), parent->kids.end(), (Node*)this) - parent->kids.begin()); }
    Node* parent, *suflink = nullptr;
    array<Node*, alpha> kids{};
};
template <typename Node> struct Trie {
    Trie():root(new Node(nullptr)){}
    template <typename S> Node* addPattern(S&& pattern) {
        auto v = root;
        for (auto c : pattern)
            v = v->kids[c-Node::a0] = v->kids[c-Node::a0] ? v->kids[c-Node::a0] : new Node(v);
        return v;
    }
    vector<Node*> BFS() {
        auto que = vector<Node*>({root});
        for (auto i=0; i<(int)que.size(); ++i)
            for (auto kid : que[i]->kids)
                if (kid)
                    que.push_back(kid);
        return que;
    }
    void buildSuflinks() { for (auto v : BFS()) v->buildSuflink(); }
    Node* root;
};
```

### Example usage

```cpp
struct Node : BaseNode<Node, char, 'a', 26> {
    Node(Node* parent):BaseNode(parent),depth(parent ? parent->depth + 1 : 0){}
    Node* cachedExtend(int ic) {
        if (not ecache[ic])
            ecache[ic] = kids[ic] ? kids[ic] : parent ? suflink->cachedExtend(ic) : this;
        return ecache[ic];
    }
    int depth;
    bool mark = false;
    array<Node*, 26> ecache{};
};
```

## Problems

- [Censoring (USACO 2015 February)](http://www.usaco.org/index.php?page=viewproblem2&cpid=533)
- [Viruses (VIIth POI)](https://szkopul.edu.pl/problemset/problem/nnyNdoueeXmWIzMJhLtp3IvG/site/?key=statement)
- [Censored! (ACM ICPC 2001. Northeastern European Region, Northern Subregion)](http://acm.timus.ru/problem.aspx?space=1&num=1158)
- [e-Government (VK Cup 2012 Round 2)](https://codeforces.com/contest/163/problem/E)

## Sources

- https://codeforces.com/blog/entry/14854

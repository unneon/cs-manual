# Trie

## Code

```cpp
template <typename Node, typename A, char _a0, int alpha> struct BaseNode {
    static const char a0 = _a0;
    explicit BaseNode(Node* parent):parent(parent),suflink(nullptr){ fill(kids.begin(), kids.end(), nullptr); }
    Node* parent, *suflink;
    array<Node*, alpha> kids;
};
template <typename Node> struct Trie {
    Trie():root(new Node(nullptr)){}
    template <typename S> Node* addPattern(S&& pattern) {
        auto v = root;
        for (auto c : pattern) {
            if (not v->kids[c - Node::a0])
                v->kids[c - Node::a0] = new Node(v);
            v = v->kids[c - Node::a0];
        }
        return v;
    }
    template <typename F> void BFS(F f) {
        auto que = vector<Node*>({root});
        for (auto i=0; i<(int)que.size(); ++i) {
            f(que[i]);
            for (auto kid : que[i]->kids)
                if (kid)
                    que.push_back(kid);
        }
    }
    void buildSuflinks() {
        BFS([&](Node* v){
            v->suflink = v == root or v->parent == root ? root : extend(v->parent->suflink, (int)(find(v->parent->kids.begin(), v->parent->kids.end(), v) - v->parent->kids.begin()));
        });
    }
    Node* extend(Node* v, int ic) {
        while (not v->kids[ic] and v->parent)
            v = v->suflink;
        return v->kids[ic] ? v->kids[ic] : v;
    }
    Node* root;
};
```

### Example usage

```cpp
struct Node : BaseNode<Node, char, 'a', 26> {
    Node(Node* parent):
        BaseNode(parent),
        depth(parent ? parent->depth + 1 : 0),
        mark(false)
    {
        fill(extendCache.begin(),extendCache.end(),nullptr);
    }
    Node* fastExtend(int ic) {
        if (not extendCache[ic]) {
            if (kids[ic])
                extendCache[ic] = kids[ic];
            else if (parent)
                extendCache[ic] = suflink->fastExtend(ic);
            else
                extendCache[ic] = this;
        }
        return extendCache[ic];
    }
    int depth;
    bool mark;
    array<Node*, 26> extendCache;
};
```

## Problems

- [Censoring (USACO 2015 February)](http://www.usaco.org/index.php?page=viewproblem2&cpid=533)

## Sources

# Suffix tree

## Code

```cpp
struct SuffixTree {
    struct Node {
        int left, right;
        Node* parent;
        Node* suflink;
        map<char, Node*> kids;
    };
    SuffixTree(const string& original){
        text = original + '$';
        nodes.resize(2*text.size()+2);
        dev=&nodes[2];
        peak=&nodes[0];
        epos=0;
        nodes[0] = Node{-1, 0, &nodes[0], &nodes[1], {}};
        nodes[1] = Node{-1, 0, &nodes[0], &nodes[0], {}};
        for (auto c : text) nodes[1].kids[c] = &nodes[0];
        fill(nodes.begin()+2, nodes.end(), Node{0, (int)text.size(), &nodes[0], &nodes[0], {}});
        for (auto pos=0; pos<(int)text.size(); ++pos)
            ukkadd(text[pos], pos);
    }
    Node* root() { return &nodes[0]; }
    void ukkadd(char c, int pos) {
        if (peak->right<=epos) {
            if (!peak->kids.count(c)) {
                peak->kids[c]=dev;  dev->left=pos;
                (dev++)->parent=peak;  peak=peak->suflink;  epos=peak->right;  return ukkadd(c,pos);
            }
            peak=peak->kids[c]; epos=peak->left;
        }
        if (epos == -1 || c == text[epos])
            epos++;
        else {
            (dev+1)->left=pos;  (dev+1)->parent=dev;
            dev->left=peak->left;  dev->right=epos;  dev->parent=peak->parent;  dev->kids[c]=dev+1;  dev->kids[text[epos]]=peak;
            peak->left=epos;  peak->parent=dev;  dev->parent->kids[text[dev->left]]=dev;  dev+=2;
            peak=(dev-2)->parent->suflink;  epos=(dev-2)->left;
            while (epos<(dev-2)->right) {
                peak=peak->kids[text[epos]];
                epos+=peak->right-peak->left;
            }
            (dev-2)->suflink = epos == (dev-2)->right ? peak : dev;
            epos=peak->right-(epos-(dev-2)->right);return ukkadd(c,pos);
        }
    }
    string text;
    vector<Node> nodes;
    Node* peak, *dev;
    int epos;
};
```

## Problems

- [Suffix Array](https://www.spoj.com/problems/SARRAY/)

## Sources

- https://cp-algorithms.com/string/suffix-tree-ukkonen.html

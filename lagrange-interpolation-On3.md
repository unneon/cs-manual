# Lagrange interpolation O(n³)

## Code

```cpp
auto total = vector<T>(n);
for (auto i=0; i<n; ++i) {
    auto sub = vector<T>(n);
    sub[0] = 1;
    auto norm = T(1);
    for (auto j=0; j<n; ++j) {
        if (i == j) continue;
        norm *= pts[i].x - pts[j].x;
        for (auto k=n-1; k>=0; --k)
            sub[k] = sub[k] * (-pts[j].x) + (k > 0 ? sub[k-1] : 0);
    }
    for (auto k=0; k<n; ++k)
        total[k] += sub[k] * pts[i].y / norm;
}
```

## Problems

## Sources

# Graham scan

## Code

```cpp
template <typename T> vector<V2<T>> grahamScan(vector<V2<T>> pts) {
	auto hull = pts.begin();
	auto root = *min_element(pts.begin(), pts.end(), [&](V2<T> a, V2<T> b){ return tie(a.x, a.y) < tie(b.x, b.y); });
	sort(pts.begin(), pts.end(), [&](V2<T> a, V2<T> b){ return (a == root and b != root) or make_tuple(cross(a - root, b - root), a.x, a.y) < make_tuple((T)0, b.x, b.y); });
	for (auto pt : pts) {
		while (hull-pts.begin() >= 2 and cross(hull[-1] - hull[-2], pt - hull[-1]) >= 0)
			--hull;
		*(hull++) = pt;
	}
	pts.erase(hull, pts.end());
	return pts;
}
```

## Problems

## Sources

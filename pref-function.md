# Pref function

## Code

```cpp
auto pref = vector<int>(n, 0);
auto q = 1;
for (auto i=1; i<n; ++i) {
	pref[i] = max(min(pref[i-q], q+pref[q]-i), 0);
	for (; text[i+pref[i]] == text[pref[i]]; ++pref[i]);
	q = i+pref[i] > q+pref[q] ? i : q;
}
```

## Problems

## Sources

- ONTAK 2018 lecture

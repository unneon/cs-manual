# Randomness utilities

## Code

```cpp
minstd_rand rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T> T randint(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
template <typename T> const T& choice(const vector<T>& xs) { return xs[randint(0, (int)xs.size()-1)]; }
```

## Problems

## Sources

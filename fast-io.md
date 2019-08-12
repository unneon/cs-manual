# Fast IO

## Code

```cpp
auto r = 0;
auto c = getchar_unlocked();
while (c < '0') c = getchar_unlocked();
while (c >= '0') {
	r = r * 10 + c - '0';
	c = getchar_unlocked();
}
```

## Problems

## Sources

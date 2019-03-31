# Geometry 2D

## Code

```cpp
template <typename T> struct V2 {
    V2():x(0),y(0){}
    V2(T x, T y):x(x),y(y){}
    friend V2 operator+(V2 a, V2 b) { return {a.x + b.x, a.y + b.y}; }
    friend V2 operator-(V2 a, V2 b) { return {a.x - b.x, a.y - b.y}; }
    friend bool operator==(V2 a, V2 b) { return a.x == b.x and a.y == b.y; }
    friend bool operator!=(V2 a, V2 b) { return a.x != b.x or a.y != b.y; }
    friend istream& operator>>(istream& in, V2& pt) { return in >> pt.x >> pt.y; }
    T x, y;
};
template <typename T> T cross(V2<T> a, V2<T> b) { return a.x * b.y - a.y * b.x; }
template <typename T> T dot(V2<T> a, V2<T> b) { return a.x * b.x + a.y * b.y; }
```

## Problems

## Sources

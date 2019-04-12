# Geometry 2D

## Code

```cpp
template <typename T> struct V2 {
    V2():x(0),y(0){}
    V2(T x, T y):x(x),y(y){}
    T squaredLength() const { return x*x + y*y; }
    T length() const { return sqrt(squaredLength()); }
    friend V2 operator+(V2 a, V2 b) { return {a.x + b.x, a.y + b.y}; }
    friend V2 operator-(V2 a, V2 b) { return a + -b; }
    friend V2 operator*(V2 a, T b) { return {a.x * b, a.y * b}; }
    friend V2 operator*(T a, V2 b) { return b * a; }
    friend V2 operator/(V2 a, T b) { return {a.x / b, a.y / b}; }
    friend V2& operator+=(V2& a, V2 b) { return a = a + b; }
    friend V2& operator-=(V2& a, V2 b) { return a = a - b; }
    friend V2& operator*=(V2& a, T b) { return a = a * b; }
    friend V2& operator/=(V2& a, T b) { return a = a / b; }
    friend V2 operator-(V2 a) { return {-a.x, -a.y}; }
    friend bool operator==(V2 a, V2 b) { return a.x == b.x and a.y == b.y; }
    friend bool operator!=(V2 a, V2 b) { return a.x != b.x or a.y != b.y; }
    friend istream& operator>>(istream& in, V2& pt) { return in >> pt.x >> pt.y; }
    T x, y;
};
template <typename T> T cross(V2<T> a, V2<T> b) { return a.x * b.y - a.y * b.x; }
template <typename T> T dot(V2<T> a, V2<T> b) { return a.x * b.x + a.y * b.y; }
template <typename T> T squaredDist(V2<T> a, V2<T> b){ return (a - b).squaredLength(); }
template <typename T> T dist(V2<T> a, V2<T> b) { return (a - b).length(); }

namespace area {
    template <typename T> T square(T a) { return a * a; }
    template <typename T> T rectangle(T a, T b) { return a * b; }
    template <typename T> T circle(T r) { return M_PI * r * r; }
}
```

## Problems

## Sources

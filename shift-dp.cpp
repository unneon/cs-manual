/// Name: Shifting DP
/// Description: DP memory optimization
/// Detail:
/// Request: ShiftDP
/// Guarantee: struct ShiftDP {
/// Dependencies:
/// Parent:
template <typename T, int k> struct ShiftDP {
    ShiftDP(int n, const T& def):n(n),j(0),def(def){data.fill(def);}
    T& operator[](int i) { return data[i % k]; }
    void shift() { data[j++ % k] = def; }
    int n, j;
    T def;
    array<T, k> data;
};
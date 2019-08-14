/// Name: Loading
/// Description:
/// Detail:
/// Guarantee: vector<T> loadMany(
/// Dependencies:
/// Parent:
template <typename T> T load() { T r; cin >> r; return r; }
template <typename T> vector<T> loadMany(int n) { vector<T> rs(n); generate(rs.begin(), rs.end(), &load<T>); return rs; }

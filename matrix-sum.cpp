/// Name: Matrix: Sum
/// Description:
/// Detail:
/// Guarantee: T sum() const { return accumulate(data.begin(), data.end(), (T)0); }
/// Dependencies: matrix
/// Parent: matrix
T sum() const { return accumulate(data.begin(), data.end(), (T)0); }

/// Name: Exponentiation
/// Description:
/// Detail:
/// Request: qpow
/// Guarantee: T qpow(
/// Dependencies:
/// Parent:
template <typename T, typename E> T qpow(T x, E e) {
    if (e == 0) return 1;
    if (e % 2 == 0) return qpow(x*x, e/2);
    return x * qpow(x*x, e/2);
}
/// Name: Matrix: Exponentiation
/// Description:
/// Detail:
/// Guarantee: Matrix exp(
/// Dependencies: matrix, matrix-mul, matrix-identity
/// Parent: matrix
template <typename E> Matrix exp(E e) const {
	if (e == 0) return identity(w);
	if (e % 2 == 0) return (*this**this).exp(e/2);
	return *this*(*this**this).exp(e/2);
}

/// Name: Matrix: Identity
/// Description:
/// Detail:
/// Guarantee: Matrix identity(
/// Dependencies: matrix
/// Parent: matrix
static Matrix identity(int n) {
	auto mat = Matrix<T>(n, n, 0);
	for (auto i=0; i<n; ++i)
		mat[i][i] = 1;
	return mat;
}

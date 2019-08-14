/// Name: Matrix: Multiplication
/// Description:
/// Detail:
/// Guarantee: friend Matrix operator*(
/// Dependencies: matrix
/// Parent: matrix
friend Matrix operator*(const Matrix& a, const Matrix& b) {
	auto c = Matrix(b.w, a.h, 0);
	for (auto x=0; x<c.w; ++x)
		for (auto y=0; y<c.h; ++y)
			for (auto i=0; i<a.w; ++i)
				c[x][y] += a[i][y] * b[x][i];
	return c;
}

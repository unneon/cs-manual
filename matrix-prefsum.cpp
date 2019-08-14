/// Name: Matrix: Prefix sums
/// Description:
/// Detail:
/// Guarantee: Matrix<U>::PrefSums prefSums()
/// Dependencies: matrix
/// Parent: matrix
struct PrefSums {
	template <typename U> PrefSums(const Matrix<U>& mat):sums(mat.w+1,mat.h+1,0){
		for (auto y=0; y<mat.h; ++y)
			for (auto x=0; x<mat.w; ++x)
				sums[x+1][y+1] = mat[x][y] + sums[x+1][y] + sums[x][y+1] - sums[x][y];
	}
	T rect(int x1, int y1, int x2, int y2) const {
		return sums[x2][y2] - sums[x2][y1] - sums[x1][y2] + sums[x1][y1];
	}
	Matrix sums;
};
template <typename U> typename Matrix<U>::PrefSums prefSums() const { return typename Matrix<U>::PrefSums(*this); }

/// Name: Matrix
/// Description:
/// Detail:
/// Guarantee: struct Matrix {
/// Dependencies:
/// Parent:
template <typename T> struct Matrix {
	Matrix(int w, int h, const T& x):w(w),h(h),data(w*h,x){}
	struct Col { int x; Matrix& m; typename vector<T>::reference operator[](int y) { return m.data[y*m.w+x]; } };
	struct CCol { int x; const Matrix& m; typename vector<T>::const_reference operator[](int y) const { return m.data[y*m.w+x]; } };
	Col operator[](int x) { return {x,*this}; }
	CCol operator[](int x) const { return {x,*this}; }
	int w, h;
	vector<T> data;
};
